^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_task_constructor_demo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.1.0 (2023-01-29)
------------------
* Update demo's version to match other packages
* Rely on CXXFLAGS definition from moveit_common package
* Merge branch 'master' into ros2
* Replace rosparam_shortcuts with generate_parameter_library (`#403 <https://github.com/JafarAbdi/moveit_task_constructor/issues/403>`_)
* Merge PR `#99 <https://github.com/JafarAbdi/moveit_task_constructor/issues/99>`_: Python API
  ... based on pybind11
* Merge branch master into ros2
* Fix cmake indentation
* Merge CI fixes/improvements
* Use catkin_INCLUDE_DIRS as system includes
  ... to suppress warnings outside the code base
* Remove MoveIt compatibility code
* Do not dictate C++ standard
  C++14 is default in clang/gcc anyway and latest log4cxx requires C++17.
  Qt on Ubuntu 18.04 sets C++11. Hence we use MoveIt's cmake macro to ensure C++14 at least.
* fixup! demo: add example cartesian.py
* Remove macros to check supported features
* Merge https://github.com/ros-planning/moveit/commit/d2918f130d5bbcd7a788d1dc86c32a6c487ca70f
* Use moveit_configs_utils for launch files (`#365 <https://github.com/JafarAbdi/moveit_task_constructor/issues/365>`_)
* Fix parameter in ik_clearance_cost demo (`#366 <https://github.com/JafarAbdi/moveit_task_constructor/issues/366>`_)
* Alphabetize package.xml's and CMakeLists
* Use verbose delimiters for source code instead of line numbers
* Add example script: properties
* Pick+Place: Correctly configure forwarding of "pregrasp" property
  ... from Grasp to UnGrasp stage
* GeneratePlacePose: Remove property "ik_frame" from stage
  - Instead, set ik_frame property on solution from passed object (frame).
  - Allow subframes to be used as "object" frames
* Cleanup pickplace.py
* Fix ComputeIK demo
* Fix demo/scripts/fixed_state.py
* mwe examples for core classes
* add further examples for basic stages
  - create more granular mwe examples as reference material
  in the documentation
* stages docs and bindings
  - pybind bindings for all the examples
  - correctly format docstrings
* add demo pickplace example script
* Merge branch 'master' into wip-python-api
* Merge PR `#309 <https://github.com/JafarAbdi/moveit_task_constructor/issues/309>`_: Fix Pruning
* Merge PR `#311 <https://github.com/JafarAbdi/moveit_task_constructor/issues/311>`_: fix Fallbacks
* Return MoveItErrorCode from task::plan (`#319 <https://github.com/JafarAbdi/moveit_task_constructor/issues/319>`_)
  ... to know whether the plan failed due to timeout, preemption, or actual planning failure
* ROS 2 Migration (`#170 <https://github.com/JafarAbdi/moveit_task_constructor/issues/170>`_)
* Port demo to ROS2
* add demo illustrating useful fallbacks behavior
* Simplify allowCollisions(object, JMG)
* Gracefully handle execution_type (`#307 <https://github.com/JafarAbdi/moveit_task_constructor/issues/307>`_)
  In moveit_resources 0.8.1 the arg execution_type was renamed to fake_execution_type.
  To support both, Melodic and Noetic versions of moveit_resources, provide both name variants.
  Additionally, disable  roslaunch's checking via pass_all_args="true".
* simplify test specification
  before anyone starts copying from here...
* demos: improve CMakeLists
  - build pick_place_task as proper library as people (e.g. moveit_benchmark_suite) reuse it
* Merge branch 'master' into wip-python-api
* CI: fixup asan job
  Need to preload libasan.so.5 for move_group node, because it loads a sanitized plugin.
* Run pick+place demo as a unit test (`#254 <https://github.com/JafarAbdi/moveit_task_constructor/issues/254>`_)
* Merge branch 'master' into wip-python-api
* Merge pull request `#261 <https://github.com/JafarAbdi/moveit_task_constructor/issues/261>`_ from ubi-agni/GHA
  Switch to GitHub actions
* Fix catkin_lint errors
* auto-format python code with black
* Perform clang-format check via github action from pre-commit.com
* add two demos for cost computation aspects
* simplify demo startup launch
  There's no need to copy the whole demo.launch from the panda config.
* demo: switch to moveit_resources_panda_moveit_config (`#231 <https://github.com/JafarAbdi/moveit_task_constructor/issues/231>`_)
* Modernize: require cmake version 3.1.3
* Merge branch master into wip-python-api
* Fix pick-place-demo: Correctly set hand group (`#205 <https://github.com/JafarAbdi/moveit_task_constructor/issues/205>`_)
* clang-tidy: llvm-namespace-comment
* clang-format: readability-identifier-naming
  Probably the most invasive format patch, also changing some internal API.
  I deliberately disabled ClassCase and MethodCase checks for the moment
  to avoid public API changes in this patch set.
* Remove accidentally committed files
* Merge `#156 <https://github.com/JafarAbdi/moveit_task_constructor/issues/156>`_: Rework interface resolution
* cleanup / renaming
  * Rename pruneInterface() -> resolveInterface()
  * Rename accepted (interface) -> expected
  * Improve exception strings
* bump cmake version
  get rid of CMP0048 warning.
* Merge pull request `#151 <https://github.com/JafarAbdi/moveit_task_constructor/issues/151>`_: Various fixes
* cartesian demo: illustrate merging of trajectories
* planning_attempts -> max_solutions (`#143 <https://github.com/JafarAbdi/moveit_task_constructor/issues/143>`_)
  The parameter describes the maximum number of found solutions before further planning is aborted.
* cleanup demo
* demo: add example cartesian.py
* Printing success log only if execution completes
  Previous code will print/log "Execution complete" even if the execution was disabled.
* Generalised code for object_name
  Previous code was generating the error on changing object_name in config/panda_config.yaml file because of this bug as here we are overwriting the object_name as "object" which brought the inconsistency in code.
* Merge branch master into wip-python-api
* add ExecuteTaskSolutionCapability to move_group (`#118 <https://github.com/JafarAbdi/moveit_task_constructor/issues/118>`_)
* "cartesian" demo: add an example stage for relative joint-space offsets
* Enable infinite number of repetitions for "modular" demo
  Using a joint-space interpolator to move back to start pose,
  we avoid pose drift in the Cartesian loop, which pushes the robot
  into its joint limits over time. Fixes `#113 <https://github.com/JafarAbdi/moveit_task_constructor/issues/113>`_.
* more tutorial demos
* demo: add 'execute' parameter
  useful for testing parameters
* Demo package for tutorial (`#104 <https://github.com/JafarAbdi/moveit_task_constructor/issues/104>`_)
  Co-Authored-By: Henning Kayser <henningkayser@picknik.ai>
  Co-Authored-By: Robert Haschke <rhaschke@techfak.uni-bielefeld.de>
* Contributors: AndyZe, Christian Petersmeier, Henning Kayser, Jafar, Jafar Abdi, JafarAbdi, Luca Lach, Michael Görner, Rajendra Singh, Robert Haschke, Stephanie Eng, cpetersmeier, simonGoldstein, v4hn
