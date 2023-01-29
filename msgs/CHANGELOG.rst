^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_task_constructor_msgs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.1.0 (2023-01-29)
------------------
* Fix cmake indentation
* Alphabetize package.xml's and CMakeLists
* ROS 2 Migration (`#170 <https://github.com/JafarAbdi/moveit_task_constructor/issues/170>`_)
* Port msgs to ROS2
* Merge branch 'master' into wip-python-api
* Modernize: require cmake version 3.1.3
* Merge branch 'master' into wip-python-api
* Merge PR `#214 <https://github.com/JafarAbdi/moveit_task_constructor/issues/214>`_ (fix various issues) and `#215 <https://github.com/JafarAbdi/moveit_task_constructor/issues/215>`_ (rework rviz introspection)
* Rename process_id -> task_id
* Rename TaskPrivate::id -> TaskPrivate::ns
  TaskPrivate's id\_ actually served as a namespace parameter.
* Merge branch master into wip-python-api
* document axiom in StageStatistics.solved
  If the axiom is violated, sorting in the rviz panel will fail.
* bump cmake version
  get rid of CMP0048 warning.
* Merge `#120 <https://github.com/JafarAbdi/moveit_task_constructor/issues/120>`_: Add computation timing
* transmit and display computation in rviz
* Merge branch master into wip-python-api
* Introduce clang-format (`#102 <https://github.com/JafarAbdi/moveit_task_constructor/issues/102>`_)
  * fix catkin_lint issues
  * introduce clang-format config and apply it
* rework solution msgs
  - to allow solution wrappers (WrappedSolution, SolutionSequence)
  to transmit their comment and markers as well
  - introduced new SolutionInfo.msg,
  which is the info common to solution wrappers and actual SubTrajectories
* Merge PR `#72 <https://github.com/JafarAbdi/moveit_task_constructor/issues/72>`_: rviz property visualization
* PropertyTypeRegistry to store serialization/deserialization functions
* Merge branch 'master' into boost-python
* Merge pull request `#54 <https://github.com/JafarAbdi/moveit_task_constructor/issues/54>`_ from ros-planning/pr-capability
  ExecuteTaskSolution capability
* modified ExecuteTaskSolution.action
* a move_group capability to execute Task Solutions
  This does not work perfectly yet in practice,
  but this is (probably) due to problems in upstream MoveIt.
* SolutionBase: rename 'name' to 'comment'
* Merge branches 'fix-remote-task-model', 'wip-cost-ordering' and 'wip-properties'
* serialize stage properties
* count all failures for statistics
* introducing process_id
  The task id was not unique enough to distinguish different tasks.
  When a task publisher is killed and restarted, it usually comes up with
  the same task id. However, visualization doesn't notice this change and
  get confused / crashes when receiving task statistics and solutions.
* reduce catkin_lint complains in core
* DisplaySolution: struct to unify all data corresponding to a sub trajectory
* cmake compatbility to 2.8.12
* add myself as maintainer & travis recipient
* removed statistics from task description
  - make TaskStatistics a latched topic too
  - subscribing to topics in order (1. description, 2. statistics, 3. solution)
  should ensure that we receive those latched messages in this order
* receive task solutions
  - remove parent_id from StageStatistics message
* split repo into different ROS packages: msgs, core, visualization
* Contributors: AndyZe, Henning Kayser, Jafar Abdi, JafarAbdi, Michael Görner, Robert Haschke, v4hn
