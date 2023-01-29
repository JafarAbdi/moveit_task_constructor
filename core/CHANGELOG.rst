^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_task_constructor_core
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.1.0 (2023-01-29)
------------------
* Merge https://github.com/ros-planning/moveit/commit/93b46ef21429bc91c8afa1b79479d302764b1e9d
* GeneratePose: forward registered properties from received solution
* Silent external clang-tidy warning
* Disable python wrapper for now
  The ROS1 wrapper relied on python <-> c++ type casting via message serialization.
  A corresponding mechanism doesn't yet exist in ROS2:
  - https://answers.ros.org/question/356542/ros2-message-serialization-adapting-types/
  - https://github.com/ros2/rclpy/issues/291#issuecomment-476314923
* Rely on CXXFLAGS definition from moveit_common package
* Merge branch 'master' into ros2
* Fix more -Wold-style-cast warnings
* Replace namespace robot_model -> moveit::core
* Fix clang-tidy warnings
  - Replace old-style casts
  - Fix missing initialization
* Fix call of PropagatingEitherWay::computeGeneric()
  computeGeneric is templated and private so it will be undefined in the
  shared object and when using the computeForward/Backward functions.
* Expose ContainerBase::childByIndex via operator[](int) (`#413 <https://github.com/JafarAbdi/moveit_task_constructor/issues/413>`_)
* Merge PRs `#412 <https://github.com/JafarAbdi/moveit_task_constructor/issues/412>`_ (fix-ci) and `#409 <https://github.com/JafarAbdi/moveit_task_constructor/issues/409>`_ (more cost-terms)
* Fix clang-tidy issues
* Update/Stick pybind11 to version 2.9.1-smart_holder
  ... to maintain compatibility with Python 3.6 and 2.7
* Update/Stick pybind11 to version 2.9.1-smart_holder
  ... to maintain compatibility with Python 3.6 and 2.7
* Build python bindings with size optimization
* Expose CostTerms to python
* new TrajectoryCostTerm: DistanceToReference
* PathLength: allow weighting of different joints
* Fetch pybind11 submodule if not yet present
* Fix SimpleGrasp/SimpleUnGrasp wrapper
  - Wrap common base class SimpleGraspBase to reduce redundancy
  - Use correct defaults for stage name
* Fix base class for container stages Pick, Place, SimpleGrasp, SimpleUnGrasp
* Drop breathe (not working) and directly link doxygen docs
* GHA: Build and deploy documentation
* Merge PR `#99 <https://github.com/JafarAbdi/moveit_task_constructor/issues/99>`_: Python API
  ... based on pybind11
* [Container|Task]::add(...) for sequence (python)
* clang-tidy: fix variable/method naming
* Merge branch master into ros2
* Fix clang-tidy warnings
* Fix cmake indentation
* CI: stricter warnings
* Merge PR `#380 <https://github.com/JafarAbdi/moveit_task_constructor/issues/380>`_: Fix Cartesian interpolation
  Correctly consider an offset transform from link to reference frame,
  such that rotations w.r.t. the reference frame don't move its origin.
* CI: stricter warnings
* Rename variables in visualizePlan()
  - link_pose -> start_pose
  - pos_link -> pos_start
* Fix getRobotTipForFrame()
  When passing the root frame, getRigidlyConnectedParentLinkModel() returns
  a nullptr for robot_link, causing a segfault.
  Actually, we don't need to use that method at all. We just need to find
  the robot_link of an associated body.
* Fix handling of ik_frame in Cartesian path planning
  The ik_frame should move in a straight-line Cartesian path.
  However, so far the link frame was following a Cartesian path.
* MoveRelative: Correctly compute motion transform
  The twist motion performs an angular rotation about the given axis _and\_
  the origin of ik_frame as well as a linear translation.
  Both transforms are expressed w.r.t. the model frame and thus require
  left-multiplication to ik_frame's current pose.
* Simplify MoveRelative
* Improve unittest for move_relative
* Merge CI fixes/improvements
* Hopefully fix spurious test failure
* Avoid unused-parameter warnings
* Suppress unused-function warning
* Use catkin_INCLUDE_DIRS as system includes
  ... to suppress warnings outside the code base
* Remove MoveIt compatibility code
* Do not dictate C++ standard
  C++14 is default in clang/gcc anyway and latest log4cxx requires C++17.
  Qt on Ubuntu 18.04 sets C++11. Hence we use MoveIt's cmake macro to ensure C++14 at least.
* Report 1st collision pair for invalid IK solutions (`#376 <https://github.com/JafarAbdi/moveit_task_constructor/issues/376>`_)
* Add MoveIt IK cost function to Cartesian path solver (`#375 <https://github.com/JafarAbdi/moveit_task_constructor/issues/375>`_)
* Merge ROS1 fixes
* Fix Task's move constructor (`#371 <https://github.com/JafarAbdi/moveit_task_constructor/issues/371>`_)
  * Add unit test
  * Fix TaskPrivate's move assignment operator
  * Slightly simplify code
  Co-authored-by: Robert Haschke <rhaschke@techfak.uni-bielefeld.de>
* Add KinematicsQueryOptions property in CartesianPath solver (`#370 <https://github.com/JafarAbdi/moveit_task_constructor/issues/370>`_)
* Remove macros to check supported features
* Merge https://github.com/ros-planning/moveit/commit/d2918f130d5bbcd7a788d1dc86c32a6c487ca70f
* Use moveit_configs_utils for launch files (`#365 <https://github.com/JafarAbdi/moveit_task_constructor/issues/365>`_)
* Add launch_testing_ament_cmake as a test depend (`#364 <https://github.com/JafarAbdi/moveit_task_constructor/issues/364>`_)
* Alphabetize package.xml's and CMakeLists
* Pruning: Relax too strong assertion: PRUNED => !ARMED (`#340 <https://github.com/JafarAbdi/moveit_task_constructor/issues/340>`_)
* Make TimeParamerization configurable (`#339 <https://github.com/JafarAbdi/moveit_task_constructor/issues/339>`_)
* Fix rolling compatibility with jammy
  Fix compile warning
  Update clang-format version to 12
* Use verbose delimiters for source code instead of line numbers
* Simplify file names, move tutorials into subfolder
* PickPlace tutorial, stage extension howto guide
* add cartesian and first steps tutorials
* Add property tutorial, restructure tutorial files
* Reformat Documentation
  - create tutorial, how-to-guide, topic and reference chapters
  - move implementation examples from api documentation into
  how-to-guides
  - create a documentation overview on the first page
* Rework stages doc
* Pruning: Relax too strong assertion: PRUNED => !ARMED
  If two Connect stages are sequenced, both sides can become ARMED.
  However, that means that the wave of PRUNED status updates, shouldn't
  overwrite a present ARMED state.
  Added unit test.
* Connect: better document suppressing recursive loop
* polish: FixedState supports collision checking
* properly set comment markAsFailure without prior comment
* operator<< for Interface::Direction
* FixedState: ignore_collisions=false
  Check collisions for FixedState's scene and report failure if needed.
  Optionally, disable the check via the property ignore_collisions=true.
* Finetune solvers documentation
* Rework core documentation
* Rework python documentation
* Pick+Place: Correctly configure forwarding of "pregrasp" property
  ... from Grasp to UnGrasp stage
* GeneratePlacePose: Remove property "ik_frame" from stage
  - Instead, set ik_frame property on solution from passed object (frame).
  - Allow subframes to be used as "object" frames
* Enable InterfaceState's copy operator
* Fix pre-commit: python formatting
* Rework doc for properties.cpp
  - Use simple description strings
  Only for multi-line doc strings, use C++11 raw string syntax `R"(...)"`
  - Auto-generate signature
  - Name arguments via `py::arg()`
* Update rosdoc + sphinx config
* Improve top-level descriptions
* fix typo
* Fix demo/scripts/fixed_state.py
* core python docs
  - add python docs to core classes
  - rework whats included in the docs and what not
* stages docs and bindings
  - pybind bindings for all the examples
  - correctly format docstrings
* core docs, mwe monitoring generator
* expand core docs, add detailed examples
* add docstrings and mwe's
* comply to google format + add docstrings
* add docstrings, custom signatures
* add python docstrings
* sphinx configuration
  - Remove warning, originating from intersphinx configuration.
  - Add .rst files for the api documentation.
* Fixup: Provide wrapper for moveit::core::MoveItErrorCode
* Merge branch 'master' into wip-python-api
* core: export rviz_marker_tools dependency
* Merge PR `#309 <https://github.com/JafarAbdi/moveit_task_constructor/issues/309>`_: Fix Pruning
* Merge PR `#311 <https://github.com/JafarAbdi/moveit_task_constructor/issues/311>`_: fix Fallbacks
* FallbacksPrivateConnect
  Implement Fallbacks behavior for children of type Connecting.
  All other connect-like children are currently infeasible to handle,
  because we cannot forward a single job, i.e. a pair (from, to)
  to the next child, but only individual states.
  However, passing states, will cause creation of undesired state pairs
  as jobs in subsequent children.
* ParallelContainerBasePrivate::propagateStateTo*All*Children
  rename method to emphasize that state updates are propagated to all children
* FallbacksPrivateCommon: shared between Generator + Propagator
* FallbacksPrivate::nextChild()
  ... factoring out functionality shared between FallbacksPrivateGenerator
  and FallbacksPrivatePropagator to switch to next child in nextJob().
* Improve readability
* reset(new Interface()) -> std::make_shared<Interface>()
* Improve comments
* Generalize connectStageInsideFallbacks
  Let's consider the following simple situation, where generators produce solutions in the given order.
  GEN           1 3
  Fallbacks     |X
  GEN           2 4
  When passing state 4 to the Fallbacks' connector, it forms pending pairs with both 1 and 3.
  Thus, the container needs to check whether 1-4 or 3-4 was processed when receiving a success or failure,
  to correctly forward the failed one to the next child.
* GeneratePlacePose: add property 'allow_z_flip'
* ComputeIK: Improve markers
  - always provide eef markers (also in case of success)
  - tint failures in red
  - use different names for "ik frame" and "target frame" markers
  - reduce code duplication
* Add comment
* Export libmoveit_python_tools.so
* Return MoveItErrorCode from task::plan (`#319 <https://github.com/JafarAbdi/moveit_task_constructor/issues/319>`_)
  ... to know whether the plan failed due to timeout, preemption, or actual planning failure
