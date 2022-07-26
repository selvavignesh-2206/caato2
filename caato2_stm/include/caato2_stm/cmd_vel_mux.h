#ifndef CMD_VEL_MUX_H
#define CMD_VEL_MUX_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <actionlib_msgs/GoalID.h>
#include "caato2_stm/change_robot_state.h"
#include "caato2_stm/caato_state.h"

class CmdVelMux
{
public:

    CmdVelMux(ros::NodeHandle* node_handle_pointer);
    ~CmdVelMux();

    void muxSpin();

    bool change_topic_callback(caato2_stm::change_robot_state::Request &req,
         caato2_stm::change_robot_state::Response &res);

private:
    ros::Publisher cmd_vel_pub;

    ros::Publisher cancel_nav_goal_pub;

    ros::Subscriber cmd_vel_sub;
    void muxSubCallback(const geometry_msgs::Twist::ConstPtr &incoming_msg);

    
    ros::ServiceServer service;
    geometry_msgs::Twist msg;
    const actionlib_msgs::GoalID cancel_goal{};
    // std::vector<std::string> cmd_vel_topics_;
    const std::string cmd_vel_topics[4] = {"cmd_vel/move_base", "cmd_vel/telejoy", "cmd_vel/coarse_guidance", "cmd_vel/reverse_docking"};
    ros::NodeHandle* nh_pointer;

    void subscriber_checker();
};

#endif
