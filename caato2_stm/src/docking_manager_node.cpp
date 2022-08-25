#include <stdlib.h>  
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
#include <actionlib/client/simple_action_client.h>
#include "caato2_stm/docking_manager.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "simple_docking_goal");

  ros::NodeHandle nh;

  ros::Rate loop_rate(10);

  ROS_INFO("starting docking_action_server 1");

  DockingManager docking_manager{&nh};

  ROS_INFO("starting docking_action_server 2");

  while (ros::ok())
  {
    ros::spinOnce();

    docking_manager.spinManager();

    loop_rate.sleep();
  }

  return 0;
}