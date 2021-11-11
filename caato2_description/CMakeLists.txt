cmake_minimum_required(VERSION 3.5.0)

project(caato2_description)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

if (catkin_FOUND)

  catkin_package()

  include_directories(
    ${catkin_INCLUDE_DIRS}
  )

  install(
    DIRECTORY launch meshes urdf
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  )

else()
  message("catkin not found so skipping this ROS1 package")
endif()

