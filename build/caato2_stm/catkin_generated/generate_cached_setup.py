# -*- coding: utf-8 -*-
from __future__ import print_function

import os
import stat
import sys

# find the import for catkin's python package - either from source space or from an installed underlay
if os.path.exists(os.path.join('/opt/ros/noetic/share/catkin/cmake', 'catkinConfig.cmake.in')):
    sys.path.insert(0, os.path.join('/opt/ros/noetic/share/catkin/cmake', '..', 'python'))
try:
    from catkin.environment_cache import generate_environment_script
except ImportError:
    # search for catkin package in all workspaces and prepend to path
    for workspace in '/home/dimsum/caato2_ws/install/xnergy_charger_rcu;/home/dimsum/caato2_ws/install/trolley_arm;/home/dimsum/caato2_ws/install/teleop_twist_joy;/home/dimsum/caato2_ws/install/rviz_atc_plugins;/home/dimsum/caato2_ws/install/rosserial_xbee;/home/dimsum/caato2_ws/install/rosserial_windows;/home/dimsum/caato2_ws/install/rosserial_vex_v5;/home/dimsum/caato2_ws/install/rosserial_vex_cortex;/home/dimsum/caato2_ws/install/rosserial_tivac;/home/dimsum/caato2_ws/install/rosserial_test;/home/dimsum/caato2_ws/install/rosserial_server;/home/dimsum/caato2_ws/install/rosserial_arduino;/home/dimsum/caato2_ws/install/rosserial_python;/home/dimsum/caato2_ws/install/rosserial_mbed;/home/dimsum/caato2_ws/install/rosserial_embeddedlinux;/home/dimsum/caato2_ws/install/rosserial_chibios;/home/dimsum/caato2_ws/install/rosserial_client;/home/dimsum/caato2_ws/install/rosserial_msgs;/home/dimsum/caato2_ws/install/caato_teleop;/home/dimsum/caato2_ws/install/caato_slam;/home/dimsum/caato2_ws/install/caato_navigation;/home/dimsum/caato2_ws/install/caato_bringup;/home/dimsum/caato2_ws/install/caato2_navigation;/home/dimsum/caato2_ws/install/caato2_examples;/home/dimsum/caato2_ws/install/caato2_bringup;/home/dimsum/caato2_ws/install/roboteq_diff_driver;/home/dimsum/caato2_ws/install/roboteq_diff_msgs;/home/dimsum/caato2_ws/install/realsense_gazebo_plugin;/home/dimsum/caato2_ws/install/realsense2_description;/home/dimsum/caato2_ws/install/realsense2_camera;/home/dimsum/caato2_ws/install/plc_modbus_node;/home/dimsum/caato2_ws/install/ouster_example;/home/dimsum/caato2_ws/install/ouster-gazebo-simulation;/home/dimsum/caato2_ws/install/map_server;/home/dimsum/caato2_ws/install/laser_filters;/home/dimsum/caato2_ws/install/ira_laser_tools;/home/dimsum/caato2_ws/install/eband_local_planner;/home/dimsum/caato2_ws/install/ds4_driver;/home/dimsum/caato2_ws/install/device_diagnostics;/home/dimsum/caato2_ws/install/decada_sim_assets;/home/dimsum/caato2_ws/install/caato_gazebo;/home/dimsum/caato2_ws/install/caato_fleet_client;/home/dimsum/caato2_ws/install/caato_description;/home/dimsum/caato2_ws/install/caato_alexa;/home/dimsum/caato2_ws/install/caato2_reverse_docker;/home/dimsum/caato2_ws/install/caato2_stm;/home/dimsum/caato2_ws/install/caato2_gazebo;/home/dimsum/caato2_ws/install/caato2_description;/home/dimsum/caato2_ws/install/atc_waypoints;/home/dimsum/caato2_ws/install/atc_stm;/home/dimsum/caato2_ws/install/atc_utils;/home/dimsum/caato2_ws/install/atc_msgs;/home/dimsum/caato2_ws/install/apriltag_ros;/home/dimsum/caato2_ws/install/Project;/opt/ros/noetic'.split(';'):
        python_path = os.path.join(workspace, 'lib/python3/dist-packages')
        if os.path.isdir(os.path.join(python_path, 'catkin')):
            sys.path.insert(0, python_path)
            break
    from catkin.environment_cache import generate_environment_script

code = generate_environment_script('/home/dimsum/caato2_ws/src/caato2/build/caato2_stm/devel/env.sh')

output_filename = '/home/dimsum/caato2_ws/src/caato2/build/caato2_stm/catkin_generated/setup_cached.sh'
with open(output_filename, 'w') as f:
    # print('Generate script for cached setup "%s"' % output_filename)
    f.write('\n'.join(code))

mode = os.stat(output_filename).st_mode
os.chmod(output_filename, mode | stat.S_IXUSR)