* Merge pull request `#320 <https://github.com/JafarAbdi/moveit_task_constructor/issues/320>`_ from v4hn/pr-master-fix-move-rel-ikframe
  Fix using IKFrame with MoveRelative
* MoveRelative: Interpret direction relative to IKFrame
  bugfix
* add tests for MoveRelative
* Improve debug output
  - printChildrenInterfaces(): fix/add usage
  - printPendingPairs(): full colorization according to status
* ROS 2 Migration (`#170 <https://github.com/JafarAbdi/moveit_task_constructor/issues/170>`_)
* Port core to ROS2
* Stage::reset() should reset total_compute_time\_ (`#310 <https://github.com/JafarAbdi/moveit_task_constructor/issues/310>`_)
* Simplify: job_has_solutions\_
  Just set a flag when we received a full solution
* Rework FallbacksPrivate*
  Further factorize and simplify FallbacksPrivate classes employing ideas from @v4hn.
  The key difference between the variants his how they advance to the next job.
  Thus, the only virtual method required is nextJob().
* Disable failing test FallbacksFixtureConnect.connectStageInsideFallbacks
  ... as we are now missing the implementation for CONNECT interfaces
* Factorize implementation of FallbacksPrivate into 3 classes
* static TaskPrivate::swap() -> ContainerBasePrivate::operator=()
  - Enable moving/swapping of other container impls (e.g. Fallbacks)
  - Clarify (via move semantics) that content of source impl will be lost
  - Get rid of friend declarations
* Remove logger configuration
  Logger config can be more easily handled via ROSCONSOLE_CONFIG_FILE.
* Enable tests
  Adapt test results FallbacksFixturePropagate.computeFirstSuccessfulStagePerSolutionOnly
  due to 2e63c154aab41a9cde8684ac0880504cfc2a99d8:
  The order of computations has changed, because we lock the processed state
  as soon as it is forwarded to the first fallback child.
  In this case, after processing GEN1 und FWD1 once, we have the two states with costs 2, 4 in the queue.
  The first one, i.e. with cost 2 is forwarded to the child FWD2, which fails.
  In the next cycle, although we have new states in the queue (1, 2, 3, 4), we stick with state "2"
  and forward it two FWD3, which adds costs 210, resulting in 212.
  With previous code, the Fallback container switched to state "1", forwarded to FWD2.
* Reintroduce pending state
* debugging helper function
* Simplify computePropagate()
  - Drop variable current_external_state\_
  - Instead encode the info that the external state wasn't yet forwarded to any child via stage = children().cend()
  - If all children have exhausted their solutions for this state, it is removed from the pending list
* Handle updates on external states
* Fix pruning
  Pruning - if acting on the external state - needs to pass the current stage (this).
* Rename: computeFromExternal -> computePropagate
* GENERATE: return correct canCompute() result as early as possible
  Moving to next child generator only in compute() requires an extra call
  to canCompute() to notice the failure of the next generator(s).
* Propagate either STATUS or PRIORITY updates into a container
* Distinguish STATUS and PRIORITY updates in notify() callbacks
  to allow propagating status updates only if the STATUS actually changed.
* templatize: pullInterface(dir) -> pullInterface<dir>()
  Also remove unused pushInterface(dir)
* Propagate status across Connecting gap
  Not only propagate updates along solution paths, but also bridge
  the gap of a `Connecting` stage.
  - If a state becomes enabled, re-enable opposite `ARMED` states as well.
  - If a state becomes pruned, also prune opposite states if they don't have alternatives.
  - Make sure that we don't run into a recursive update loop by disabling notify() callbacks.
* Never overwrite ARMED with PRUNED
* Recombine both variants of Interface::updatePriority()
  As only the InterfaceState* variant is actually called,
  we can drop the splitting introduced for performance reasons in
  29d1e44c5da4649ee5a31a2903dfc3a57c27e341
* Recursively prune new CONNECT state if there is no enabled opposite
  This also requires to drop the assertion in SerialContainer::onNewSolution()
  that new solutions will have enabled start+end states (a CONNECT stage's solution might not).
* Recursively re-enable states when matching an ARMED state
* Rename Interface::Status FAILED -> ARMED
  ... to better indicate that such a state can be immediately re-enabled.
* Switch order of function declarations
  ... to avoid explicit template initialization
* Fix test Pruning.NoPruningIfAlternativesExist
* Fix hasPendingOpposites()
  - Switch directions: FORWARD <-> BACKWARD to make the function reusable for status propagation.
  - We need to ignore the source state when looking for opposite states of the target state.
  Thus add both, source and target state arguments.
* Rework updatePriority() functions
  - Centrally distinguish between have owner() or not in InterfaceState::updatePriority()
  - Have a separate updateStatus() method to just update the pruning status
  - Split Interface::updatePriority() into a method taking the InterfaceState*
  and one taking an Interface::iterator (for efficiency)
  - Early return in container.cpp's updateStatePrios()
* Drop unused and misleading Direction enums
* Never remove pending CONNECT pairs
  Both, failed and pruned states might get re-enabled later!
  This also required rework (simplification) of the sorting function for pending pairs.
* Improve readability
* Always skip pruning if there exist alternative enabled solutions
* Disable failing tests
* Add more pruning tests
* Fix printChildrenInterfaces()
* add debug logs to pruning code
* GeneratorMockup: Add solutions_per_compute argument
* fix fallbacks logic
  Setting up a demo for
  Fallbacks({CartesianPath,PTP,RRTConnect})
  I found the logic did not work as expected yet.
  - process last job spec as well
  - ignore failures when looking for a solution
  - add more debug output
* order external states
* run only one compute step per call
  Note that while this ensures other stages outside the Fallbacks container
  can compute as well, it does not solve the problem internally.
  A new incoming state will only ever be considered once
  the current stage cannot compute any more.
  We have no way of telling a child to compute for *a specific state* for now.
  So once we copied a state to its interface we have to let it compute until
  all possibilities are exhausted to detect whether or not it could generate a solution for it.
  If we wouldn't do so, there were no way of knowing when to fall back
  to the next child as long as the stage can still compute on *any* copied solution.
* cleanup: get rid of superfluous parameter
* simplify onNewFailure
  give an elaborate reason for an empty overload that doesn't call the parent.
* fallback generator can run a single job per compute call
* Implement state-wise Fallbacks
  Keep the previous logic around for Generator stages.
  Note that this only makes sense for *pure* Generators and not for MonitoringGenerator,
  because for the latter we would expect monitored solutions to be passed individually
  (similar to pruning).
* add hook to ParallelContainerBase to customize state propagation
* Merge pull request `#304 <https://github.com/JafarAbdi/moveit_task_constructor/issues/304>`_ from v4hn/pr-move-to-tests
  Add MoveTo tests & make them pass
* refactor logic to handle ik_frame
  fallbacks and verification.
* establish utils namespace
  leaves us a place to put free helper functions
* add compat header to cmake
  previous oversight
* simplify parameter-free lambdas
  I just didn't know the syntax was allowed
* Extend mtc_add_test() macro to handle rostest as well
* ComputeIK supports attached-object ik frame
* MoveTo supports attached objects&subframes for ik frame
* add move MoveTo tests
  (partially disabled because broken)
* InterpolationPlanner: implement simple IK-based solver for pose targets
* add some tests for MoveTo
* FixedState: add optional scene in constructor
* fix test helper
  never unload the plugin loader before the plugins (IK plugins here).
  We don't have unrelated loaders in gtest executables, so the static should be fine.
* Simplify code
  We know that trajectory at least comprises the start state.
  Thus, we don't need the sanity checks.
* move to tf2_eigen everywhere (`#301 <https://github.com/JafarAbdi/moveit_task_constructor/issues/301>`_)
* split off pruning tests
  yes, most pruning happen along children of a serial container,
  but children for many tests comprise a lot of other containers as well.
  - migrated pruning tests from Connect to ConnectMockup (as the concrete implementation
  is not relevant for them)
  - added missing header to stage_mockups.h
* consolidate test base
* define core tests through macros (`#299 <https://github.com/JafarAbdi/moveit_task_constructor/issues/299>`_)
  Maybe it makes sense to define this in an exported config,
  but then why bother until someone needs it.
* Merge pull request `#294 <https://github.com/JafarAbdi/moveit_task_constructor/issues/294>`_ from v4hn/pr-fallbacks-split-tests
  new set of fallback tests
* Optimize setStatus(): only escalate to parent interface at boundaries of a partial solution
  In all other cases internalToExternalMap().find(s) will fail anyway.
* DISABLED -> PRUNED
  This makes the semantics much clearer as states can only be disabled by pruning.
* simplify exception handling
  This could have been done already back when `runCompute` was introduced.
  Wrapping the calls in try/catch comes from the previous implementation directly
  calling `compute()`.
* Connecting: add another ROS_DEBUG hint
  These can facilitate debugging a lot for little overhead.
* DISABLED_FAILED -> FAILED
  Failed states are *not* disabled, they just failed connecting (for now).
* add todo
* disable currently failing tests
  They will be enabled when the corresponding functionality is merged.
* Add more fallback tests
* Replace std::list<double>() with PredefinedCosts()
* Simplify tests by introducing EXPECT_COSTS()
* fixup & extend fallback tests
* add another non-trivial test for a reliable fallbacks container
* add a test for generator-fallbacks
* fallbacks: add a test to use fallbacks *per state*
  The current implementation will not fall back for each state
  independently, but is meant to stay with the first child producing
  a solution. For propagators, this is problematic though
  as the picked child depends on the (arbitrary) first received state.
  Instead, fallbacks should pass each state to each child separately
  until one produces a solution for it (or all are exhausted).
* rearrange fallback test fixtures
* fallback tests: use fixture
* move fallback to separate test
* add another test to cover both cases for failing children
* disable ConnectStageInsideFallbacks
  This should work, but will require more changes.
* Fix test Fallback.ActiveChildReset
* add unit tests for Fallbacks container
* Improve readability of internal-external bimap using tags (`#293 <https://github.com/JafarAbdi/moveit_task_constructor/issues/293>`_)
* split assert
  so that it becomes obvious which condition triggered it.
* print debug message in runCompute
  so that it prints from all containers
* address interface changes for object poses in MoveIt
  Also include a check for the new object pose field in `Connecting::compatible()`.
* remove dirty MOVEIT_MASTER-check
  ... in favor of checking version numbers.
  Checking for one header was used for multiple independent things.
  In theory we could do exact feature testing instead of using the next release number,
  but in practice nobody cares about the individual commits between older releases.
* ComputeIK: spawn failures with correct states
  Otherwise all failures look correct in the introspection.
  That was a stupid oversight at some point.
* do not modify scene in isTargetPoseColliding
  Especially, do not create a custom scene at all.
  The method only affects a RobotState.
  Fixes https://github.com/ros-planning/moveit_task_constructor/issues/209
* Merge different mockup implementations
  Co-authored-by: Jascha Kühn <57101356+j-kuehn@users.noreply.github.com>
* test_container: correctly initialize robot_model
  The local mocks do not care, but leaving a dangling nullptr
  leads to segfaults with refactoring/new tests. :-)
