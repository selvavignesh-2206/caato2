#include <stdlib.h>  //for converting argv to int
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "caato2_stm/navigation_manager.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "simple_navigation_goals");

  ros::NodeHandle nh;

  ros::Rate loop_rate(10);

  NavigationManager navigation_manager{&nh};

  ROS_INFO("starting action_server");

  while (ros::ok())
  {
    ros::spin();
    loop_rate.sleep();
  }

  return 0;
}