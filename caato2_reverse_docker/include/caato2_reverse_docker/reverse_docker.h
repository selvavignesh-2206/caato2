#ifndef REVERSE_DOCKER_H
#define REVERSE_DOCKER_H

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "caato2_reverse_docker/ReverseDockAction.h"
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "caato2_stm/navigate_goal.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <string>
#include "caato2_reverse_docker/PID.h"
#include <dynamic_reconfigure/server.h>
#include "caato2_reverse_docker/PIDConfig.h"

class ReverseDocker
{
private:
  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<caato2_reverse_docker::ReverseDockAction> as_;  // NodeHandle instance must be created
                                                                                // before this line. Otherwise strange
                                                                                // error occurs.
  std::string action_name_;
  // create messages that are used to published feedback/result
  caato2_reverse_docker::ReverseDockFeedback feedback_;
  caato2_reverse_docker::ReverseDockResult result_;

  geometry_msgs::Pose goal_pose;
  geometry_msgs::Pose current_pose;

  dynamic_reconfigure::Server<caato2_reverse_docker::PIDConfig> PID_server;
  dynamic_reconfigure::Server<caato2_reverse_docker::PIDConfig>::CallbackType dynamic_reconfigure_cb;

  ros::Subscriber pose_subscriber;
  ros::Publisher coarse_cmd_vel_pub;
  PID angle_pid = PID(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  PID vel_x_pid = PID(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  double yaw_current;

  double calculateAngularVel(double orientationGoal);
  double calculateLinearVel(double distToGoal);
  void stopVel();
  double calculateOrientationGoal();
  double calculateDistanceToGoal();

public:
  ReverseDocker(std::string name);
  ~ReverseDocker();
  void executeCB(const caato2_reverse_docker::ReverseDockGoalConstPtr& goal);
  void poseSubscriberCB(const geometry_msgs::PoseWithCovarianceStamped& msg);
  void dynamicReconfigureCB(caato2_reverse_docker::PIDConfig& config, uint32_t level);
};

// #include <ros/ros.h>
// #include <actionlib/server/simple_action_server.h>
// #include <geometry_msgs/PoseWithCovarianceStamped.h>
// #include "caato2_reverse_docker/ReverseDockAction.h"
// #include "caato2_stm/navigate_goal.h"
// #include <move_base_msgs/MoveBaseAction.h>
// #include <string>
// #include "caato2_reverse_docker/PID.h"
// #include <dynamic_reconfigure/server.h>
// #include "caato2_reverse_docker/PIDConfig.h"

// class ReverseDockAction
// {
// public:
//   ReverseDockAction(std::string name);
//   ~ReverseDockAction();
//   void executeCB(const caato2_reverse_docker::ReverseDockActionConstPtr& goal);
//   void goalCB();
//   void preemptCB();
//   bool reverseGoalCB(caato2_stm::navigate_goal::Request& req, caato2_stm::navigate_goal::Response& res);
//   void reverseGoalExecutor();
//   void poseSubscriberCB(const geometry_msgs::PoseWithCovarianceStamped& msg);
//   void dynamicReconfigureCB(caato2_reverse_docker::PIDConfig &config, uint32_t level);

// private:
//   ros::NodeHandle nh_;
//   actionlib::SimpleActionServer<caato2_reverse_docker::ReverseDockAction> as_;
//   std::string action_name_;
//   caato2_reverse_docker::ReverseDockFeedback feedback_;
//   caato2_reverse_docker::ReverseDockResult result_;
//   caato2_reverse_docker::ReverseDockGoal goal_;
//   geometry_msgs::Pose goal_pose;
//   geometry_msgs::Pose current_pose;
//   ros::ServiceServer reverse_goal_server;

//   dynamic_reconfigure::Server<caato2_reverse_docker::PIDConfig> PID_server;
//   dynamic_reconfigure::Server<caato2_reverse_docker::PIDConfig>::CallbackType dynamic_reconfigure_cb;

//   ros::Subscriber pose_subscriber;
//   ros::Publisher coarse_cmd_vel_pub;
//   PID angle_pid = PID(0.0,0.0,0.0,0.0,0.0,0.0);
//   PID vel_x_pid = PID(0.0,0.0,0.0,0.0,0.0,0.0);
// };

#endif
