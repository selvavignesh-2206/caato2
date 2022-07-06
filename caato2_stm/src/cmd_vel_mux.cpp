#include "caato2_stm/cmd_vel_mux.h"

CmdVelMux::CmdVelMux(ros::NodeHandle* node_handle_pointer)
{
    nh_pointer = node_handle_pointer;

    // nh_pointer->getParam("/cmd_vel_topic_list", cmd_vel_topics_);

    cmd_vel_sub = nh_pointer->subscribe(cmd_vel_topics[0], 1000, &CmdVelMux::muxSubCallback, this);
    cmd_vel_pub = nh_pointer->advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    cancel_nav_goal_pub = nh_pointer->advertise<actionlib_msgs::GoalID>("move_base/cancel", 1000);
    service = nh_pointer->advertiseService("cmd_vel_mux", &CmdVelMux::change_topic_callback, this);
}

CmdVelMux::~CmdVelMux()
{
}

void CmdVelMux::muxSpin()
{
    cmd_vel_pub.publish(msg);
}

void CmdVelMux::muxSubCallback(const geometry_msgs::Twist::ConstPtr &incoming_msg)
{
    msg = *incoming_msg;
    
}

bool CmdVelMux::change_topic_callback(caato2_stm::change_robot_state::Request &req,
         caato2_stm::change_robot_state::Response &res)
{
    // std::cerr << "line 1 " << cmd_vel_topics_[req.a] << std::endl;
    if (req.request_state_code >= ((sizeof(cmd_vel_topics)/sizeof(cmd_vel_topics[0])) + 1))
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

    switch (req.request_state_code){
        case 0: //for caato stop command
            cmd_vel_sub.shutdown();
            res.result = true;
            cancel_nav_goal_pub = nh_pointer->advertise<actionlib_msgs::GoalID>("move_base/cancel", 1000);
            cancel_nav_goal_pub.publish(cancel_goal);
            muxSpin();
            return true;
            break;
        case 1: //for move_base navigate state
            subscriber_checker();
            cmd_vel_sub = nh_pointer->subscribe(cmd_vel_topics[0], 1000, &CmdVelMux::muxSubCallback, this);
            return true;
            break;
        case 2: //for move_base PAUSE state
            subscriber_checker();
            return true;
            break;
        case 3: //for telejoy state
            subscriber_checker();
            cmd_vel_sub = nh_pointer->subscribe(cmd_vel_topics[1], 1000, &CmdVelMux::muxSubCallback, this);
            return true;
            break;
        case 4: //for reverse from dock, entering lift
            subscriber_checker();
            cmd_vel_sub = nh_pointer->subscribe(cmd_vel_topics[3], 1000, &CmdVelMux::muxSubCallback, this);
            return true;
            break;
        default:
            return false;
            break; 
    }
    
    cmd_vel_sub.shutdown();
    cmd_vel_sub.shutdown();
    cmd_vel_sub = nh_pointer->subscribe(cmd_vel_topics[req.request_state_code], 1000, &CmdVelMux::muxSubCallback, this);
    // std::cerr << "line 2 " <<cmd_vel_topics_[req.a] << std::endl;
    res.result = true;

    return true;
}

void CmdVelMux::subscriber_checker(){
    if (cmd_vel_sub.getNumPublishers()){
        cmd_vel_sub.shutdown();
    }
    if (cancel_nav_goal_pub.getNumSubscribers()){
        cancel_nav_goal_pub.shutdown();
    }
}