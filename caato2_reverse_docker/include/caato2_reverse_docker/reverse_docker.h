#ifndef REVERSE_DOCKER_H
#define REVERSE_DOCKER_H

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "caato2_reverse_docker/ReverseDockAction.h"
#include "caato2_stm/navigate_goal.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <string>
#include "caato2_reverse_docker/PID.h"

class ReverseDockAction
{
public:
  ReverseDockAction(std::string name);
  ~ReverseDockAction();
  void executeCB(const caato2_reverse_docker::ReverseDockActionConstPtr& goal);
  void goalCB();
  void preemptCB();
  bool reverseGoalCB(caato2_stm::navigate_goal::Request& req, caato2_stm::navigate_goal::Response& res);
  void reverseGoalExecutor();
  void poseSubscriberCB(const geometry_msgs::PoseWithCovarianceStamped& msg);

private:
  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<caato2_reverse_docker::ReverseDockAction> as_;
  std::string action_name_;
  caato2_reverse_docker::ReverseDockFeedback feedback_;
  caato2_reverse_docker::ReverseDockResult result_;
  geometry_msgs::Pose goal_pose;
  geometry_msgs::Pose current_pose;
  ros::ServiceServer reverse_goal_server;
  ros::Subscriber pose_subscriber;
  PID angle_pid = PID(0.0,0.0,0.0,0.0,0.0,0.0);
  PID vel_x_pid = PID(0.0,0.0,0.0,0.0,0.0,0.0);
};

#endif