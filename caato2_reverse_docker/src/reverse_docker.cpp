#include "caato2_reverse_docker/reverse_docker.h"
#include <geometry_msgs/Twist.h>
#include "tf/transform_datatypes.h"
#include <math.h>

ReverseDocker::ReverseDocker(std::string name)
  : as_(nh_, name, boost::bind(&ReverseDocker::executeCB, this, _1), false), action_name_(name)
{
  dynamic_reconfigure_cb = boost::bind(&ReverseDocker::dynamicReconfigureCB, this, _1, _2);
  PID_server.setCallback(dynamic_reconfigure_cb);

  pose_subscriber = nh_.subscribe("amcl_pose", 100, &ReverseDocker::poseSubscriberCB, this);
  coarse_cmd_vel_pub = nh_.advertise<geometry_msgs::Twist>("cmd_vel/reverse_docking", 10);

  as_.start();
}

ReverseDocker::~ReverseDocker(void)
{
}

void ReverseDocker::executeCB(const caato2_reverse_docker::ReverseDockGoalConstPtr& goal)
{
  ros::Rate r(10);
  bool success = false;
  geometry_msgs::Twist cmd_vel_msg;
  goal_pose = goal->goal_pose;

  double yaw_goal = calculateOrientationGoal();
  feedback_.stage = 1;
  feedback_.description = "Stage 1: Angular rotation to backwards face goal";
  feedback_.executing = true;

  while (feedback_.stage == 1)
  {
    if (as_.isPreemptRequested() || !ros::ok())
    {
      ROS_INFO("%s: Preempted", action_name_.c_str());
      as_.setPreempted();
      break;
    }

    as_.publishFeedback(feedback_);
    cmd_vel_msg.angular.z = calculateAngularVel(yaw_goal);

    if (abs(yaw_goal - yaw_current) > 0.05)
    {
      // geometry_msgs::Twist cmd_vel_msg;
      // ROS_INFO("angular velocity is: %f", cmd_vel_msg.angular.z);
      coarse_cmd_vel_pub.publish(cmd_vel_msg);
      ros::spinOnce();
      r.sleep();
    }
    else
    {
      stopVel();
      feedback_.stage = 2;
      feedback_.description = "Stage 2: Translational Movement to goal";
    }
  }

  double dist_to_goal = 0;

  while (feedback_.stage == 2)
  {
    if (as_.isPreemptRequested() || !ros::ok())
    {
      ROS_INFO("%s: Preempted", action_name_.c_str());
      as_.setPreempted();
      break;
    }
    as_.publishFeedback(feedback_);

    dist_to_goal = calculateDistanceToGoal();
    yaw_goal = calculateOrientationGoal();
    // cmd_vel_msg.angular.z = calculateAngularVel(yaw_goal);
    cmd_vel_msg.linear.x = calculateLinearVel(dist_to_goal);
    // ROS_INFO("cmd vel msg x = %f, z = %f", cmd_vel_msg.linear.x, cmd_vel_msg.angular.z);

    if (dist_to_goal > 0.05)
    {
      coarse_cmd_vel_pub.publish(cmd_vel_msg);
      ros::spinOnce();
      r.sleep();
    }
    else
    {
      stopVel();
      feedback_.stage = 3;
      feedback_.description = "Stage 3: Completed all goals";
    }
  }

  result_.success = true;
  success = true;
  // result_.success = true;
  ROS_INFO(success ? "true" : "false");
  as_.setSucceeded(result_);
}

void ReverseDocker::poseSubscriberCB(const geometry_msgs::PoseWithCovarianceStamped& msg)
{
  current_pose = msg.pose.pose;
}

void ReverseDocker::dynamicReconfigureCB(caato2_reverse_docker::PIDConfig& config, uint32_t level)
{
  angle_pid.setValues(config.AnglePID_dt, config.AnglePID_max_angular_vel, config.AnglePID_min_angular_vel,
                      config.AnglePID_Kp, config.AnglePID_Kd, config.AnglePID_Ki);
  vel_x_pid.setValues(config.XVelPID_dt, config.XVelPID_max_x_vel, config.XVelPID_min_x_vel, config.XVelPID_Kp,
                      config.XVelPID_Kd, config.XVelPID_Ki);
  ROS_INFO("Kp is %f", angle_pid.getDt());
  ROS_INFO("Kp for X is %f", vel_x_pid.getDt());
}

void ReverseDocker::stopVel()
{
  geometry_msgs::Twist cmd_vel_msg;
  cmd_vel_msg.angular.z = 0;
  cmd_vel_msg.linear.x = 0;
  coarse_cmd_vel_pub.publish(cmd_vel_msg);
  ros::spinOnce();
}

double ReverseDocker::calculateAngularVel(double orientationGoal)
{
  double roll, pitch;
  tf::Quaternion quat_current;
  tf::quaternionMsgToTF(current_pose.orientation, quat_current);
  tf::Matrix3x3(quat_current).getRPY(roll, pitch, yaw_current);
  return angle_pid.calculate(orientationGoal, yaw_current);
}

double ReverseDocker::calculateOrientationGoal()
{
  double yaw_goal =
      atan2((current_pose.position.y - goal_pose.position.y), (current_pose.position.x - goal_pose.position.x));
  // (yaw_goal > 0) ? yaw_goal -= 3.14 : yaw_goal += 3.14;
  return yaw_goal;
}

