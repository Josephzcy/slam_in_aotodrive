
SET(MODULE_NAME common)
SET(MODULE_HOME_PATH ${PROJECT_HOME}/${MODULE_NAME})
message(STATUS "MODULE_HOME_PATH = ${MODULE_HOME_PATH}")
# set(CMAKE_CXX_STANDARD 17)


INCLUDE_DIRECTORIES(
  ${SRC_HOME_PATH}
  ${MODULE_HOME_PATH}
  ${PROJECT_HOME}/src
)

add_subdirectory(msg)

add_library(${PROJECT_NAME}_common SHARED
        io_utils.cc
        timer/timer.cc
        global_flags.cc
        g2o_types.cc
        point_cloud_utils.cc
        )

target_link_libraries(${PROJECT_NAME}_common
        ${PROJECT_NAME}_tools
        ${catkin_LIBRARIES}
        ${PCL_LIBRARIES}
        )


set(sad_messages
  monitor_msgs_generate_messages
  velodyne_msgs_generate_messages
  livox_ros_driver_generate_messages
)

add_dependencies(${PROJECT_NAME}_common ${sad_messages})
