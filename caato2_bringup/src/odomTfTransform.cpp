// By Selva, July 6 For Odom Tranforms 
#include <ros/ros.h>
#include <geometry_msgs/TransformStamped.h>
#include <nav_msgs/Odometry.h>

geometry_msgs::TransformStamped tf_stamped;

void odomCallback(const nav_msgs::Odometry &msg) {
   nav_msgs::Odometry odometry_ = msg;

   tf_stamped.header = odometry_.header;
// sam: tried this bottom line to fix the atc_stm transform but didn't work
//    tf_stamped.header.stamp = ros::Time(0) + ros::Duration(0.2);
   tf_stamped.child_frame_id = odometry_.child_frame_id;
   tf_stamped.transform.translation.x = odometry_.pose.pose.position.x;
   tf_stamped.transform.translation.y = odometry_.pose.pose.position.y;
   tf_stamped.transform.translation.z = odometry_.pose.pose.position.z;
   tf_stamped.transform.rotation = odometry_.pose.pose.orientation;

}

int main(int argc, char** argv) {
    ros::init(argc, argv, "odom_tf");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("odom",100, odomCallback);
    ros::Publisher pub = nh.advertise<geometry_msgs::TransformStamped>("odom_transformed",100);
    

    ros::Rate rate(100);

    while(ros::ok()) {
    pub.publish(tf_stamped);
    ros::spinOnce();
    rate.sleep();
    }
    return 0;
}