* better API comments for StageCallback
* GenerateGraspPose: Handle RobotState.msg as pregrasp property (`#275 <https://github.com/JafarAbdi/moveit_task_constructor/issues/275>`_)
  Co-authored-by: v4hn <me@v4hn.de>
* Merge branch 'master' into wip-python-api
* Skip some python tests on incompatible pybind11 versions
  If MoveIt and MTC use incompatible versions of pybind11, the tests
  will fail because MoveIt objects like RobotModel or PlanningScene
  cannot be passed to MTC objects and vice versa.
* Fix utf8 encoding
* support TYPED_TEST_SUITE
  Get rid of deprecation warning if new variant exists.
* add missing virtual destructor to CostTerm
  Correctly pointed out by the clang-tidy CI.
* satisfy clang-tidy & -Werror -Wall -Wextra
* Add missing semicolons after cleanup of MoveIt
* Split ClassLoader plugin code from main libraries (`#271 <https://github.com/JafarAbdi/moveit_task_constructor/issues/271>`_)
  to work around https://github.com/ros/class_loader/issues/131
* Fix test: correctly reset Interface
* Fix memory leak in unit test
* Fix compiler warnings
* allow to consider specific joints only in cost terms
* PyMonitoringGenerator
* Fix names of trampoline classes
  Using template names T is not a good idea, because this name is used
  verbatim for some error reporting, resulting e.g. in:
  Tried to call pure virtual function "T::canCompute"
* Update pybind11 submodule
* smart_holder: conservative mode
  ... to become compatible with classical pybind11 modules, e.g. the MoveIt packages
* Generator::spawn()
* Use pybind11's smart_holder branch
* Use py:overload_cast<>()
* Merge branch 'master' into wip-python-api
* Augment license/disclaimer
* Allow casting of PoseStamped from string
* Fix compiler warnings
  unused parameters and functions
* remove unused helper method
* fix pick_ur5 test
  TAMS' models changed and often produces less solutions.
* add visualization for Point goals (`#264 <https://github.com/JafarAbdi/moveit_task_constructor/issues/264>`_)
  - move visualization from `getPoseGoal` to `compute`
  - create target frame from `target_eigen` to allow visualization from Pose and Point goals
* Improve arrow visualization for MoveRelative stage (`#255 <https://github.com/JafarAbdi/moveit_task_constructor/issues/255>`_)
  Implement visualization as red-green arrow
  * overload makeArrow to allow creation with points
  * create new function for visualization
  * if no plan is found, construct arrow from green cylinder and red arrow
  * adjust arrow construction for backward propagators
* Merge pull request `#261 <https://github.com/JafarAbdi/moveit_task_constructor/issues/261>`_ from ubi-agni/GHA
  Switch to GitHub actions
* Fix more clang-tidy issues
* clang-tidy auto-fixes
* Fix trailing white space
* Simplify tests
* Implement pruning inside-to-outside of a container
  - Remove public onNewFailure() interface
  Moved to ContainerBasePrivate to reuse logic for serial and parallel containers.
  - Add tests
* Configure namespace package
* Rename wrapper -> bindings
* rosdoc_lite configuration
* Simplify generation of pybind11 modules
  * Install module libs into CATKIN_GLOBAL_PYTHON_DESTINATION (assuming unique names).
  This avoids the need to link them into the source space, because they are found also from devel space.
  * Use pybind11's def_submodule() to create the `core` and `stages` submodules,
  everything linked into the same lib
* clang-format python wrapping code
* Towards inherited classes in Python
* implement bimap for internal_external state map
  Get hashing for inverted lookups, but incur
  structural overhead.
  Whether this is worth it depends on the number of mapped interface states
  and the number of pruning/reactivation requests.
* fix constness
* Implement pruning inside serial container
  By inefficient inverse lookup.
  Also add disabled test for the inverted inference (failure inside should prune outside)
* Rework PipelinePlanner creation (`#249 <https://github.com/JafarAbdi/moveit_task_constructor/issues/249>`_)
  - Moved Task::createPlanner into PipelinePlanner::create
  - Handle mutiple planner pipeline configs as introduced in https://github.com/ros-planning/moveit/pull/2127
* Rework Pruning (`#221 <https://github.com/JafarAbdi/moveit_task_constructor/issues/221>`_)
* Explicitly instantiate PropagatingEitherWay::send<> templates (`#246 <https://github.com/JafarAbdi/moveit_task_constructor/issues/246>`_)
  Otherwise compiler was optimizing (inlining) them away.
* add more asserts to onNewSolution
  Strictly speaking there is no need for the invariant,
  but if something violates it a stage computed something it wasn't meant to.
* only run propagators on enabled solutions
  resolve simple pruning test
* add (failing) simple pruning test
  to validate propagators do not compute disabled solutions.
  It's also good to have a simpler test around than 2 connects.
* pruning tests: restructure tests
* add more (commented-out) debug statements
  Also print generator symbol for completeness.
* resolve PruningMultiForward test
  Every InterfaceState along the partial solution has to be disabled
  for pruning, not just the ends that are currently relevant.
* add failing pruning test for branching propagator
* streamline trait parameters
  state asked for a reference, but trajectories for a pointer.
* rename Status values
  Start and End are already used for an entirely different concept,
  so if anyone ever wants to read this code, we should use new terms instead.
  Because the source state is the disabled state that *failed* to extend,
  triggering the whole subtree to be disabled, I went for the new terms
  DISABLED and DISABLED_FAILED.
* Remove debug output
* Replace Priority::enabled() with status()
  The key to pruning in the Connecting stage was the following:
  - Don't remove states during pruning, but only disable them.
  They might become re-enabled due to further input.
  - Distinguish START and END sides of a disabled solution tree to break their symmetry.
  The START side from where we started disabling, can be re-enabled by a new partner state in
  Connecting, the END side must not. This was important as, otherwise, the states would simply
  get re-enabled immediately. The END side only gets re-enabled if the START side actually
  connects the whole solution branch.
* Debug evolution of interfaces
* operator<< for Interface + Priority
  Co-authored by v4hn
* Extend unit tests: PruningForward + PruningBackward
* Actually implement pruning and re-enabling of states
* Restore pruning
  If a stage fails to find a solution, this often implies that further planning
  on the open end(s) of connected InterfaceStates is not needed anymore.
  Thus the InterfaceStates along all connected solution paths will be marked as disabled.
  They are not removed from the pending state lists though, because they might get
  reactivated by solutions found in future.
  To this end, we introduced the method ContainerBase::onNewFailure().
* test comparison of ConnectingPrivate's StatePairs
* InterfaceState::Priority::enabled()
  To allow pruning, we need to enable and disable InterfaceStates to be considered for further
  planning. In the past, we just indicated the disabled status with infinite costs.
  However, because we might need to re-enable states (with previous state),
  we need to separate these two concepts.
* PythonWrapper: Use collective includes
* Simplify wrapper code
* Access to container's children
* auto-format python code with black
* MoveTo/MoveRel: reduce code duplication
  ... using templated versions for computeForward + computeBackward
  as they essentially perform the same operations.
* MoveTo/MoveRel: Report errors via solution comments instead of ROS_WARN
* Perform clang-format check via github action from pre-commit.com
* Replace MoveIt! -> MoveIt
* add test to validate correct solution state in computeCost
  This is somewhat cumbersome because of the additional internal/external
  layer introduced through the container.
  But it's still better than leaving this unverified.
* fix computeCost interface (again)
  Fixes the missing creator pointer introduced in a6a23d3775be81cdd5920d8c79e218edc199f7c5
* remove leftover joint counting
  Not used anywhere
* output stream formatting for InterfaceState::Priority
* Remove return value from Container::insert
  adapted Container::add
  Logical consequence of removing the ROS_ERROR output in `setParent`
* remove roscpp as an export dependency for the core package
  We do use ROS in the background. But there is no need for a public export dependency on it.
  This patch also resolves the following catkin_lint issue:
  moveit_task_constructor_core: CMakeLists.txt(17): error: package 'roscpp' must be in CATKIN_DEPENDS in catkin_package()
* Fallback: Correctly end iterating children
  Fixes `#234 <https://github.com/JafarAbdi/moveit_task_constructor/issues/234>`_
* Use RobotModelBuilder to simplify tests (`#225 <https://github.com/JafarAbdi/moveit_task_constructor/issues/225>`_)
  * Simplify RobotModel definition using RobotModelBuilder
  * Silent RobotModel errors once in models.cpp
* getTaskId(): Replace '-' in hostname with '_' (`#223 <https://github.com/JafarAbdi/moveit_task_constructor/issues/223>`_)
* minor cleanups
  * unify usage of pimpl()
  * fix StatePair constructors
  * improve/add comments
  * test_container: reset MOCK_ID for each test to facilitate identification of stages
* Propagating: disable infeasible state pruning
  Because stages might get re-enabled later, we must not throw them away.
  Remove dropFailedStarts(), dropFailedEnds().
  Extend Pruning unittest.
* Remove set[Start|End]StateUnsafe
  These methods were introduced to temporarily set meaningful states for cost calculation
  w/o connecting the solution to these temporary states (to solve a chicken-egg problem).
  This commit provides TmpInterfaceStateProvider as an alternative approach to this problem.
  This essentially reverts 53c0964618c9920faea0f931fe771fa80bd02b8f.
