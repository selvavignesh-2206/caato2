#ifndef DOCKING_MANAGER_H
#define DOCKING_MANAGER_H

#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/Pose.h>
#include "caato2_stm/navigate_goal.h"
#include "caato2_stm/navigation_state.h"

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class DockingManager
{
public:
  DockingManager(ros::NodeHandle* nh_pointer);
  
  ~DockingManager();

  void actionClientRun(const move_base_msgs::MoveBaseGoal& input_goal);

  void spinManager();

private:
  ros::NodeHandle* nh;
  MoveBaseClient ac;
  ros::ServiceServer nav_goal_service;
  ros::Publisher nav_state_pub;

  actionlib::SimpleClientGoalState goal_state{ actionlib::SimpleClientGoalState::PENDING };

  bool service_state;
  caato2_stm::navigation_state nav_state_msg;

  bool navGoal(caato2_stm::navigate_goal::Request& req, caato2_stm::navigate_goal::Response& res);

};

#endif
