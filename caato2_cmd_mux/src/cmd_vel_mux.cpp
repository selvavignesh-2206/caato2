#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "caato2_cmd_mux/change_sub_topic.h"

ros::Publisher pub;
ros::Subscriber sub;
geometry_msgs::Twist msg;
std::vector<std::string> cmd_vel_topics_;
ros::NodeHandle* nh_pointer;

void muxSubCallback(const geometry_msgs::Twist::ConstPtr &incoming_msg)
{
    msg = *incoming_msg;

}

bool change_topic_callback(caato2_cmd_mux::change_sub_topic::Request &req,
         caato2_cmd_mux::change_sub_topic::Response &res)
{
    if (req.a >= cmd_vel_topics_.size())
    {
        res.result = false;
        return false;
    }
    else if (req.a == 0)
    {
        msg.linear.x = 0;
        msg.linear.y = 0;
        msg.linear.z = 0;
        msg.angular.x = 0;
        msg.angular.y = 0;
        msg.angular.z = 0;
        res.result = true;
        return true;
    }
    sub.shutdown();
    sub = nh_pointer->subscribe(cmd_vel_topics_[req.a], 1000, muxSubCallback);
    // std::cerr << cmd_vel_topics_[req.a] << std::endl;
    res.result = true;

    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "caato2_cmd_mux");
    ros::NodeHandle nh;
    nh_pointer = &nh;
    
    nh.getParam("/cmd_vel_topic_list", cmd_vel_topics_);

    ros::ServiceServer service = nh.advertiseService("cmd_vel_mux", change_topic_callback);

    sub = nh.subscribe(cmd_vel_topics_[0], 1000, muxSubCallback);

    pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}