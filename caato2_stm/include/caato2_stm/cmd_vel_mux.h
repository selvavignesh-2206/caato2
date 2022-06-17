#ifndef CMD_VEL_MUX_H
#define CMD_VEL_MUX_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "caato2_stm/change_sub_topic.h"

class CmdVelMux
{
public:
    CmdVelMux();

    CmdVelMux(ros::NodeHandle* node_handle_pointer);

    ~CmdVelMux();

    void muxSpin();

    void muxSubCallback(const geometry_msgs::Twist::ConstPtr &incoming_msg);
    bool change_topic_callback(caato2_stm::change_sub_topic::Request &req,
         caato2_stm::change_sub_topic::Response &res);

private:
    ros::Publisher pub;
    ros::Subscriber sub;
    ros::ServiceServer service;
    geometry_msgs::Twist msg;
    std::vector<std::string> cmd_vel_topics_;
    ros::NodeHandle* nh_pointer;
};

#endif
