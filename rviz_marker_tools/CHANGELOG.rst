^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package rviz_marker_tools
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.1.0 (2023-01-29)
------------------
* Add missing dependency (`#417 <https://github.com/JafarAbdi/moveit_task_constructor/issues/417>`_)
  Fixup for b54f53e
* Rely on CXXFLAGS definition from moveit_common package
* Fix cmake indentation
* Merge CI fixes/improvements
* Use catkin_INCLUDE_DIRS as system includes
  ... to suppress warnings outside the code base
* Do not dictate C++ standard
  C++14 is default in clang/gcc anyway and latest log4cxx requires C++17.
  Qt on Ubuntu 18.04 sets C++11. Hence we use MoveIt's cmake macro to ensure C++14 at least.
* Fix Eigen build issues on some platforms (`#362 <https://github.com/JafarAbdi/moveit_task_constructor/issues/362>`_)
* Alphabetize package.xml's and CMakeLists
* rviz_marker_tools: Fix dependencies
* Merge branch 'master' into wip-python-api
* ROS 2 Migration (`#170 <https://github.com/JafarAbdi/moveit_task_constructor/issues/170>`_)
* Port rviz_marker_tools to ROS2
* move to tf2_eigen everywhere (`#301 <https://github.com/JafarAbdi/moveit_task_constructor/issues/301>`_)
* Merge branch 'master' into wip-python-api
* Improve arrow visualization for MoveRelative stage (`#255 <https://github.com/JafarAbdi/moveit_task_constructor/issues/255>`_)
  Implement visualization as red-green arrow
  * overload makeArrow to allow creation with points
  * create new function for visualization
  * if no plan is found, construct arrow from green cylinder and red arrow
  * adjust arrow construction for backward propagators
* Modernize: require cmake version 3.1.3
* Merge branch master into wip-python-api
* bump cmake version
  get rid of CMP0048 warning.
* Merge branch master into wip-python-api
* Introduce clang-format (`#102 <https://github.com/JafarAbdi/moveit_task_constructor/issues/102>`_)
  * fix catkin_lint issues
  * introduce clang-format config and apply it
* Merge branches 'fix-interface-deduction' (`#84 <https://github.com/JafarAbdi/moveit_task_constructor/issues/84>`_), 'compute-ik-default-timeout' (`#80 <https://github.com/JafarAbdi/moveit_task_constructor/issues/80>`_),
  'fix-visualization' (`#76 <https://github.com/JafarAbdi/moveit_task_constructor/issues/76>`_), and master-improvements (`#81 <https://github.com/JafarAbdi/moveit_task_constructor/issues/81>`_)
* simplify/fix color interpolation
* Eigen::Affine3 -> Eigen::Isometry3
* Merge branch 'master' into boost-python
* fix cylinder markers
  rviz' Marker expects scale.x/y to be diameter instead of radius
* Merge branches 'fixes', 'wip-drag-n-drop', 'wip-ikstage' and 'wip-marker-vis'
  resolved conflicts:
  core/include/moveit/task_constructor/container.h
  core/src/container.cpp
  core/src/stages/generate_grasp_pose.cpp
  visualization/motion_planning_tasks/src/task_display.cpp
  visualization/motion_planning_tasks/src/task_panel_p.h
* rviz marker tools
* Contributors: AndyZe, Henning Kayser, JafarAbdi, Jochen Sprickerhof, Michael Görner, Robert Haschke, j-kuehn, v4hn
