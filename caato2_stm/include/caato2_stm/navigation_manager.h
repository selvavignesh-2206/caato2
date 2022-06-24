#ifndef NAVIGATION_MANAGER_H
#define NAVIGATION_MANAGER_H

#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class NavigationManager
{
    public:

    NavigationManager();

    void navigate_manager_server_run();

    private:

    MoveBaseClient ac{"move_base", true};

};

#endif