double ReverseDocker::calculateDistanceToGoal()
{
  double dist_to_goal = sqrt(pow((current_pose.position.x - goal_pose.position.x), 2) +
                             pow((current_pose.position.y - goal_pose.position.y), 2));
  // ROS_INFO("current x,y pose is (%f, %f) and goal pose is (%f,%f)", current_pose.position.x, current_pose.position.y,
          //  goal_pose.position.x, goal_pose.position.y);
  ROS_INFO("dist to goal is %f", dist_to_goal);
  return dist_to_goal;
}

double ReverseDocker::calculateLinearVel(double distToGoal)
{
  double vel = vel_x_pid.calculate(0.00, distToGoal);
  ROS_INFO("cmd_vel is %f", vel_x_pid.calculate(0.05, distToGoal));
  return vel;
}

// #include "caato2_reverse_docker/reverse_docker.h"
// #include <geometry_msgs/Twist.h>
// #include "tf/transform_datatypes.h"
// #include <math.h>

// ReverseDockAction::ReverseDockAction(std::string name) : as_(nh_, name, false), action_name_(name)
// {
//   as_.registerGoalCallback(boost::bind(&ReverseDockAction::goalCB, this));
//   as_.registerPreemptCallback(boost::bind(&ReverseDockAction::preemptCB, this));
//   reverse_goal_server = nh_.advertiseService("caato2_reverse_goal", &ReverseDockAction::reverseGoalCB, this);

//   dynamic_reconfigure_cb = boost::bind(&ReverseDockAction::dynamicReconfigureCB, this, _1, _2);
//   PID_server.setCallback(dynamic_reconfigure_cb);

//   pose_subscriber = nh_.subscribe("amcl_pose", 100, &ReverseDockAction::poseSubscriberCB, this);
//   coarse_cmd_vel_pub = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 10);
//   feedback_.executing = false;
//   result_.success = false;
//   as_.start();
// }

// ReverseDockAction::~ReverseDockAction(void)
// {
// }

// void ReverseDockAction::executeCB(const caato2_reverse_docker::ReverseDockActionConstPtr& goal)
// {
// }

// void ReverseDockAction::goalCB()
// {
//   goal_pose = geometry_msgs::Pose{};
//   goal_pose = as_.acceptNewGoal()->goal_pose;
// }

// void ReverseDockAction::preemptCB()
// {
//   ROS_INFO("%s: Preempted", action_name_.c_str());
//   as_.setPreempted();
// }

// bool ReverseDockAction::reverseGoalCB(caato2_stm::navigate_goal::Request& req, caato2_stm::navigate_goal::Response&
// res)
// {
//   goal_pose = req.nav_goal;

//   if (as_.isActive())
//   {
//     feedback_.executing = true;
//     as_.publishFeedback(feedback_);
//     res.success = true;
//     return true;
//   }
//   else
//   {
//     feedback_.executing = true;
//     as_.publishFeedback(feedback_);
//     res.success = false;
//     return true;
//   }

//   return false;
// }

// void ReverseDockAction::reverseGoalExecutor()
// {
//   if (!feedback_.executing)
//   {
//     return;
//   }

//   tf::Quaternion quat_current;
//   tf::quaternionMsgToTF(current_pose.orientation, quat_current);
//   double roll, pitch, yaw_current;
//   tf::Matrix3x3(quat_current).getRPY(roll, pitch, yaw_current);
//   double yaw_goal =
//       atan2((goal_pose.position.y - current_pose.position.y), (goal_pose.position.x - current_pose.position.x));
//   yaw_goal += 3.14;
//   angle_pid.calculate(yaw_goal, yaw_current);

//   feedback_.executing = true;
//   as_.publishFeedback(feedback_);

//   while (abs(yaw_goal - yaw_current) > 0.05)
//   {
//     tf::quaternionMsgToTF(current_pose.orientation, quat_current);
//     tf::Matrix3x3(quat_current).getRPY(roll, pitch, yaw_current);

//     geometry_msgs::Twist cmd_vel_msg;
//     cmd_vel_msg.angular.z = angle_pid.calculate(yaw_goal, yaw_current);
//     coarse_cmd_vel_pub.publish(cmd_vel_msg);

//     ros::spinOnce();
//   }

//   if (abs(yaw_goal - yaw_current) > 0.05)
//   {
//     result_.success = true;
//     as_.setSucceeded(result_);
//   }
//   else{
//     result_.success = false;
//     as_.setAborted(result_);
//   }
// }

// void ReverseDockAction::poseSubscriberCB(const geometry_msgs::PoseWithCovarianceStamped& msg)
// {
//   current_pose = msg.pose.pose;
// }

// void ReverseDockAction::dynamicReconfigureCB(caato2_reverse_docker::PIDConfig& config, uint32_t level)
// {
//   angle_pid.setValues(config.AnglePID_dt, config.AnglePID_min_angular_vel, config.AnglePID_min_angular_vel,
//                       config.AnglePID_Kp, config.AnglePID_Kd, config.AnglePID_Ki);
//   vel_x_pid.setValues(config.XVelPID_dt, config.XVelPID_max_x_vel, config.XVelPID_min_x_vel, config.XVelPID_Kp,
//                       config.XVelPID_Kd, config.XVelPID_Ki);
// }