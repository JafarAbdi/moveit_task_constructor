#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
if (BUILD_TESTING)
	find_package(ament_cmake_gtest REQUIRED)
	find_package(ament_cmake_gmock REQUIRED)

	add_library(gtest_utils SHARED gtest_value_printers.cpp models.cpp stage_mockups.cpp)

	target_link_libraries(gtest_utils ${PROJECT_NAME})

	macro(mtc_add_test TYPE FILE)
	    string(REGEX REPLACE "\.cpp$" "" TEST_NAME ${FILE})
	    string(REGEX REPLACE "_" "-" TEST_NAME ${TEST_NAME})
      if("${TYPE}" STREQUAL "gtest")
          ament_add_gtest(${PROJECT_NAME}-${TEST_NAME} ${FILE})
      elseif("${TYPE}" STREQUAL "gmock")
          ament_add_gmock(${PROJECT_NAME}-${TEST_NAME} ${FILE})
      endif()
	    _catkin_add_google_test(${TYPE} ${PROJECT_NAME}-${TEST_NAME} ${FILE})
	    target_link_libraries(${PROJECT_NAME}-${TEST_NAME} ${PROJECT_NAME} ${PROJECT_NAME}_stages ${ARGN} gtest_utils gtest_main)
	endmacro()
	macro(mtc_add_gtest)
	    mtc_add_test("gtest" ${ARGN})
	endmacro()
	macro(mtc_add_gmock)
	    mtc_add_test("gmock" ${ARGN})
	endmacro()

	mtc_add_gtest(test_stage.cpp)
	mtc_add_gtest(test_container.cpp)
	mtc_add_gtest(test_serial.cpp)
	mtc_add_gtest(test_pruning.cpp)
	mtc_add_gtest(test_properties.cpp)
	mtc_add_gtest(test_cost_terms.cpp)

	mtc_add_gmock(test_fallback.cpp)
	mtc_add_gmock(test_cost_queue.cpp)
	mtc_add_gmock(test_interface_state.cpp)

	# building these integration tests works without moveit config packages
	ament_add_gtest_executable(pick_ur5 pick_ur5.cpp)
	target_link_libraries(pick_ur5 ${PROJECT_NAME}_stages)

	ament_add_gtest_executable(pick_pr2 pick_pr2.cpp)
	target_link_libraries(pick_pr2 ${PROJECT_NAME}_stages)

	ament_add_gtest_executable(pick_pa10 pick_pa10.cpp)
	target_link_libraries(pick_pa10 ${PROJECT_NAME}_stages)

	# TODO(JafarAbdi): Port integration tests
	#	# running these integrations test naturally requires the moveit configs
	#	find_package(tams_ur5_setup_moveit_config QUIET)
	#	if(tams_ur5_setup_moveit_config_FOUND)
	#		add_rostest(pick_ur5.test)
	#	endif()
	#	find_package(pr2_moveit_config_FOUND QUIET)
	#	if(pr2_moveit_config_FOUND)
	#		add_rostest(pick_pr2.test)
	#	endif()
	#	find_package(pa10_shadow_moveit_config QUIET)
	#	if(pa10_shadow_moveit_config_FOUND)
	#		add_rostest(pick_pa10.test)
	#	endif()
endif()
