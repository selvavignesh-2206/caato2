#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "caato2_stm/change_sub_topic.h"
#include "caato2_stm/cmd_vel_mux.h"





int main(int argc, char **argv)
{
    ros::init(argc, argv, "caato2_stm");
    ros::NodeHandle nh;
    // nh_pointer = &nh;
    
    // nh.getParam("/cmd_vel_topic_list", cmd_vel_topics_);

    // ros::ServiceServer service = nh.advertiseService("cmd_vel_mux", change_topic_callback);

    // sub = nh.subscribe(cmd_vel_topics_[0], 1000, muxSubCallback);

    // pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    // ros::NodeHandle* nh_pointer = &nh;

    CmdVelMux cmdVelMux(&nh);

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        ros::spinOnce();

        cmdVelMux.muxSpin();

        loop_rate.sleep();
    }

    return 0;
}