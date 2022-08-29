#ifndef DOCKING_LOGIC_H
#define DOCKING_LOGIC_H

#include <math.h>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"
#include <bits/stdc++.h>
#include <nav_msgs/Odometry.h>
#include <tf2/LinearMath/Quaternion.h>
#include <cmath>

class DockingLogic 
{
public:

    void move();

    void actual_angle (const nav_msgs::Odometry& msg);

    void linearApproach(const );

    void driveForward (double distance);

    void frontalDocking(....);

    // TODO: More functions

private:

    ros::Publisher cmd_vel_pub;

    ros::Publisher cancel_nav_goal_pub;

    ros::Subscriber cmd_vel_sub;

    void dockingSubCallback(const geometry_msgs::Twist::ConstPtr &incoming_msg);
    
    ros::ServiceServer service;
    geometry_msgs::Twist msg;
    const actionlib_msgs::GoalID cancel_goal{};

    const std::string cmd_vel_topics[2] = {"cmd_vel/move_base", "cmd_vel/docking"};
    ros::NodeHandle* nh_pointer;

    // TODO: Declare variables 
}