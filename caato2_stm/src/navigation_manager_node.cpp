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

   ROS_INFO("starting action_server 1");

  NavigationManager navigation_manager{&nh};

  ROS_INFO("starting action_server 2");

  while (ros::ok())
  {
    ros::spinOnce();

    navigation_manager.spinManager();

    loop_rate.sleep();
  }

  return 0;
}