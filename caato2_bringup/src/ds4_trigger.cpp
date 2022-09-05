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

class DS4_Trigger 
{
    public:

        DS4_Trigger(ros::NodeHandle &n) {

            ros::NodeHandle private_nh("~");

            //Subscriber
            this->sub = n.subscribe<sensor_msgs::Joy>("/joy", 10, &DS4_Trigger::subscribeDS4, this);
            
            //Service
            this->serv= n.advertiseService("/trolley_....", printTrigger);

        }

        ~DS4_Trigger() {
        }

        void run() {
            
            this->printTrigger();

        }

        void subscribeDS4(const sensor_msgs::Joy::ConstPtr &joy) {

            this->l2 = joy->axes[3];
            this->r2 = joy->axes[4];

        }

        bool printTrigger(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res) 
        {

            if (this->l2 > 0) 
            {
                res.success = false;
                ROS_INFO("Trigger L2 activated: %d", this->l2);
            }
            else if (this->r2 >0)
            {
                res.success = true;
                ROS_INFO("Trigger R2 activated: %d", this->r2);
            }

            return true;
        }

    private:

        ros::Subscriber sub;

        ros::ServiceServer serv;

        double l2, r2;

};

int main(int argc, char **argv) {

    ros::init(argc, argv, "DS4_Trigger");

    ros::NodeHandle n;

    //Create DS4_Trigger Object
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