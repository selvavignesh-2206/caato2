#include <ros/ros.h>
#include "caato2_charger_docker/charger_docker.h"

int main(int argc, char** argv) {

    ros::init(argc, argv, "charger_docker");

    ChargerDocker charger_docker(ros::this_node::getName());

    ros::spin();

    return 0;
}