#! /usr/bin/env python

import os
import rospy
import threading

from fastapi import FastAPI
import uvicorn
from pydantic import BaseModel

# Brings in the SimpleActionClient
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal

from caato2_stm.srv import *

import json

class NavGoal(BaseModel):
    nav_goal_x: float
    nav_goal_y: float
    nav_goal_z: float

app = FastAPI()

threading.Thread(target=lambda: rospy.init_node('fleet_client_node', disable_signals=True)).start()

@app.get('/')
async def root():
    rospy.loginfo("move_base!")
    # movebase_client(27.2, 9.90, 0.99)
    return {"message": "Hello World"}


def movebase_client(nav_goal_x, nav_goal_y, nav_goal_z):

    rospy.loginfo("move_base starting!")
   # Create an action client called "move_base" with action definition file "MoveBaseAction"
    client = actionlib.SimpleActionClient('move_base',MoveBaseAction)
 
   # Waits until the action server has started up and started listening for goals.
    client.wait_for_server()

   # Creates a new goal with the MoveBaseGoal constructor
    goal = MoveBaseGoal()
    goal.target_pose.header.frame_id = "map"
    goal.target_pose.header.stamp = rospy.Time.now()
   # Move 0.5 meters forward along the x axis of the "map" coordinate frame 
    goal.target_pose.pose.position.x = nav_goal_x
    goal.target_pose.pose.position.y = nav_goal_y
   # No rotation of the mobile base frame w.r.t. map frame
    goal.target_pose.pose.orientation.w = nav_goal_z

   # Sends the goal to the action server.
    client.send_goal(goal)
   # Waits for the server to finish performing the action.
    wait = client.wait_for_result()
   # If the result doesn't arrive, assume the Server is not available
    if not wait:
        rospy.logerr("Action server not available!")
        rospy.signal_shutdown("Action server not available!")
    else:
    # Result of executing the action
        rospy.loginfo("move_base completed!")
        return client.get_result()   

command_robot = rospy.ServiceProxy('cmd_vel_mux', change_robot_state)

@app.post('/navigate')
def navigate(navgoal: NavGoal):
    # nav_goal = request.get_json()
    movebase_client(navgoal.nav_goal_x, navgoal.nav_goal_y, navgoal.nav_goal_z)
    # movebase_client(nav_goal["nav_goal_x"], nav_goal["nav_goal_y"], nav_goal["nav_goal_z"])
    return 200

@app.post('/start_process')
def start_process():
    return '', 204

@app.post('/stop')
def stop():
    rospy.wait_for_service('cmd_vel_mux')
    try:
        resp1 = command_robot(0)
        return '', 200
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)
        return "Service call failed: %s"%e,200

@app.post('/pause_navigation')
def pause():
    rospy.wait_for_service('cmd_vel_mux')
    try:
        resp1 = command_robot(2)
        return '', 200
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)
        return "Service call failed: %s"%e,200

@app.post('/resume_navigation')
def resume():
    rospy.wait_for_service('cmd_vel_mux')
    try:
        resp1 = command_robot(1)
        return '', 200
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)
        return "Service call failed: %s"%e,200


if __name__ == '__main__':
    try:
        uvicorn.run(app, host="127.0.0.1", port=5000, log_level="info")
        rospy.spin()
    except rospy.ROSInterruptException:
        pass