* Simplify SolutionCollector
* Remove default constructor for Priority
  It's better to explicitly state the initial value.
* Provide move constructor for InterfaceState
  The code was tuned to move InterfaceStates around, but there wasn't the matching constructor!
* Modernize: require cmake version 3.1.3
* Fix issues `#182 <https://github.com/JafarAbdi/moveit_task_constructor/issues/182>`_ + `#218 <https://github.com/JafarAbdi/moveit_task_constructor/issues/218>`_
* Connect: Decouple subsolutions of SolutionSequence from external interface states
* SerialContainer: Simplify solution traversal
  Compute depth + accumulated cost of a partial solution sequence using InterfaceState::Priority.
* Connect: mark failures in sub solutions of a sequence
* Interface::updatePriority(): only allow decrease
* Fix cost calculation
  The default CostTerm should rely on precomputed costs. Only, if a CostTerm is explicitly defined
  for a particular stage, it should modify costs.
* Simplify state priority updates
  Only need to update the end points of a partial solution.
* SerialContainer tests
* Test Interface::updatePriority()
* Python3 compatibility
* migration: boost::python -> pybind11
* Merge branch 'master' into wip-python-api
* StagesWrapper: Python Function Bindings
  Add python bindings for
  - SimpleGrasp::setIKFrame
  - Pick::setApproachMotion
  - Pick::setLiftMotion
* MoveTo: Publish failed planning attempts
* Merge PR `#214 <https://github.com/JafarAbdi/moveit_task_constructor/issues/214>`_ (fix various issues) and `#215 <https://github.com/JafarAbdi/moveit_task_constructor/issues/215>`_ (rework rviz introspection)
* Create task-specific ServiceClients to fetch solutions
  This finally allows to have multiple tasks publishing in the same namespace.
* IntroSpection: indicateReset() on disable
* Allow naming a Task
  which just names the top-level container
* Rename process_id -> task_id
* Rename TaskPrivate::id -> TaskPrivate::ns
  TaskPrivate's id\_ actually served as a namespace parameter.
* Connect: Fix segfault when accessing solutions from multiple plan() calls
  Connect::init() was resetting its dynamically created JMG merged_jmg\_,
  thus invalidating all previous solutions. Only reset the JMG in reset().
* Improve task unittests
* Task: Add ability to set timeout (`#213 <https://github.com/JafarAbdi/moveit_task_constructor/issues/213>`_)
  Task::setTimeout will allow setting an overall timeout.
* StagesWrapper: Add std::map setGoal overload.
  Adding a further overload of the `setGoal()` function that is exposed to
  the python api. This should provide an interface for passing in dicts as
  joint name and -angle configurations.
* Fix issues with Merger stage
* Report exceptions (e.g. config issues)
* Report merge failures
* Reject failures early
* Test Merger
* fix typo
* Fix interface resolution
* Container::remove(): return removed Stage
* Merge PR `#183 <https://github.com/JafarAbdi/moveit_task_constructor/issues/183>`_: CostTerm API
* clearer naming of cost variables
* melodic compatibility
* initialize default CostTerm in constructor
  It seems to be too fragile to rely on `init` being called.
  On the other hand we should really enforce this anyway. -.-
* Update comments to solution's computeCost() methods
* rework CostTerm's from support flags to vtable
  requested in review.
  Without support for custom aggregators, which we dropped again
  after finding more flaws with it, I agree that this is the nicer solution.
  On the downside, it converts the interfaces from copyable objects
  to another round of shared_ptrs.
  I added shortcuts for lambda costs to keep support for
  `stage->setCostTerm([](auto&& s){ return 42; })`
  without the additional
  `stage->setCostTerm(LambdaCostTerm{ [](auto&& s){ return 42; } } )`
* Revert "add CostAggregator for SerialContainer"
  This reverts commit dc7ce9bdfac97eb468f5a850adcb27cc118b5fd7.
  It turns out multiple places in SerialContainer's cost inference
  expect 0.0 as the neutral element (which is why std::min and multiply did not work).
  While these additional issues can be fixed, it would make the interface much less elegant.
  We should consider adding it back if an actual use-case is there to discuss.
* Clearance: provide better interface for different modes
  Interface::Direction should always designate a valid direction.
* Make transform in cost::Clearance configurable
  In theory this can be done with a PassThrough with a modifying transform,
  but this specific mapping is intrinsic to the definition of Clearance as a cost.
* refactor Forward -> PassThrough
  based on review feedback
* simplify LinkMotion computation
  review feedback
* enable implicit construction of CostTerm from lambdas
  without the need for explicit casts to the correct signature.
* provide CostTerm class for all CostTerms
  This pattern allows cost::Constant to override the hierarchical cost computation
  for the SerialContainer and avoid traversing the graph.
  I implemented the CostTerm::supports() pattern over a full double visitor pattern
  with overloads for each SolutionBase specialization, because the SerialContainer
  needs to know whether cost aggregation of the subsolutions should take place or whether
  the SolutionSequence should be forwarded to the CostTerm.
  This would not be possible with a `virtual double operator()(const SolutionSequence&)`
  callback in CostTerm.
  Alternatively, implementing the hierarchical aggregation in the default implementation
  of this operator would be possible as well, but breaks intuition:
  - the corresponding methods to handle `SubTrajectory` and `WrappedSolution` *have to*
  default to not touching the solution's cost at all so it is inappropriate to have
  the default implementation for the Sequence do something else
  - The SerialContainer also aggregates costs outside the `computeCost()` interface
  (in multiple places in `onNewSolution()` to aggregate costs along partial paths)
  and thus moving the hierarchical aggregation to the CostTerm methods requires
  the aggregator to be shared between the Container and the CostTerm,
  The only shortcoming of the implemented approach, by contrast, is that user implementations
  that want to handle WrappedSolution or SolutionSequence differently have to ensure
  the supports\_ flags are set correctly. Notice that most custom CostTerms will only
  ever access SubTrajectories and this case is simplified with the provided CostTerm constructors.
* add CostAggregator for SerialContainer
  It can be useful to change the default addition to other operators.
  The simplest example is applying a Constant cost term to a container.
  As the tests show, the visitor-based cost computation ends up adding
  cost::Constant *for each subtrajectory*.
* improve cost term tests
  - add tests for nested containers
  - add descriptions to checks
  - refactor helper to support different containers
* add basic tests for using cost terms
* introduce new trivial stage Forward
  This can be used together with a custom CostTerm to modify costs of a solution.
* compute cost in liftSolution as well
* setCostTermShort(nullptr) must not set a valid function
* avoid ambiguity of setCostTerm(nullptr)
* allow setCostTerm for containers
  implement visitor pattern for cost computation on solutions
  - compute cost terms for solution subtrees instead of only for SubTrajectory
  - allows users to set cost terms for containers
* move more overhead to computeCost
* remove CostTransform
  If required, this can hopefully be implemented through Wrapper stages soon.
* cost computation: provide valid interface states for Solution
  The CostTerm's should get only a single solution that is well-setup
  with its InterfaceStates. That's impossible though because these
  states are stored in different places depending on the cost.
  To avoid this, set stub states for cost computation
  and change them to the real states later on.
  This is motivated by the Clearance cost which can act on an InterfaceState only.
* make cost operators const
* refactor addCost->computeCost
* generalize Clearance cost
  - can now be used to estimate cost for either interface state or the trajectory
  - Introduced Interface::Direction NONE as a way of pointing to the trajectory in contrast to START or END
* add missing license
* remove Cost suffix for elements in mtc::cost::
* implement LinkMotionCost
* implement correct PathLengthCost
  The previous implementation depends on the dynamics limits of the robot,
  which might be interesting in some cases, but shouldn't be a default anywhere.
* add cumulative distance to ClearanceCost
* turn Clearance cost into parameterized struct
  There is a lot of variations for how to compute clearance.
* establish struct cost pattern
  for costs with multiple parameters, this option-style is more useful
  than verbose getter/setter. There is nothing to hide here.
* enable costs to (optionally) return a comment
  With more complicated costs (such as the ClearanceCost), it's useful to get comments.
* allow wrappers to use CostTerm
* first attempts on ClearanceCost
* improve comments
* add CostTransform
  CostTerms only apply to primitive solutions and generalizing them
  to Containers would make them quite unintuitive (and adds overhead).
  Instead CostTransform can be used in any container to scale, crop, square
  the cost of the solutions.
  I initially thought about adding scaling factors, but then again,
  other transforms are of interest just as well.
* fully restrict CostTerms to primitive solutions
  simplify implementations.
* add explicit default CostTerms to most basic stages
  Simplifies code and makes the costs of each stage explicit.
* provide Constant and PathLength cost terms
* add CostTerm interface
  basic stages can now be configured with arbitrary cost terms.
* fix stage test mock
  base class init needs to be called although this didn't pose problems
  until now.
* Silence -Wdeprecated-declarations due to std::auto_ptr
* Merge branch master into wip-python-api
* WrappedSolution: expose child solution
  SolutionSequence allows to access children already,
  but WrappedSolution blocked access to the full hierarchy.
* expose WrappedSolution together with other Solution types
  Moved out of private header.
  Users can access these objects, so they should know about the type.
* Solution: export public creator
  It's a public interface, returning private pointer is not neat.
* InterfaceState: provide constructor with initial Priority
  most useful to prepare a valid InterfaceState in tests
* PredicateFilter: actually use declared property
* MoveTo: support map<string,double> joint target
  There was a corresponding setGoal method already, but no implementation...
* Apply clang-format-10 (`#199 <https://github.com/JafarAbdi/moveit_task_constructor/issues/199>`_)
* adapt tests to new moveit_resources layout (`#200 <https://github.com/JafarAbdi/moveit_task_constructor/issues/200>`_)
* fix c&p error in documentation
* expose Stage API to get the matching introspection ID
  This was implicitly requested in `#192 <https://github.com/JafarAbdi/moveit_task_constructor/issues/192>`_ .
* do not mix pimpl() and impl for no reason
* fix unused-parameter warning
* fix comment typo
* send a single reset message when introspection is enabled
  My previous patches accidentally disabled *all* (3) reset messages,
  instead of keeping exactly one. This patch sends exactly one empty description
  (reset) message every time an introspection instance is constructed for a task.
  Notice the additional increase of the description queue_size from 1 to 2 to avoid
  directly dropping the reset message in favor of the new description likely to be send
  shortly afterwards.
