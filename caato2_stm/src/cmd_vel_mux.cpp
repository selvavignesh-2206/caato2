#include "caato2_stm/cmd_vel_mux.h"


CmdVelMux::CmdVelMux()
{

}

CmdVelMux::CmdVelMux(ros::NodeHandle* node_handle_pointer)
{
    nh_pointer = node_handle_pointer;

    nh_pointer->getParam("/cmd_vel_topic_list", cmd_vel_topics_);

    sub = nh_pointer->subscribe(cmd_vel_topics_[0], 1000, &CmdVelMux::muxSubCallback, this);
    pub = nh_pointer->advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    service = nh_pointer->advertiseService("cmd_vel_mux", &CmdVelMux::change_topic_callback, this);
}

CmdVelMux::~CmdVelMux()
{
}

void CmdVelMux::muxSpin()
{
    pub.publish(msg);
}

void CmdVelMux::muxSubCallback(const geometry_msgs::Twist::ConstPtr &incoming_msg)
{
    msg = *incoming_msg;
    
}

bool CmdVelMux::change_topic_callback(caato2_stm::change_sub_topic::Request &req,
         caato2_stm::change_sub_topic::Response &res)
{
    std::cerr << "line 1 " << cmd_vel_topics_[req.a] << std::endl;
    if (req.a >= cmd_vel_topics_.size())
    {
        res.result = false;
        std::cerr << "false" << std::endl;
        return false;
    }
    else // if (req.a == 0)
    {
        msg.linear.x = 0;
        msg.linear.y = 0;
        msg.linear.z = 0;
        msg.angular.x = 0;
        msg.angular.y = 0;
        msg.angular.z = 0;
        res.result = true;
        // return true;
    }
    sub.shutdown();
    sub = nh_pointer->subscribe(cmd_vel_topics_[req.a], 1000, &CmdVelMux::muxSubCallback, this);
    std::cerr << "line 2 " <<cmd_vel_topics_[req.a] << std::endl;
    res.result = true;

    return true;
}