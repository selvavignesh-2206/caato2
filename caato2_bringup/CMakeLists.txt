cmake_minimum_required(VERSION 3.0.2)
project(caato2_bringup)

add_compile_options(-std=c++11)
################################################################################
# Find catkin packages and libraries for catkin and system dependencies
################################################################################
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  diagnostic_msgs
  tf2
  tf2_ros
  geometry_msgs
  nav_msgs
  std_srvs
  ds4_driver
)

################################################################################
# Setup for python modules and scripts
################################################################################

################################################################################
# Declare ROS messages, services and actions
################################################################################

################################################################################
# Declare ROS dynamic reconfigure parameters
################################################################################

################################################################################
# Declare catkin specific configuration to be passed to dependent projects
################################################################################

catkin_package(
  CATKIN_DEPENDS geometry_msgs roscpp std_msgs tf2 tf2_ros nav_msgs std_srvs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

################################################################################
# Build
################################################################################
add_executable(static_ouster_broadcaster src/ouster_tf_publisher_node.cpp)

add_dependencies(static_ouster_broadcaster ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(static_ouster_broadcaster  ${catkin_LIBRARIES} )

add_executable(odom_to_tfstamped src/odomTfTransform.cpp)

add_dependencies(odom_to_tfstamped ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(odom_to_tfstamped  ${catkin_LIBRARIES} )

add_executable(ds4_trigger src/ds4_trigger.cpp)

add_dependencies(ds4_trigger ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(ds4_trigger ${catkin_LIBRARIES} )

################################################################################
# Install
################################################################################
install(TARGETS static_ouster_broadcaster odom_to_tfstamped ds4_trigger
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


install(DIRECTORY launch 
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

################################################################################
# Test
################################################################################

