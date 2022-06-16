cmake_minimum_required(VERSION 3.5.0)

project(caato2_gazebo)

find_package(catkin REQUIRED COMPONENTS
roscpp
std_msgs
sensor_msgs
geometry_msgs
nav_msgs
tf
gazebo_ros
)

find_package(gazebo REQUIRED)

if (catkin_FOUND)

  catkin_package(
    CATKIN_DEPENDS roscpp std_msgs sensor_msgs geometry_msgs nav_msgs tf gazebo_ros
    DEPENDS GAZEBO
  )

  install(
    DIRECTORY launch worlds models rviz maps config
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

else()
  message("catkin not found so skipping this ROS1 package")
endif()