* introspection *can* be disabled
  Otherwise a new task will always setup the publisher,
  even if introspection is disabled afterwards.
  It is a good idea to keep introspection on, but there should be a way to initialize the C++ classes without ROS communication.
* replace remaining typedefs by using declaration
  I have no idea why these were not picked up by clang-tidy.
* fix autocomplete typo
* Improve code readability
* SolutionMsg: always fill start_scene (`#175 <https://github.com/JafarAbdi/moveit_task_constructor/issues/175>`_)
  So far, the start_scene field of a SolutionMsg was only filled by  Introspection::fillSolution(),
  but not yet by Task::execute().
  Addendum(v4hn): The previous approach was actually reasonable too (although the scene should have been marked as `is_diff`) for solutions sent for execution, but keeping the full start_scene around can facilitate debugging from recorded data.
* MoveRelative: provide failure message
* clang-tidy: performance-*
  I NOLINTed the noexcept move constructor for Task for now because
  the constructor *can* indeed throw exceptions.
* clang-tidy: llvm-namespace-comment
* clang-format: readability-identifier-naming
  Probably the most invasive format patch, also changing some internal API.
  I deliberately disabled ClassCase and MethodCase checks for the moment
  to avoid public API changes in this patch set.
* clang-format: readability-container-size-empty
* clang-tidy: readability-named-parameters
* clang-tidy: modernize-use-nullptr
* clang-tidy: modernize-use-override
* clang-tidy: use using over typedef
  $ run-clang-tidy.py -header-filter='.*' -checks='modernize-use-using' -fix
  add .clang-tidy file
* grant access to subsolutions of a sequence
  SubTrajectory allows to access the trajectory,
  but for SolutionSequence is was not needed until now.
* add informative comment
* do not reset on plan
  users can reset explicitly as needed.
  Reset sends ROS messages and prevents { plan(1); plan(1) } style usage.
* check for valid robot model
  Also, no need to reset() unless the model is different and not the first.
* fix typo
* extend comment on unintuitive setter
* Add ability to add/remove objects to/from planning scene (`#165 <https://github.com/JafarAbdi/moveit_task_constructor/issues/165>`_)
* Fix for GCC5 (Ubuntu 16.04 / Kinetic) call to non-constexpr function (`#163 <https://github.com/JafarAbdi/moveit_task_constructor/issues/163>`_)
  Co-authored-by: Aris Synodinos <aris.synodinos@unibap.com>
* add convenience includes
* expose group property
* Merge `#156 <https://github.com/JafarAbdi/moveit_task_constructor/issues/156>`_: Rework interface resolution
* SerialContainer: Resolve interfaces of all stages
* cleanup / renaming
  * Rename pruneInterface() -> resolveInterface()
  * Rename accepted (interface) -> expected
  * Improve exception strings
* simplify internal API
* Combine pruneInterface() + validateConnectivity()
  Validate interfaces during resolution. No need to separately validate interfaces.
  Thus, validateConnectivity() is removed from Task::init().
  Functions are kept (but simplified) for unit testing.
* Further simplify interface resolution
  * Do not modify explicitly configured direction of Propagator
  * Avoid code duplication in pruneInterface() and validateConnectivity()
  Only implement pruneInterface() for stages that actually need to adapt their interface.
* New test: keep previously configured propagate interface
* minor cleanup, fixing warnings, improving comments
* templated flowSymbol<input/output mask>(flags)
  * Enforce at compile time that either input or output flags are considered.
  * Use horizontal flow symbols (as in console output).
  * Replace redundant direction(flags).
* Simplify test_container.cpp
  * Reset mock_id for each test to facilitate assignment
  * Simplify creation of nested containers
  * Moved some test cases around
  * Output all exception messages (even expected ones)
* Allow constructing PipelinePlanner from PlanningPipelinePtr (`#155 <https://github.com/JafarAbdi/moveit_task_constructor/issues/155>`_)
* remove logical flow BOTH / simplify pruning
  The PROPAGATE concept BOTH declared the stages *will* propagate solutions in
  either direction. ANY, on the other hand, only means the propagation
  direction is *not resolved yet* (but will be at planning time).
  BOTH was originally described to support a more general control flow
  than was eventually decided to support. The four exclusive Stage interfaces
  CONNECT, PROPAGATE_FORWARDS, PROPAGATE_BACKWARDS, and GENERATOR
  do not allow for BOTH as a valid setup anymore, unless you setup a very
  convolved task like `Alternatives(GEN, PROP) - Alternatives(PROP, GEN)`
  which would be very complex to inspect. The same functionality can still
  be achieved more readable as `Alternatives(Seq(GEN, PROP), Seq(PROP, GEN))`.
  The confusion between BOTH (propagator *will* send in both directions) and
  ANY (propagator will send in *either* direction, decided during init) led
  to a lot of confusion with users and was not fully accounted
  throughout the pipeline.
  Adjust tests.
  Notice the difference between ANY (unresolved propagator) and UNKNOWN
  (a container before introspecting its children). propagators still
  report UNKNOWN as requiredInterface though to simplify control flow.
  The simplification enables a much simpler linear inference of the connective
  structure of a task, as the first interface direction is always given.
  Additionally, unify the resource setup for static interfaces to run
  in the constructor, and for dynamic initialization in `pruneInterface`,
  getting rid of partial initializations in `init`.
* enumerate test stages
  remove ambiguity when multiple stages of the same type are used
* treat empty container as init exception
* minor documentation improvements
* bump cmake version
  get rid of CMP0048 warning.
* Merge pull request `#151 <https://github.com/JafarAbdi/moveit_task_constructor/issues/151>`_: Various fixes
* merge: update states only once per waypoint
* simplify trajectory merging
  avoid code duplication: reuse merge(std::vector<JointModelGroup*>)
* fix joint_interpolation
  - return a trajectory in any case (even if there is no motion needed)
  - check feasability of goal pose
* add override in Task
  I very much considered just removing the protected inheritance again,
  but it would add unnecessary code duplication.
  Take note, the overriding `insert` function bypasses the Wrapper and directly forwards to the wrapped container.
  This is somewhat dirty and could be an issue for anyone inheriting from `Task`.
* resolve clang warnings & suggestions
* correct sign for StageCallback type
  backward compatible, the function type implicitly converts from previous int definitions.
* rename Task::erase -> eraseTaskCallback
  `erase` is too general for a container class,
  when it's not actually about erasing children or the container itself.
* streamline add/insert interfaces for Task/Container
  `add` falls back to `insert` for both structures,
  but `add` throws exceptions and does not provide a return value.
  `insert` provides standard STL container access.
* enforce one-parent policy in StagePrivate
  So new containers cannot get this wrong by accident.
* do not export inline functions (`#147 <https://github.com/JafarAbdi/moveit_task_constructor/issues/147>`_)
  This makes sure that code using `pimpl()` will not compile out of the box unless the _p header is included.
* build tests using gmock via catkin_add_gmock (`#148 <https://github.com/JafarAbdi/moveit_task_constructor/issues/148>`_)
  Otherwise these suddenly started to fail for me on Lunar Linux...
* avoid copy from const id reference
  This mustn't compile as users got confused about it:
  ```
  Task t;
  t.id() = "foobar";
  ```
* Container: abort traversal with false return value of processor
  So far, returning false from the processor function, just skipped further traversing the current child (depth-wise).
  Now, traversal is completely aborted, even not traversing the remaining siblings of the current child.
  Having a single boolean return value, we cannot distinguish both cases.
  We need the new behaviour for 8061945c15bea22e8f8899c987bc28e3542885aa.
* don't install PIMPL header files (`#119 <https://github.com/JafarAbdi/moveit_task_constructor/issues/119>`_)
* Add return value to Task::execute (`#136 <https://github.com/JafarAbdi/moveit_task_constructor/issues/136>`_)
* fix memory access issue
  Fixes `#132 <https://github.com/JafarAbdi/moveit_task_constructor/issues/132>`_.
* Added C++11 flags for MOVEIT_MASTER check (`#129 <https://github.com/JafarAbdi/moveit_task_constructor/issues/129>`_)
* Merge `#120 <https://github.com/JafarAbdi/moveit_task_constructor/issues/120>`_: Add computation timing
* transmit and display computation in rviz
* use runCompute()
* Stage::runCompute() to measure computation time
* Merge branch master into wip-python-api
* Task: don't publish solutions by default
  Having multiple solutions, automatic publishing of intermediate solutions is confusing.
  One never knows, which one is the final one. If desired, the user should setup a hook for this.
* Expose SolutionCallback API in Task (`#121 <https://github.com/JafarAbdi/moveit_task_constructor/issues/121>`_)
* RosMsgConverter: ensure that python and C++ types match
* simplify method overloads
* boost::python: provide generic converter for std::map
* avoid deprecation warnings of MoveIt master branch
  Use new methods
  - moveit::core::isEmpty
  - moveit::core::CartesianInterpolator::computeCartesianPath
* compatibility to MoveIt master branch
* fix MoveRelative::getJointStateFromOffset
  Fix for `#114 <https://github.com/JafarAbdi/moveit_task_constructor/issues/114>`_: Accessing variable indexes was screwed.
* Added cost calculation in move_relative (`#108 <https://github.com/JafarAbdi/moveit_task_constructor/issues/108>`_)
* update RobotState in getJointStateGoal()
* MoveTo/MoveRelative: report failure on invalid trajectories (`#107 <https://github.com/JafarAbdi/moveit_task_constructor/issues/107>`_)
* Merge branch master into wip-python-api
* Fixup: adding cost calculations to connect and move_to
* PipelinePlanner: always forward trajectory
  (also in case of failure)
* Fixup: adding cost calculations to connect and move_to
  Need to handle nullptr trajectories.
* Introduce clang-format (`#102 <https://github.com/JafarAbdi/moveit_task_constructor/issues/102>`_)
  * fix catkin_lint issues
  * introduce clang-format config and apply it
* adding cost calculations to connect and move_to
* micro-fix whitespace
  Let's use clang-format...
