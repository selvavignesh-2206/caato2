#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
// #include "caato2_stm/change_robot_state.h"
#include "caato2_stm/cmd_vel_mux.h"





int main(int argc, char **argv)
{
    ros::init(argc, argv, "caato2_stm");
    ros::NodeHandle nh;

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