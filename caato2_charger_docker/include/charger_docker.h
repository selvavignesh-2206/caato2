#ifndef REVERSE_DOCKER_H
#define REVERSE_DOCKER_H

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "caato2_charger_docker/ReverseDockAction.h"
#include <geometry_msgs/PoseWithCovarianceStamped.h>
//  #include "caato2_stm/navigate_goal.h"    !!!!!TODO!!!!
#include <move_base_msgs/MoveBaseAction.h>
#include <string>
#include "caato2_changer_docking/PID.h"
#include <dynamic_reconfigure/server.h>
#include "caato2_charger_docker/PIDConfig.h"

class ChargerDocker
{
public:

    ChargerDocker(std::string name);

    ~ChargerDocker();


    void move();

    void actual_angle (const nav_msgs::Odometry& msg);

    // Functions to manipulate various other topics and their data
    void poseSubscriberCB(const geometry_msgs::PoseWithCovarianceStamped& msg);
    void executeCB(const caato2_charger_docker::ChargerDockGoalConstPtr& goal);

    // For dynamic reconfiguration of parameters
    void dynamicReconfigureCB(caato2_charger_docker::PIDConfig& config, uint32_t level);

    // Functions for the actual docking logic portion
    void linearApproach(const );
    void driveForward (double distance);
    void frontalDocking(....);

private:

    ros::NodeHandle nh_;

    actionlib::SimpleActionServer<caato2_charger_docker::ChangerDockAction> as_;
    std::string action_name_;

    caato2_charger_docker::ChargerDockerFeedback feedback_;
    caato2_charger_docker::ChargerDockerResult result_;

    geometry_msgs::Pose goal_pose;
    geometry_msgs::Pose current_pose;

    dynamic_reconfigure::Server<caato2_charger_docker::PIDConfig> PID_server;
    dynamic_reconfigure::Server<caato2_charger_docker::PIDConfig>::CallbackType dynamic_reconfigure_cb;

    ros::Subscriber pose_subscriber;
    ros::Publisher coarse_cmd_vel_pub;
    
    PID angle_pid = PID(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
    PID vel_x_pid = PID(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)

    double yaw_current;

    // Functions to calculate and manipulate the cmd_vel 
    double calculateAngularVel(double orientationGoal);
    double calculateLinearVel(double distToGoal);
    void stopVel();
    double calculateOrientationGoal();
    double calculateDistanceToGoal();

    /* Initial Code
    ros::Publisher cmd_vel_pub;

    ros::Publisher cancel_nav_goal_pub;

    ros::Subscriber cmd_vel_sub;

    void dockingSubCallback(const geometry_msgs::Twist::ConstPtr &incoming_msg);
    
    ros::ServiceServer service;
    geometry_msgs::Twist msg;
    const actionlib_msgs::GoalID cancel_goal{};

    const std::string cmd_vel_topics[2] = {"cmd_vel/move_base", "cmd_vel/docking"};
    ros::NodeHandle* nh_pointer;
    */

}