* test packages are required
* fix Task::operator=(Task&&)
  To move a task instance to another one, it's not sufficient to swap all task members,
  but we also need to adapt all back pointers, i.e. me\_ and parent\_ pointers of children,
  to point to the (swapped) task instances.
* relax assertion
* improve comments
* Overload setGoal to accept map of joint values as argument (`#87 <https://github.com/JafarAbdi/moveit_task_constructor/issues/87>`_)
* Merge branch 'fix-interface-deduction' into master
* fix clang-tidy warnings
  - virtual functions used in constructor / destructor
  - captured variable in lambda expression not used
  - unhandled enums in switch
* ParallelContainer: fix interface error reporting
  need to separately check for start/end interface
* SerialContainer: fix nested interface resolution
  We need to distinguish two cases for how the interface of a nested serial container is determined:
  1. from its children
  2. from its (outer) context
  As long as the interface is not fully resolved, requiredInterface() returns UNKNOWN.
  After pruning, the first/last child's interface is remembered and reported instead.
* fix unit test definitions
* replace assertion by exception
* rename [INPUT|OUTPUT]_IF_MASK -> [START|END]_IF_MASK
* improve comments
* cherry-pick changes from boost-python branch
  stages: default arguments for constructors
  properties: make iterator public
* FixedCartesianPoses
* ContainerBase::remove(Stage* child)
* SimpleGrasp: only use generator if it's defined
  UnGrasp doesn't need a grasp generator
* vary place pose depending on object shape
  - boxes, cylinders: flip up/down, rotate about world's z
  - spheres: rotate about world's z
* use simple InterpolationPlanner to open/close gripper
* fix SimpleUnGrasp
  - ComputeIK needs to be first sub stage for both, grasping and ungrasping
  - correctly re-enable object collision checking
* GeneratePlacePose
* ContainerBase::findChild()
* Merge branches 'fix-interface-deduction' (`#84 <https://github.com/JafarAbdi/moveit_task_constructor/issues/84>`_), 'compute-ik-default-timeout' (`#80 <https://github.com/JafarAbdi/moveit_task_constructor/issues/80>`_),
  'fix-visualization' (`#76 <https://github.com/JafarAbdi/moveit_task_constructor/issues/76>`_), and master-improvements (`#81 <https://github.com/JafarAbdi/moveit_task_constructor/issues/81>`_)
* fix pruning
  Never augment already derived interfaces, only prune!
* improve SerialContainerPrivate::pruneInterface
* move validateConnectivity() from ContainerBase to StagePrivate
  ... to allow specific stage types (PropagatingEitherWay) implementing their own validation
  No need for a public interface.
* prune UNKNOWN *and* PROPAGATE_BOTHWAYS
  If PropagatingEitherWay's interface is not met in *both* directions (but only one),
  in BOTHWAY mode, issue a warning. Otherwise handle both, AUTO and BOTHWAY mode,
  in the same fashion when resolving interfaces.
  TODO: move validateConnectivity() in StagePrivate.
  default action = default action from ContainerBase.
  PropagatingEitherWay: issue warning for case above
* fix comments + typos
* Container: more unit tests for interface detection / validation
* fixup! improve error msg for mismatching container/child interfaces
  We need to consider input and output interfaces separately.
  Also, use console output symbols (<- / -> / <->)
* non-const Property::value()
* MoveTo/MoveRelative: reduce default timeout to 1s
* ComputeIK: allow attached body as ik_frame
* cannot use cmake generator expressions in COMMENT
* fixup wrapping of solvers
  - wrap JointInterPolationPlanner
  - remove properties: group, timeout
  - add actual planner properties
* expose PropagatingEitherWay::restrictDirection()
  fixup! expose PropagatingEitherWay::restrictDirectio()
* ComputeIK: auto-configure default timeout from JMG's default
  TODO: actually set the default value but not the current value!
* Connecting: also check that attached objects match
* Merger: skip empty sub trajectories for merging
* ComputeIK: fix typo
* rework solution msgs
  - to allow solution wrappers (WrappedSolution, SolutionSequence)
  to transmit their comment and markers as well
  - introduced new SolutionInfo.msg,
  which is the info common to solution wrappers and actual SubTrajectories
* correctly sort upstream_solutions\_ in ComputeIK and GeneratePose
  Reworked cost_queue to correctly sort pointer-like types.
  Added unittests for new ValueOrPointeeLess<T> less operator, ordered<T>, and rviz cost ordering.
* generate IK solutions incrementally
  This is not a good approach.
  The same can be achieved by generating targets incrementally.
  The better approach, to generate IK solutions incrementally,
  has to maintain previous solutions for each target.
* Merge PR `#72 <https://github.com/JafarAbdi/moveit_task_constructor/issues/72>`_: rviz property visualization
* yamp-cpp parsing
* YAML property serialization
  - switch from ROS serialization/deserialization to YAML
  - no native C++ deserialization for ROS msg types available
  - drop Propert::print()
* unify property handling in LocalTaskModel and RemoteTaskModel
* Task: fix RobotModelPtr leak
  On Task::clear() also need to reset introspection's cache.
* improve error msg for mismatching container/child interfaces
* Property::type_index -> boost::typeindex::type_info
  avoid decl expressions, explicit public typedef
* PropertyTypeRegistry to store serialization/deserialization functions
* Eigen::Affine3 -> Eigen::Isometry3
* let marker_ns default to stage name
  The stages can still decide on their namespaces on their own,
  but markerNS() at least provides a stage-specific name they can use.
* add accessors for marker_ns property
* document timeout() helpers
* ComputeIK: threshold for new solutions as property
* fix broken rvalue-forward & SerialContainer assert
  Release mode builds previously produced broken solutions with too many entries,
  debug build triggered the assert
  container.cpp:334: assert(solution.empty())
  The standard guarantees std::vector(&&a) leaves a.empty() == true,
  so the logic there is fine as long as subsolutions is actually
  used for move-construction.
* use task id as default name of top-level stage
* predicate filter: fix documentation
* add PredicateFilter
* GenerateGraspPose: spawn failure if object unknown
* move storeFailures() into public Stage API
* modify ps: add convenience functions
* Add test for all stages' PropertyMaps
  Iterate over all stages and their properties to see check for missing conversion functions.
* disable python default constructors for some classes
  these classes do not yet handle nullptr as their argument
* Provide default constructors for all stages
* cleanup converter for ros::Duration
* add converter for std::set<std::string>
* register enum Connect::MergeMode
* fixup! generalize Property conversion between C++ and Python
* adapt API: MoveRelative::setGoal -> setDirection
* python wrappers for new functionality since last merge
* Merge branch 'master' into boost-python
* MoveRelative: possibly update last waypoint before transform lookup
  Apparently this RobotState is not necessarily updated,
  this broke some pipeline testing over here.
* add comment to subtrajectory
* add comments to wrapped solutions
* do not send failures to parent
  It is enough for us to investigate these locally
* do not pass failures on to monitors
  They should not work with them and this
  removes the need for the usual `if(s.isFailure) return`.
* fixup! rename "goal" to "direction"
* remove dummy file
* Merge branches 'cleanup-planner-interface', 'connect', 'fix-visualization' and 'rviz-createMarker' into master
* fixup! add name to Connecting DEBUG output
  This is important to differentiate between different Connect stages.
* fixup! rename "goal" to "direction"
  "Goal" implies a motion to a target configuration.
  MoveRelative explicitly does not do that.
  "Direction" is usually not used for rotations,
  but perfectly valid to describe them.
  I merged 544f57416694fb45cc5bb02bde4c3ac34d57bbc3
  together with the first version of this rename
  that got force-pushed because it was incomplete.
* fixup! add properties for conditional debug output
  in MoveIt planner.
  These can be quite helpful.
  I agree, we really don't need them enabled by default.
* Connect: skip initial PlanningScene::diff()
* cleanup PlannerInterface
  - remove group + timeout properties: they are passed as arguments to plan()
  - move max_velocity_scaling_factor, max_acceleration_scaling_factor to PlannerInterface base class
* Introspection::solutionFromId()
* Connect: verbose debugging output in case of state incompatibilities
* Connect: allow different merge modes
  for now:
  SEQUENTIAL (no merging)
  WAYPOINTS (naive)
* Merge pull request `#54 <https://github.com/JafarAbdi/moveit_task_constructor/issues/54>`_ from ros-planning/pr-capability
  ExecuteTaskSolution capability
* fix stage "FixCollisionObjects"
  ... correction wasn't initialized to zero, resulting in random NaNs
* update PlanningScene's RobotState before storing it
* fix caching of PlanningPipeline ptrs
  Need to reset cache if corresponding RobotModel was destroyed.
  To this end, we cannot simply use the RobotModel's name.
* PipelinePlanner: disable publishing of plan request + computed path
* reduce copying of shared ptrs
* guard use of introspection\_ pointer
* pick_pa10: fix initialization of RobotState
  only a subset of joints was initialized
* fix destruction order
* generalize Property conversion between C++ and Python
  register appropriate converters for boost::any
* replace MessageSignature with simple ros-msg-name string
* better robustness against already registered boost::python type converters
* RosMsgConverter: do not allow custom message name
* ROSMsgConverter -> RosMsgConverter
* cleanup type conversion
* protect fromPython / toPython
* fix compiler warnings
* keep RobotModelLoader around
  Otherwise the robot_model\_ does not remain valid
* fix compiler warnings in release mode
* fixes for Bionic
  boost::python 1.65 is more picky about exactly returning the placeholder type in __init_\_ functions.
* fix API to match MoveTo / MoveRelative stages
* allow PoseStamped as property
* pass verbose InitStageException from C++ to python
  reverts df43ba1d68bb5c628a8e8f13729e7cdda872f1f9
* Solution.toMsg()
* expose MonitoringGenerator's setMonitoringStage()
* Task::init(): verbose exception output
* Properties: exposeTo(), configureInitFrom()
* moved python includes to global include folder too
  catkin package expects all includes to be in one global location
* import .core by default
* add reference test for properties
* merge fixes
* fix compiler warnings
* fix tests
* fixup! allow preemption of Task::plan()
* Task::execute()
* allow preemption of Task::plan()
* FixCollisions stage
* PlannerInterface for joint-space interpolation
* ComputeIK: forward child solution's comment
* fixup! MoveTo: store goal as any type
* fix compiler warnings
* fix include order
  Local headers should be preferred over those from underlay.
  Consequently use target_include_directories() to properly define include order.
