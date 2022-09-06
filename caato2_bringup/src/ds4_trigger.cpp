/**
 * @file ds4_trigger.cpp
 * @author Selva
 * @brief Service call trigger using L2 and
 * R2 buttons in DS4
 * @version 0.1
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <string>
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/SetBool.h>
#include <std_msgs/Int32.h>
#include <ds4_driver/Status.h>

class DS4_Trigger
{
public:
    DS4_Trigger(ros::NodeHandle &n)
    {

        ros::NodeHandle private_nh("~");

        // Subscriber
        this->sub = n.subscribe<ds4_driver::Status>("/status", 10, &DS4_Trigger::subscribeDS4, this);

        this->serv = n.serviceClient<std_srvs::SetBool::Request, std_srvs::SetBool::Response>("trolley_lifting_arm_srv", &DS4_Trigger::printTrigger);
    }

    ~DS4_Trigger()
    {
    }

    void run()
    {
        this->printTrigger();
    }

    void subscribeDS4(const ds4_driver::Status::ConstPtr &status)
    {

        this->l2 = status->button_l2;
        this->r2 = status->button_r2;
    }

    bool printTrigger()
    {
        std_srvs::SetBool srv_info;
        if (this->l2 == 1)
        {
            srv_info.request.data = false;
            ROS_INFO("Trigger L2 activated: %i", this->l2);
        }
        else if (this->r2 == 1)
        {
            srv_info.request.data = true;
            ROS_INFO("Trigger R2 activated: %i", this->r2);
        }
        else
        {
            return false;
        }

        if (this->serv.call(srv_info))
        {
            ROS_INFO("Good call");
        }
        else
        {
            ROS_INFO("Bad call");
        }

        return true;
    }

private:
    ros::Subscriber sub;

    ros::ServiceClient serv;

    int32_t l2, r2;
};

int main(int argc, char **argv)
{

    ros::init(argc, argv, "DS4_Trigger");

    ros::NodeHandle n;

    // Create DS4_Trigger Object
    DS4_Trigger *ds4_trigger = new DS4_Trigger(n);

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        ds4_trigger->run();
        ros::spinOnce();
        loop_rate.sleep();
    }

    delete ds4_trigger;

    return 0;
}