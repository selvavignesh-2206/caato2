#include <ros/ros.h>
#include "caato2_reverse_docker/reverse_docker.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "reverse_docker");

  ReverseDocker reverse_docker(ros::this_node::getName());
  ros::spin();

  return 0;
}