* Merge branch master into boost-python
* expose solutions, publish + execute
* remove redundant exposure of smart pointers
* cleanup Property access
* cleanup
* PropertyMap iterator, PropertyMap.update(dict)
* unit tests for all stages
* overload constructors
* container wrappers
* add ROS unittest
* roscpp_init: provide init_options AnonymousName, NoRosout
* more wrappers, unittest, fixes
* register ROS msg types with boost::python's type converters
* handle std::unique_ptr<Stage>
  Class holder needs to be a smart pointer, e.g. std::auto_ptr.
  This can be released(), such that ownership can be passed.
  Further, derived types need to be declared as implicitly_convertible to base type.
* cleanup, unittest for properties
* separate .core and .stages modules
* local names for python wrapper libs
* cleanup folder structure
* solvers + stages
* Properties
* basic boost::python wrappers
* pa10 doesn't need move_group
* cast demos as integration unit tests
  - moved demos from demo to test folder
  - run them as unittest, checking range of solutions
* Merge branches 'move-to', 'simple-grasp' and 'properties' into master
  These branches only work together:
  - MoveTo / MoveRelative: common handling of "goal" property
  - properties: required changes to allow for multiple inheritance
  - generalize SimpleGrasp / GenerateGraspPose
* remove Container::exposePropertiesOfChild()
* generalize SimpleGrasp / GenerateGraspPose
  - move "pregrasp", "grasp" property from SimpleGrasp to GenerateGraspPose
  - Container::exposePropertiesOfChild: decouple exposure from inheritance
* MoveRelative: store goal as any type
* MoveTo: store goal as any type
* exposeTo: const method
* PropertyMap: allow any type
* Container::exposePropertiesOfChild: allow skipping of undefined props
* Stage: generally allow forwarding of interface properties
* SimpleGrasp(GraspGenerator)
  allow any GraspGenerator stage that provides "pregrasp" and "grasp"
  postures as well as a target_pose for grasping.
* improve property debugging
* property inheritance: both from PARENT and INTERFACE
  - source_id -> source_flags: bits indicating configured paths
  - initializers, e.g. fromName(), should throw
  - ignore undeclared errors during inheritance
  - on undefined error, reset the value to None
  - override value only if previously set by lower-priority source
  MANUAL > CURRENT > PARENT > INTERFACE
* reuse boost::any's type_index type
* fix: don't report config issues as successful (but empty) solutions
* compatibility with boost 1.54
  This is required for ROS indigo on ubuntu 14.04
* use correct frame in pick (`#52 <https://github.com/JafarAbdi/moveit_task_constructor/issues/52>`_)
* compute ik: ignore collisions skips early eef check
* Rewrite and relax approx comparisons
  This is more readable.
  Adjusting the threshold to 1e-4 is required to allow for tolerances
  in potential sampling planner steps in between.
* add max_solutions param to plan()
  For big problems you just don't want *all* solutions
* minor formatting changes (`#51 <https://github.com/JafarAbdi/moveit_task_constructor/issues/51>`_)
* validate merged trajectories
* declare properties "timeout", "marker_ns" for all stages
* rework storing of solutions
  - solutions\_, failures\_ as SolutionBaseConstPtrs in StagePrivate
  - replace processSolutions() / processFailures() by direct const-access to storage containers
  - generic sendForward(), sendBackward(), spawn(), connect() methods in StagePrivate
  - reuse StagePrivate's sendForward(), sendBackward(), spawn() in containers
  - store created InterfaceStates in StagePrivate::states\_
  - Interface: ordered<InterfaceState*> (only store pointers)
  allows for common handling of states of valid and failure solutions
  - remove additional state+solution storages
  - containers: internal->external state mapping as InterfaceState* -> InterfaceState*
* remove void line
  ?
* correctly reset FixedState
* simplify compute() API
  - remove bool return value
  - always create a solution trajectory, also in case of failures
  - success/failure determined from solution.isFailure()
  minor adjustments during cherry-pick
* SolutionBase: rename 'name' to 'comment'
* MoveTo/MoveRelative: generic IK target frame
  ...instead of simple link name
* Merge branches 'joint_pose', 'move-relative-joints', 'basic-merger' and 'compute-ik'
* MoveRel: handle unknown links with hard failure
* MoveTo: cleaner strict handling of invalid properties
* MoveTo: reduce scope of try-catch
* MoveTo: simplify getJointStateGoal
* basic merger functionality
* ignore failures for further processing
* forward properties
* ComputeIK: report collision pairs
* remove std::map serialization
* cleanup
* Pick: added setter for relative joint lift motion
* MoveRelative: added relative joint space goals to
* added stream serialization for std::map<std::string, T>
* moved implementations of property setters to header
* cleanup
  - indentation: space -> tabs
  - only consider joints of JMG
* adapted MoveTo api change. joint_pose -> named_joint_pose
* MoveTo: converting named joint poses to robot state msg in init; property names refactoring
* MoveTo: can now take RobotState msg as goal
* Task: only accept containers
* Property: silently return empty string when serialization is not supported
* Property: provide a fallback serialize() implementation
  ... in case operator<< is not defined for type T
* get rid off empty JointState errors
* add timing to merged trajectories
* unittest for Priority comparisons
* update ordering on any change of priority
* move implementation into cpp file
* inf cost states always go last
  Also update sorted interface when state becomes inf or get's new cost.
* Merge branches 'travis', 'fixes', 'visualization' and 'todos'
* relax equality condition for joint values for inactive groups
* consider v4hn's comment
* only attempt to merge if there is something to merge
* more todo
* feedback
* list of random todos
* minor improvements: variable names, comments
* fix MoveRelative
  Ignore success of planner\_->plan() when min_distance is specified (and >= 0).
  In this case, compute the achieved distance myself.
* std::string -> const std::string&
* rename enableCollision -> allowCollision
* renamed demo: plan_pick_trixi -> plan_pick_pr2
* removed old stages: Move, Gripper, CartesianPositionMotion
* fix trajectory merging: initialize from well-defined RobotState
* SolutionSequence::fillMessage: ignore sub solutions with same creator as parent
* Merge branches 'robot-model', 'task-move-constructor' and 'const-robot-trajectory'
* SubTrajectory: promise to not modify encapsulated RobotTrajectory
* move assignment operator
* Task: move constructor
* enable introspection only if ROS was initialized
* Task::setRobotModel() / Task::loadRobotModel()
* Merge branches 'master' 'generate-pose' and 'connect'
* publish failures
* report duplicate joints, accept fixed joints as duplicates
* merge trajectories
* utility functions to merge multiple RobotTrajectories
* Pick, Place as specializations of PickPlaceBase
* SimpleGrasp, SimpleUnGrasp as specializations of SimpleGraspBase
* Pick: remove Connect
* Connecting::compatible() to check compatibility of states
* MoveTo: use moving frame markers
* expose typed setters in Cartesian solver
* Connect: allow multiple groups to be processed in series
* setCreator() once in StagePrivate::newSolution()
* SerialSolution -> SolutionSequence
* validate existence of object frame in init()
* derive GenerateGraspPose from GeneratePose
* postpone pose transformation
* add missing reset()
* add a simple GeneratePose stage
  ComputeIK is a wrapper, so we can't just give it a pose to compute.
* fix PropertyMap::exposeTo: use other_name as new name for property (`#40 <https://github.com/JafarAbdi/moveit_task_constructor/issues/40>`_)
* MoveRelative: adapt msgs to fit class name (`#39 <https://github.com/JafarAbdi/moveit_task_constructor/issues/39>`_)
* Merge pull request `#28 <https://github.com/JafarAbdi/moveit_task_constructor/issues/28>`_ from ros-planning/pr-path-constraints
  implement path constraints
* actually implement path constraints for CartesianPath planner
  ... validating constraints
* implement path constraints for Move*
* expose timeout property as typed setter
* add path constraints to planner API
  and use it in the Connect class.
  The cartesian planner ignores the constraints for now.
* ContainerBasePrivate::position() -> childByIndex()
* ContainerBasePrivate::position(): generically handle shifting
* remove tool_to_grasp_tf from SimpleGrasp
* remove tool_to_grasp_tf from GenerateGraspPose
* added disclaimer
* fix isTargetPoseColliding
  - must not use new sandbox_scene (we want to display the place eef)
  - jmg not needed anymore
* frame marker at ik frame
* rename reference frame -> ik frame
* consider reference_frame
* allow arbitrary reference frame for target_pose and ik frame
* remove tests that do not test anything
* unittests
  - provide simple hard-coded robot model
  - test ComputeIK::init()
* validate available properties during init()
* Merge branches 'bug-fixes', 'gui' and 'pick-stage'
* MoveTo Cartesian: create marker frame at current and goal pose
* CartesianPath: return a partial trajectory in case of failure
* cosmetic fixes
* pick: expose IK link frame as eef_frame
* expose solvers
* moved "attach object" from "pick" to "grasp" stage
* position scene node w.r.t. fixed frame
* fixup! SerialContainer: don't consider failures for solutions
* fix ContainerBasePrivate::copyState(): don't copy (again) on update
* reset num_failures\_
* MoveTo Cartesian Point: bug fix
* fix interface detection for nested SerialContainers
* fix SerialContainer::canCompute()
* pick: reusable stage for picking up an object
* Merge branch 'parallel-container'
* GenerateGraspPose::reset()
* SerialContainer: don't consider failures for solutions
* fix ParallelContainers' init()
* relax ParallelContainer's validateConnectivity()
* implement ParallelContainer's pruneInterface()
* ParallelContainer's requiredInterface()
* ParallelContainer: unittests
* more constexpr InterfaceFlags
* Merge branches 'analyze-property-errors' and 'fixes'
* fixup! PropertyMap: different exception types
* add catch-rethrow for property initialization
  The property doesn't know its own name, so we add it here
* add convenience overloads for setting properties
* ContainerBase::exposePropertiesOfChild
* properties: init from source if current value is not defined
  - reset(): reset current value to empty, not default
  - value(): return current value, or - if not defined - the default
  - initialize from source if current value is undefined,
  don't care about default value
* declare by std::type_index (instead of std::type_info)
* Stage::reportPropertyError
* PropertyMap: different exception types
  undeclared
  undefined
  type_error
