#ifndef NAVIGATION_MANAGER_H
#define NAVIGATION_MANAGER_H

#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/Pose.h>
#include "caato2_stm/navigate_goal.h"

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class NavigationManager
{
public:
  NavigationManager(ros::NodeHandle* nh_pointer);
  ~NavigationManager();

  void actionClientRun(const move_base_msgs::MoveBaseGoal& input_goal);

  void spinManager();

private:
  ros::NodeHandle* nh;
  MoveBaseClient ac;
  ros::ServiceServer nav_goal_service;

  actionlib::SimpleClientGoalState goal_state{ actionlib::SimpleClientGoalState::PENDING };

  bool service_state;

  bool navGoal(caato2_stm::navigate_goal::Request& req, caato2_stm::navigate_goal::Response& res);
};

#endif