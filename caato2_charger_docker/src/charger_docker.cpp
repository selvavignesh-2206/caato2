/**
 * @file charger_docker.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "caato2_charger_docker/charger_docker.h"
#include <geometry_msgs/Twist.h>
#include "tf/transform_datatypes.h"
#include <math.h>

ChargerDocker::ChargerDocker(std::string name) {

}

ChargerDocker::~ChargerDocker(void) {
}

void ChargerDocker::poseSubscriberCB(const geometry_msgs::PoseWithCovarianceStamped& msg) 
{
    current_pose = msg.pose.pose;
}

void ReverseDocker::stopVel() 
{
  geometry_msgs::Twist cmd_vel_msg;
  cmd_vel_msg.angular.z = 0;
  cmd_vel_msg.linear.x = 0;
  coarse_cmd_vel_pub.publish(cmd_vel_msg);
  ros::spinOnce();
}

//-----------------------------------------------------------
void DockingLogic::moveForward(ros::Publisher& cmd_vel_pub) \
{
    
    geometry_msgs::Twist cmd_vel_msg;
    cmd_vel_msg.linear.x = 0.4;
    coarse_cmd_vel_pub.publish(cmd_vel_msg);
    ros::spinOnce();


}
void DockingLogic::moveAngular(ros::Publisher& cmd_vel_pub) {

    if (alpha_rad != 0.0)
    {
        goal_angle = odom_angle + alpha_rad;

        N = (int) goal_angle/M_PI;

        rest = goal_angle - ((float)N * M_PI);

        if ((rest > 0) && (N >0)) 
        {
            /// TODO 

        }

        rad_velocity = (alpha_rad < 0) ? -0.5 : 0.5;

        weiter = true;

        while (weiter) {

            geometry_msgs::Twist base;

            base.linear.x = 0.0;
            base.angular.z = rad_velocity;

            cmd_vel_pub.publish(base);

            ros::Duration(0.5).sleep();
            
            epsilon = goal_angle - angle;

            if (epsilon > 0.1)
            {
                weither = true;
            } 
            else 
            {
                weither = false;
            }
        }

    }
}

// ---------------------------------------------------------------------
void DockingLogic::actualAngle (const nav_msgs::Odometry& msg) {

    tf2::Quaternion q;

    geometery_msgs::Twist odom_reading;

    odom_reading.angular.x = 
    msg->pose.pose.orientation.x
}

// ---------------------------------------------------------------------
void DockingLogic::driveForward (double distance) {

    velocity = 0.15;

    time_to_wait = distance/velocity;

   /*
    * @m the gradient of the line after using
    * standard square method
    * @c is the y-intercept of the line
    */
    error = m * log(distance * 100) - c

    dt = error/(velocity*100);

    if (td > 0)
    {
        time_to_wait += dt;
    }
    else
    {
        velocity = 0.05;

        time_to_wait = distance/velocity;

        error  = (0.395 * (distance * 100)) - 0.079

        dt = error/(velocity*100);

        time_to_wait += dt;

        startTime = Time::now()

        while ((Time::now() - startTime) < time_to_wait) 
        {
            drive_forward(velocity)
            Duration(0.5).sleep()
        }
    }
}

// ---------------------------------------------------------------------
void DockingLogic::linearApproach (const ) {

    geometry_msgs::Pose current_pose = 
    geometry_msgs::Point current_point = p.position;

    float x_pos = current_point.x;
    float y_pos = current_point.y;
    float z_pos = current_point.z;

    float epsilon = x_pos / fabst(x_pos);

    float beta = M_PI/2.0 - epsilon;

    float d = y_pos - fabst(x_pos) * tan()

    if (d < min_distance) 
    {
        moveAngle(M_PI);
        driveForward(0.5);
        moveAngle(-M_PI);
        linearApproach();
        break;
    } 
    else 
    {
        moveAngle(epsilon);
        alpha = 2 * M_PI;
        E = 0.3;

        while (alpha > E) 
        {
            alpha = ;
            driveForward();
        }
        moveAngle(-epsilon);
    }

}

// ---------------------------------------------------------------------
void DockingLogic::frontalDocking (/*TODO*/) {

    alpha_boundary = 2.0 * (M_PI/180.0);

    if (alpha_dock > alpha_docking)
    {
        omega = 2.0 * (M_PI/180.0);
    }
    else if (alpha_dock > -alpha_docking)
    {
        omega = -1.2 * (M_PI/180.0);   
    }
    else
    {
        omega = 0.0
    }

    /* @v param is the driven velocity */
    v = 0.07

    if (y_pos > stop_distance)
    {
        move(omega, v);
        frontalDocking();
    }                    
    else 
    {
        adjust();

        if (!is_recharging)
        {
            driveForward(-0.65);
            frontalDocking();
        }

        break;
    }  
}

