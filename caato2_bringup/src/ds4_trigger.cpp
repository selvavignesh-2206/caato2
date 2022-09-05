#include <string>
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <geometry_msgs/Twist.h>

class DS4_Trigger 
{
    public:

        DS4_Trigger(ros::NodeHandle &n) {

            ros::NodeHandle private_nh("~");

            //Subscriber
            this->sub = n.subscribe<sensor_msgs::Joy>("/joy", 10, &DS4_Trigger::subscribeDS4, this);

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

        void printTrigger() {

            ROS_INFO("Trigger L2 activated: %d", this->l2);
            ROS_INFO("Trigger R2 activated: %d", this->r2);
        }

    private:

        ros::Subscriber sub;

        double l2, r2;

        double currentL2, currentR2;

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

    // delete ds4_trigger;

    return 0;
}