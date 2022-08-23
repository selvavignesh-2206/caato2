#include <ros/ros.h>
#include "caato2_stm/docking_manager.h"
#include <thread>
#include <iostream>

DockingManager::DockingManager(ros::NodeHandle* nh_pointer) : ac("move_base", true)
{
  nh = nh_pointer;
  docking_goal_service = nh->advertiseService("caato_docking_goal", &DockingManager::navGoal, this);
  docking_state_pub = nh->advertise<caato2_stm::docking_state>("navigation_state", 100);
}

DockingManager::~DockingManager()
{
}

void DockingManager::spinManager()
{

  ROS_INFO("Hello, this is the docking spin call");
  goal_state = ac.getState();
  if (goal_state == actionlib::SimpleClientGoalState::PENDING)
  {
    nav_state_msg.state_code = 0;
    nav_state_msg.state_description = "PENDING";
  }
  else if (goal_state == actionlib::SimpleClientGoalState::ACTIVE)
  {
    nav_state_msg.state_code = 0;
    nav_state_msg.state_description = "ACTIVE";
  }
  else if (goal_state == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    nav_state_msg.state_code = 1;
    nav_state_msg.state_description = "SUCCEEDED";
  }
  else
  {
    nav_state_msg.state_code = 2;
    nav_state_msg.state_description = "ERROR";
  }

  nav_state_pub.publish(nav_state_msg);

}

void NavigationManager::actionClientRun(const move_base_msgs::MoveBaseGoal& input_goal)
{
  // wait for the action server to come up
  while (!ac.waitForServer(ros::Duration(5.0)))
  {
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  ac.sendGoal(input_goal);
  goal_state = ac.getState();

  // std::threaHi A

  return;

  // while (goal_state == actionlib::SimpleClientGoalState::PENDING ||
  //        goal_state == actionlib::SimpleClientGoalState::ACTIVE)
  // {
  //   goal_state = ac.getState();
  //   // ROS_INFO("%s", goal_state.toString());
  // }

  // if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  //   ROS_INFO("Hooray, the action client was successful");
  // else
  //   ROS_INFO("The base failed to complete action for some reason");

  // goal_state = ac.getState();
  // spin_thread.join();

  // return;
}

bool NavigationManager::navGoal(caato2_stm::navigate_goal::Request& req, caato2_stm::navigate_goal::Response& res)
{
  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose = req.nav_goal;

  actionClientRun(goal);

  std::cout << goal_state.toString() << std::endl;

  if (goal_state == actionlib::SimpleClientGoalState::PENDING || goal_state == actionlib::SimpleClientGoalState::ACTIVE)
  {
    res.success = true;
    return true;
  }

  return false;
}