#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "caato2_stm/cmd_vel_mux.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "caato2_node");
    ros::NodeHandle nh;

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}