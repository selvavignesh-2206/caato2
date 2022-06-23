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
from geometry_msgs.msg import PoseWithCovarianceStamped
import tf_conversions

from caato2_stm.srv import *

import json



class NavGoal(BaseModel):
    nav_goal_x: float
    nav_goal_y: float
    nav_goal_z: float

class PoseResp(BaseModel):
    pose_x: float
    pose_y: float
    pose_theta: float

pose_resp = PoseResp(pose_x='0.0', pose_y='0.0', pose_theta='0.0')

app = FastAPI()

threading.Thread(target=lambda: rospy.init_node('fleet_client_node', disable_signals=True)).start()

def pose_sub_callback(data):
    pose_resp.pose_x = data.pose.pose.position.x
    pose_resp.pose_y = data.pose.pose.position.y
    rpy = tf_conversions.transformations.euler_from_quaternion([data.pose.pose.orientation.x, data.pose.pose.orientation.y, data.pose.pose.orientation.z, data.pose.pose.orientation.w])
    pose_resp.pose_theta = rpy[2]
    rospy.loginfo("successfully callback")
    return

rospy.Subscriber("amcl_pose", PoseWithCovarianceStamped, pose_sub_callback)


@app.get('/')
async def root():
    rospy.loginfo("server test!")
    # movebase_client(27.2, 9.90, 0.99)
    return {"connected": "True"}

@app.get('/position')
def position():
    return pose_resp, 200


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
    rospy.loginfo("Current State: " + client.get_goal_status_text())
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