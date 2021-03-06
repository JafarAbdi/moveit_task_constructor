#include "models.h"
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <urdf_parser/urdf_parser.h>

using namespace moveit::core;
namespace {

const std::string R_MODEL0 = "<?xml version=\"1.0\" ?>"
                             "<robot name=\"one_robot\">"
                             "<link name=\"base_link\">"
                             "  <inertial>"
                             "    <mass value=\"2.81\"/>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0.0 0.0 .0\"/>"
                             "    <inertia ixx=\"0.1\" ixy=\"-0.2\" ixz=\"0.5\" iyy=\"-.09\" iyz=\"1\" izz=\"0.101\"/>"
                             "  </inertial>"
                             "  <collision name=\"my_collision\">"
                             "    <origin rpy=\"0 0 0\" xyz=\"0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </collision>"
                             "  <visual>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0.0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </visual>"
                             "</link>"
                             "<joint name=\"joint_a\" type=\"continuous\">"
                             "   <axis xyz=\"0 0 1\"/>"
                             "   <parent link=\"base_link\"/>"
                             "   <child link=\"link_a\"/>"
                             "   <origin rpy=\" 0.0 0 0 \" xyz=\"0.0 0 0 \"/>"
                             "</joint>"
                             "<link name=\"link_a\">"
                             "  <inertial>"
                             "    <mass value=\"1.0\"/>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0.0 0.0 .0\"/>"
                             "    <inertia ixx=\"0.1\" ixy=\"-0.2\" ixz=\"0.5\" iyy=\"-.09\" iyz=\"1\" izz=\"0.101\"/>"
                             "  </inertial>"
                             "  <collision>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </collision>"
                             "  <visual>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0.0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </visual>"
                             "</link>"
                             "<joint name=\"joint_b\" type=\"fixed\">"
                             "  <parent link=\"link_a\"/>"
                             "  <child link=\"link_b\"/>"
                             "  <origin rpy=\" 0.0 -0.42 0 \" xyz=\"0.0 0.5 0 \"/>"
                             "</joint>"
                             "<link name=\"link_b\">"
                             "  <inertial>"
                             "    <mass value=\"1.0\"/>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0.0 0.0 .0\"/>"
                             "    <inertia ixx=\"0.1\" ixy=\"-0.2\" ixz=\"0.5\" iyy=\"-.09\" iyz=\"1\" izz=\"0.101\"/>"
                             "  </inertial>"
                             "  <collision>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </collision>"
                             "  <visual>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0.0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </visual>"
                             "</link>"
                             "  <joint name=\"joint_c\" type=\"prismatic\">"
                             "    <axis xyz=\"1 0 0\"/>"
                             "    <limit effort=\"100.0\" lower=\"0.0\" upper=\"0.09\" velocity=\"0.2\"/>"
                             "    <safety_controller k_position=\"20.0\" k_velocity=\"500.0\" soft_lower_limit=\"0.0\" "
                             "soft_upper_limit=\"0.089\"/>"
                             "    <parent link=\"link_b\"/>"
                             "    <child link=\"link_c\"/>"
                             "    <origin rpy=\" 0.0 0.42 0.0 \" xyz=\"0.0 -0.1 0 \"/>"
                             "  </joint>"
                             "<link name=\"link_c\">"
                             "  <inertial>"
                             "    <mass value=\"1.0\"/>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0.0 0 .0\"/>"
                             "    <inertia ixx=\"0.1\" ixy=\"-0.2\" ixz=\"0.5\" iyy=\"-.09\" iyz=\"1\" izz=\"0.101\"/>"
                             "  </inertial>"
                             "  <collision>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </collision>"
                             "  <visual>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0.0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </visual>"
                             "</link>"
                             "  <joint name=\"mim_f\" type=\"prismatic\">"
                             "    <axis xyz=\"1 0 0\"/>"
                             "    <limit effort=\"100.0\" lower=\"0.0\" upper=\"0.19\" velocity=\"0.2\"/>"
                             "    <parent link=\"link_c\"/>"
                             "    <child link=\"link_d\"/>"
                             "    <origin rpy=\" 0.0 0.1 0.0 \" xyz=\"0.1 0.1 0 \"/>"
                             "    <mimic joint=\"joint_f\" multiplier=\"1.5\" offset=\"0.1\"/>"
                             "  </joint>"
                             "  <joint name=\"joint_f\" type=\"prismatic\">"
                             "    <axis xyz=\"1 0 0\"/>"
                             "    <limit effort=\"100.0\" lower=\"0.0\" upper=\"0.19\" velocity=\"0.2\"/>"
                             "    <parent link=\"link_d\"/>"
                             "    <child link=\"link_e\"/>"
                             "    <origin rpy=\" 0.0 0.1 0.0 \" xyz=\"0.1 0.1 0 \"/>"
                             "  </joint>"
                             "<link name=\"link_d\">"
                             "  <collision>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </collision>"
                             "  <visual>"
                             "    <origin rpy=\"0 1 0\" xyz=\"0 0.1 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </visual>"
                             "</link>"
                             "<link name=\"link_e\">"
                             "  <collision>"
                             "    <origin rpy=\"0 0 0\" xyz=\"0 0 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </collision>"
                             "  <visual>"
                             "    <origin rpy=\"0 1 0\" xyz=\"0 0.1 0\"/>"
                             "    <geometry>"
                             "      <box size=\"1 2 1\" />"
                             "    </geometry>"
                             "  </visual>"
                             "</link>"
                             "</robot>";

const std::string S_MODEL0 =
    "<?xml version=\"1.0\" ?>"
    "<robot name=\"one_robot\">"
    "<virtual_joint name=\"base_joint\" child_link=\"base_link\" parent_frame=\"odom_combined\" type=\"planar\"/>"
    "<group name=\"base_from_joints\">"
    "<joint name=\"base_joint\"/>"
    "<joint name=\"joint_a\"/>"
    "<joint name=\"joint_c\"/>"
    "</group>"
    "<group name=\"mim_joints\">"
    "<joint name=\"joint_f\"/>"
    "<joint name=\"mim_f\"/>"
    "</group>"
    "<group name=\"base_with_subgroups\">"
    "<group name=\"base_from_base_to_tip\"/>"
    "<joint name=\"joint_c\"/>"
    "</group>"
    "<group name=\"base_from_base_to_tip\">"
    "<chain base_link=\"base_link\" tip_link=\"link_b\"/>"
    "<joint name=\"base_joint\"/>"
    "</group>"
    "<group name=\"base_with_bad_subgroups\">"
    "<group name=\"error\"/>"
    "</group>"
    "<end_effector name=\"eef\" parent_link=\"link_b\" group=\"mim_joints\" parent_group=\"base_from_base_to_tip\"/>"
    "</robot>";
}  // namespace

RobotModelPtr getModel() {
	urdf::ModelInterfaceSharedPtr urdf_model = urdf::parseURDF(R_MODEL0);
	srdf::ModelSharedPtr srdf_model(new srdf::Model());
	srdf_model->initString(*urdf_model, S_MODEL0);
	return RobotModelPtr(new RobotModel(urdf_model, srdf_model));
}

moveit::core::RobotModelPtr loadModel() {
	robot_model_loader::RobotModelLoader loader;
	return loader.getModel();
}
