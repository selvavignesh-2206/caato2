#ifndef REVERSE_DOCKER_H
#define REVERSE_DOCKER_H

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "caato2_reverse_docker/ReverseDockAction.h"
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "caato2_stm/navigate_goal.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <string>
#include "caato2_changer_docking/PID.h"
#include <dynamic_reconfigure/server.h>
#include "caato2_reverse_docker/PIDConfig.h"

class ChargerDocker
{
public:

    ChargerDocker(std::)

    void move();

    void actual_angle (const nav_msgs::Odometry& msg);

    void linearApproach(const );

    void driveForward (double distance);

    void frontalDocking(....);

    void poseSubscriberCB(const geometry_msgs::PoseWithCovarianceStamped& msg);

    void dynamicReconfigureCB(caato2_charger_docker::PIDConfig& config, uint32_t level);


    // TODO: More functions

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