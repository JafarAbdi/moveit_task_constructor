/*********************************************************************
 * BSD 3-Clause License
 *
 * Copyright (c) 2021 PickNik Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Boston Cleek
   Desc:   Grasp generator stage
*/

#include <moveit/task_constructor/stages/grasp_provider.h>
#include <grasping_msgs/GraspPlanningAction.h>

namespace moveit {
namespace task_constructor {
namespace stages {

constexpr char LOGNAME[] = "grasp_provider";

GraspProvider::GraspProvider(const std::string& action_name, const std::string& stage_name, double server_timeout)
  : GeneratePose(stage_name), ActionBase(action_name, false, server_timeout), found_all_candidates_(false) {
	setTimeout(std::numeric_limits<double>::max());
	auto& p = properties();
	p.declare<std::string>("eef", "name of end-effector");
	p.declare<std::string>("object");
	p.declare<boost::any>("pregrasp", "pregrasp posture");
	p.declare<boost::any>("grasp", "grasp posture");
}

void GraspProvider::composeGoal() {
	const auto& props = properties();
	grasping_msgs::GraspPlanningGoal goal;
	goal.object.name = props.get<std::string>("object");
	clientPtr_->sendGoal(goal,
	                     std::bind(&GraspProvider::doneCallback, this, std::placeholders::_1, std::placeholders::_2),
	                     std::bind(&GraspProvider::activeCallback, this),
	                     std::bind(&GraspProvider::feedbackCallback, this, std::placeholders::_1));

	ROS_DEBUG_NAMED(LOGNAME, "Goal sent to server to grasp object: %s", goal.object.name.c_str());
}

void GraspProvider::activeCallback() {
	ROS_DEBUG_STREAM_NAMED(LOGNAME, "Generate grasp goal now active");
	found_all_candidates_ = false;
}

void GraspProvider::feedbackCallback(const grasping_msgs::GraspPlanningFeedbackConstPtr& feedback) {
	// Protect grasp candidate incase feedback is sent asynchronously
	const std::lock_guard<std::mutex> lock(grasp_mutex_);
	grasp_candidates_.push(feedback->grasps);
}

void GraspProvider::doneCallback(const actionlib::SimpleClientGoalState& state,
                                 const grasping_msgs::GraspPlanningResultConstPtr& result) {
	if (state == actionlib::SimpleClientGoalState::SUCCEEDED) {
		ROS_DEBUG_STREAM_NAMED(LOGNAME, "Found grasp candidates");
	} else {
		ROS_ERROR_NAMED(LOGNAME, "No grasp candidates found (state): %s", clientPtr_->getState().toString().c_str());
	}
	found_all_candidates_ = true;
}

void GraspProvider::init(const core::RobotModelConstPtr& robot_model) {
	InitStageException errors;
	try {
		GeneratePose::init(robot_model);
	} catch (InitStageException& e) {
		errors.append(e);
	}

	const auto& props = properties();

	// check availability of object
	props.get<std::string>("object");
	// check availability of eef
	const std::string& eef = props.get<std::string>("eef");
	if (!robot_model->hasEndEffector(eef)) {
		errors.push_back(*this, "unknown end effector: " + eef);
	} else {
		// check availability of eef pose
		const moveit::core::JointModelGroup* jmg = robot_model->getEndEffector(eef);
		const std::string& name = props.get<std::string>("pregrasp");
		std::map<std::string, double> m;
		if (!jmg->getVariableDefaultPositions(name, m)) {
			errors.push_back(*this, "unknown end effector pose: " + name);
		}
	}

	if (errors) {
		throw errors;
	}
}

void GraspProvider::compute() {
	if (upstream_solutions_.empty()) {
		return;
	}
	planning_scene::PlanningScenePtr scene = upstream_solutions_.pop()->end()->scene()->diff();

	// set end effector pose
	const auto& props = properties();
	const std::string& eef = props.get<std::string>("eef");
	const moveit::core::JointModelGroup* jmg = scene->getRobotModel()->getEndEffector(eef);

	robot_state::RobotState& robot_state = scene->getCurrentStateNonConst();
	robot_state.setToDefaultValues(jmg, props.get<std::string>("pregrasp"));

	// compose/send goal
	composeGoal();
	ros::AsyncSpinner spinner(2);
	spinner.start();

	const auto grasp_candidates_empty = [this] {
		std::lock_guard<std::mutex> lock(grasp_mutex_);
		return grasp_candidates_.empty();
	};

	// monitor feedback/results
	// blocking function until timeout reached or results received
	const auto available_time = timeout();
	const auto start_time = std::chrono::steady_clock::now();
	while (nh_.ok() && !(found_all_candidates_ && grasp_candidates_empty())) {
		if (std::chrono::duration<double>(std::chrono::steady_clock::now() - start_time).count() > available_time) {
			clientPtr_->cancelGoal();
			ROS_ERROR_NAMED(LOGNAME, "Grasp pose generator time out reached");
			return;
		}
		// Protect grasp candidate incase feedback is being recieved asynchronously
		const auto grasp_candidates = [this] {
			const std::lock_guard<std::mutex> lock(grasp_mutex_);
			if (grasp_candidates_.empty())
				return std::vector<moveit_msgs::Grasp>();
			auto grasp_candidates = std::move(grasp_candidates_.front());
			grasp_candidates_.pop();
			return grasp_candidates;
		}();
		for (unsigned int i = 0; i < grasp_candidates.size(); i++) {
			InterfaceState state(scene);
			state.properties().set("target_pose", grasp_candidates.at(i).grasp_pose);
			props.exposeTo(state.properties(), { "pregrasp", "grasp" });

			SubTrajectory trajectory;
			trajectory.setCost(grasp_candidates.at(i).grasp_quality);
			trajectory.setComment(std::to_string(i));

			// add frame at target pose
			rviz_marker_tools::appendFrame(trajectory.markers(), grasp_candidates.at(i).grasp_pose, 0.1, "grasp frame");

			spawn(std::move(state), std::move(trajectory));
		}
	}
}

void GraspProvider::onNewSolution(const SolutionBase& s) {
	planning_scene::PlanningSceneConstPtr scene = s.end()->scene();

	const auto& props = properties();
	const std::string& object = props.get<std::string>("object");
	if (!scene->knowsFrameTransform(object)) {
		const std::string msg = "object '" + object + "' not in scene";
		if (storeFailures()) {
			InterfaceState state(scene);
			SubTrajectory solution;
			solution.markAsFailure();
			solution.setComment(msg);
			spawn(std::move(state), std::move(solution));
		} else {
			ROS_WARN_STREAM_NAMED(LOGNAME, msg);
		}
		return;
	}

	upstream_solutions_.push(&s);
}
}  // namespace stages
}  // namespace task_constructor
}  // namespace moveit