* elaborate runtime_error in InterfaceState
* ComputeIK: update state to avoid dirty transforms
* InitStageException::what(): distinguish stage/stages
* become agnostic to urdfdom's shared_ptr types
* conditionally normalize angular
* fix derivation of propagation direction from connect stage
* fix ModifyPlanningScene: pass stage properties to callback
* GenerateGraspPose: require pregrasp pose
* unittest ContainerBasePrivate::position()
* Stage::init(PlanningScene) -> Stage::init(RobotModel)
* remove restriction to watch only generators
* MonitoringGenerator
* FixedState generator
* CurrentState: fetch scene via get_planning_scene service
* add missing headers
* Merge branches 'fix-containers' and 'fix-priority-updates'
* fixed remaining unittest
* avoid accidental overwrite of InterfaceState
* update priorities of all interface states along a (partial) solution path
  if a parallel container is involved somewhere in the middle, it will
  again access these states, e.g. planning alternative solutions
* reset InterfaceState::owner\_ if state is removed from Interface
* recursive interface auto-detection
  trigger auto-detection from top (task) level:
  only there we now for sure the accepted interface
* improve validation
  - postpone pruning / interface auto-detection to top task-level
  only the task state knows for sure, that it requires its wrapped child to push to both ends
  - perform connectivity validation only after pruning
  only then, we the interfaces are completely determined
* basic auto-detection of interfaces for propagating stages
  works if propagation direction can be derived from a generator or
  connecting stage within the sequence
  start-to-end propagation through whole serial container still fails
* fix connection creation
  Establishing the interface connections, we face a chicken-egg-problem:
  To establish a connection, a predecessors/successors pull interface is
  assigned to the current's stage push interface.
  However, propagating stages (in auto-detection mode) can only create
  their pull interfaces if the corresponding, opposite-side push interface
  is present already (because that's the mechanism to determine the supported
  propagation directions).
  Hence, we need to resolve this by performing two sweeps:
  - initialization, assuming both propagation directions should be supported,
  thus generating both pull interfaces, i.e. providing the egg
  - stripping down the interfaces to the actual context
  This context is provided by two stages pushing from both ends
  into a (potentially long) sequence of propagating stages (tbd).
  Contributions of this PR:
  - PropagatingEitherWay: explicitly distinguish AUTO from BOTHWAYS interface
  AUTO: auto-derive interface from provided push interfaces
  BOTHWAYS: explicitly require both directions
  - SerialContainer: (better, but not yet perfect) validation of connectivity
  - ParallelContainer: determine interface from what children offer
* extended unittest for serial connection validation
* cleanup operator<<(ostream, *)
  - basic implementation for StagePrivate
  - implementation for Stage calls this
  - implementation for ContainerBase recursively calls this
  - implementation for Task added
* PropagatingEitherWayPrivate: count failures in both directions
* replace std::cout with ros console
* SerialContainer: fix priority propagation
  - traverse all (also partial) solution paths
  - and update priority at both ends
  - remove pending state pairs if cost increased to infinity
* MoveRelative: fix marker arrow
* cleanup ComputeIK
  - correctly check collision for target pose before doing IK
  - visualize failed collision check / failed IK
* GenerateGraspPose: marker cleanup
  - remove arrow marker (approach direction isn't hard-coded anymore)
  - consider all rigidly attached parent links for display
  - add grasp frame
* GenerateGraspPose: correctly check for existence of link frames
* marker tools: allow vector of LinkModel*
* MoveRelative: allow zero min_distance
* example: twist motion
* local planning scene
* example using new features
* cmake cleanup: group source files
* Merge branches 'cleanup', 'wip-modular-planning', 'wip-containers', 'wip-gui' and 'wip-modify-ps'
* modular planning
  Separate planning approaches (using MoveIt pipeline or computeCartesianPath) from stages.
  This allows to reuse planning in various stages without code duplication.
  Reworked stages:
  Move -> Connect
  Gripper + CartesianPositionMotion -> MoveTo
  CartesianPositionMotion -> MoveRelative
* visualize collisions
* FixCollisionObjects stage
* reduce code bloat using SFINAE template selection
* ModifyPlanningScene stage
  - attach / detach objects to robot
  - enable / disable collision pairs
  - works in either direction (FORWARD +  BACKWARD)
* merge WrapperBase + Wrapper into WrapperBase
  Wrapper is not restricted to generator-type stage anymore.
* derive WrapperBase from ParallelContainerBase
* ContainerBasePrivate::liftSolution()
* implement ParallelContainerBase
* improved directional (forward/backward) access to interfaces
  - TraverseDirection -> Interface::Direction
  - StagePrivate: pullInterface(), pushInterface()
  - trajectories<dir>(SolutionBase) -> SolutionBase::trajectories<dir>()
* simplify usage of ContainerBasePrivate::copyState()
* exploit default argument for Interface constructor
* unify use of buffer interfaces in containers
  All containers need to buffer their children's sendBackward/sendForward states.
* expose Task::initScene()
  ... to allow use of local scene
* default arg in header
* Merge branches 'fix-remote-task-model', 'wip-cost-ordering' and 'wip-properties'
* serialize stage properties
* signal callback function
  ... to allow for syncing with rviz::Property
* allow only a single inititialization source
* update state priorities in a container-specific fashion
  Reorder interface list on priority updates.
  This requires the InterfaceState to store a pointer to the owning Interface.
* Interface: order states by priority
  Priority is (depth of solutions, accumulated cost along trace).
* single map internal_to_external
  There is no need to distinguish between starts and ends when mapping
  states, because start/end states need to be disjoint sets.
* SerialContainer: traverse solutions w/o stopping stage
  Always traverse from current solution to the start/end of a complete
  path and only call the callback once for the whole trace.
* default argument for NotifyFunction in Interface constructor
* sort serial solutions before insertion
* cost ordering for solutions
* cost ordered API
* fixed some clang warnings
* count all failures for statistics
* example setting solution markers
* allow handling of failures
  - store "failure" solutions to facilitate debugging
  - Introspection assigns solution IDs as soon as they are created in a stage
  Thus, solution IDs represent their creation order.
  In contrast, the order of publishing (in StageStatistics) should
  represent the cost order.
  - Storing failures is disabled if Introspection is not available.
* Wrapper::compute: return true if new solutions are found
* ComputeBase::addTrajectory -> ComputeBasePrivate::addTrajectory
  Forbid indirect access to trajectories\_.
  Only official compute classes have access.
* Merge branches 'fixes', 'wip-drag-n-drop', 'wip-ikstage' and 'wip-marker-vis'
  resolved conflicts:
  core/include/moveit/task_constructor/container.h
  core/src/container.cpp
  core/src/stages/generate_grasp_pose.cpp
  visualization/motion_planning_tasks/src/task_display.cpp
  visualization/motion_planning_tasks/src/task_panel_p.h
* more exported stage plugins: CurrentState
* collision test for ee group
* fix IK stage: insert different solutions as different scenes
* better names for frame and transform variables
* renamed GenerateGraspPose::setGraspFrame() to setToolToGraspTF()
* implement IK as separate stage
  ... wrapping another stage
* derive WrapperBase from ContainerBase
  While ParallelContainers can directly promote their child solutions as
  their own, a Wrapper needs to modify those solutions. Hence, Wrappers
  should be derived directly from Container.
* removed Stage::validate()
  ... only was checking for implies(a, a) which is always true
* promise to not modify solutions
* introducing process_id
  The task id was not unique enough to distinguish different tasks.
  When a task publisher is killed and restarted, it usually comes up with
  the same task id. However, visualization doesn't notice this change and
  get confused / crashes when receiving task statistics and solutions.
* marker_tools
* allow stages to access the created SubTrajectory
  to add markers, set name, etc.
* Merge branch 'wip-properties'
* more unit tests
* cleanup error handling
  throw std::logic_error on type errors
  throw std::runtime_error on undeclared property
  don't expose generic PropertyMap::declare()
* fix initialization order of properties
  First from INTERFACE, second from PARENT.
  INTERFACE initialization only makes sense for Propagating stages.
  Connecting stages should ensure that interfaces define identical
  properties which is not possible with boost::any.
* definition of PropertyInitializerSource moved to Stage
* generalize initialization source from enum to int
* separate setValue() and setCurrentValue()
  setValue() also updates the default value.
  reset() reset to the default value.
  setCurrentValue() only updates the current value, keeping current default.
  Thus setCurrentValue() can be reverted (to default) using reset().
* remove property name from InitializerFunction's signature
* initFrom() -> configureInitFrom() + performInitFrom()
  Use different function names for different semantics.
* countDefined(): count number of defined properties
* generalize GenerateGraspPose
  replacing scalar graspOffset and hard-coded Euler angles with arbitrary graspFrame
* ur5 example: use properties
* PropertyMap
* add full license information
  so dull... but for the matter of completeness
* reduce catkin_lint complains in core
* DisplaySolution: struct to unify all data corresponding to a sub trajectory
* Merge branch 'wip-visualization' into wip-refactor
* cmake compatbility to 2.8.12
* navigate solutions
* don't export SerialContainer as pluginlib class
  ... it's imported as builtin
* Introspection: start solution id at index 1
  ... allowing 0 to have special meaning "invalid"
* Introspection: helper fillSolution() adding task_id
* travis config + fixes
* Merge remote-tracking branch 'origin/master' into wip-refactor
  - cmake 3.1 required for CMAKE_CXX_STANDARD
  - more old-style signal/slots for Qt4 compatibility
* removed statistics from task description
  - make TaskStatistics a latched topic too
  - subscribing to topics in order (1. description, 2. statistics, 3. solution)
  should ensure that we receive those latched messages in this order
* receive task solutions
  - remove parent_id from StageStatistics message
* cleanup TODO
* split repo into different ROS packages: msgs, core, visualization
* Contributors: AndyZe, Aris Synodinos, Captain Yoshi, Christian Petersmeier, Henning Kayser, Jafar, Jafar Abdi, JafarAbdi, Jochen Sprickerhof, Mark Moll, Markus Vieth, Martin Meier, Michael Görner, Niklas Fiedler, Robert Haschke, Tyler Weaver, Wyatt Rees, cpetersmeier, eirtech, j-kuehn, janEbert, llach, v4hn
