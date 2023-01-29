^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_task_constructor_capabilities
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.1.0 (2023-01-29)
------------------
* Rely on CXXFLAGS definition from moveit_common package
* Check for moveit::core::MoveItErrorCode::toString
* Fix syntax error
* Fix compiler warnings
* Merge CI fixes/improvements
* Use catkin_INCLUDE_DIRS as system includes
  ... to suppress warnings outside the code base
* Remove MoveIt compatibility code
* Do not dictate C++ standard
  C++14 is default in clang/gcc anyway and latest log4cxx requires C++17.
  Qt on Ubuntu 18.04 sets C++11. Hence we use MoveIt's cmake macro to ensure C++14 at least.
* Alphabetize package.xml's and CMakeLists
* Merge branch 'master' into wip-python-api
* execute_task_solution_capability: check for canceling request before canceling the goal handle (`#321 <https://github.com/JafarAbdi/moveit_task_constructor/issues/321>`_)
* ROS 2 Migration (`#170 <https://github.com/JafarAbdi/moveit_task_constructor/issues/170>`_)
* Port capabilities to ROS2
* remove dirty MOVEIT_MASTER-check
  ... in favor of checking version numbers.
  Checking for one header was used for multiple independent things.
  In theory we could do exact feature testing instead of using the next release number,
  but in practice nobody cares about the individual commits between older releases.
* Merge branch 'master' into wip-python-api
* Merge pull request `#261 <https://github.com/JafarAbdi/moveit_task_constructor/issues/261>`_ from ubi-agni/GHA
  Switch to GitHub actions
* Fix catkin_lint errors
* Modernize: require cmake version 3.1.3
* Merge branch master into wip-python-api
* clang-tidy: llvm-namespace-comment
* clang-format: readability-container-size-empty
* clang-tidy: readability-named-parameters
* clang-tidy: modernize-use-override
* bump cmake version
  get rid of CMP0048 warning.
* Revert "workaround for MoveIt PlanningScene bug"
  Fixed via https://github.com/ros-planning/moveit/pull/1899.
  Please use *latest* master (if you do not use melodic builds).
  This reverts commit c44d0cac19ae96c042e262350419f91c77a80eb5.
* workaround for MoveIt PlanningScene bug
  https://github.com/ros-planning/moveit/issues/1835
* Added C++11 flags for MOVEIT_MASTER check (`#129 <https://github.com/JafarAbdi/moveit_task_constructor/issues/129>`_)
* Fixup: avoid deprecation warnings of MoveIt master branch
  Fixes missing definition of MOVEIT_MASTER for capabilities packages
  in 233d63aa7aa3f06b687442b8fe8ece695d41132f
* shorten description of trajectory component
  info's id and stage_id are not always filled
* Merge branch master into wip-python-api
* avoid deprecation warnings of MoveIt master branch
  Use new methods
  - moveit::core::isEmpty
  - moveit::core::CartesianInterpolator::computeCartesianPath
* Merge branch master into wip-python-api
* Introduce clang-format (`#102 <https://github.com/JafarAbdi/moveit_task_constructor/issues/102>`_)
  * fix catkin_lint issues
  * introduce clang-format config and apply it
* rework solution msgs
  - to allow solution wrappers (WrappedSolution, SolutionSequence)
  to transmit their comment and markers as well
  - introduced new SolutionInfo.msg,
  which is the info common to solution wrappers and actual SubTrajectories
* Merge branch 'master' into boost-python
* Merge pull request `#54 <https://github.com/JafarAbdi/moveit_task_constructor/issues/54>`_ from ros-planning/pr-capability
  ExecuteTaskSolution capability
* fixup! a move_group capability to execute Task Solutions
* fix determination of JMG
* modified ExecuteTaskSolution.action
* execute: apply effects through the PSM
  We can bypass it too, but things are a bit cleaner this way.
* add effect description as debug output
* a move_group capability to execute Task Solutions
  This does not work perfectly yet in practice,
  but this is (probably) due to problems in upstream MoveIt.
* Contributors: AndyZe, Aris Synodinos, Henning Kayser, Jafar Abdi, JafarAbdi, Michael Görner, Robert Haschke, v4hn
