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
from geometry_msgs.msg import PoseWithCovarianceStamped, Pose, Quaternion
from actionlib_msgs.msg import GoalStatusArray
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
status_msg = 0

app = FastAPI()

threading.Thread(target=lambda: rospy.init_node('fleet_client_node', disable_signals=True)).start()

def pose_sub_callback(data):
    global pose_resp
    pose_resp.pose_x = data.pose.pose.position.x
    pose_resp.pose_y = data.pose.pose.position.y
    rpy = tf_conversions.transformations.euler_from_quaternion([data.pose.pose.orientation.x, data.pose.pose.orientation.y, data.pose.pose.orientation.z, data.pose.pose.orientation.w])
    pose_resp.pose_theta = rpy[2]
    rospy.loginfo("successfully callback")
    return

def move_base_callback(data):
    global status_msg
    if len(data.status_list) > 0:
        status_msg = data.status_list[len(data.status_list)-1].status
    rospy.loginfo("successfully callback for status")
    return

rospy.Subscriber("amcl_pose", PoseWithCovarianceStamped, pose_sub_callback)

rospy.Subscriber("move_base/status", GoalStatusArray, move_base_callback)


@app.get('/')
async def root():
    rospy.loginfo("server test!")
    return {"connected": "True"}

@app.get('/position')
def position():
    return pose_resp

@app.get('/device_status')
def device_status():
    return 0.8 

command_robot = rospy.ServiceProxy('cmd_vel_mux', change_robot_state)
command_navigation_robot = rospy.ServiceProxy('caato_nav_goal', navigate_goal)
#commands added by Selva for docking 
#command_dock = rospy.ServiceProxy('start_dock', )

def navigate_goal(nav_goal_x, nav_goal_y, nav_goal_theta):
    pose_goal = Pose()
    pose_goal.position.x = nav_goal_x
    pose_goal.position.y = nav_goal_y
    q = tf_conversions.transformations.quaternion_from_euler(0.0,0.0,nav_goal_theta)
    pose_goal.orientation = Quaternion(*q)
    try:
        resp1 = command_navigation_robot(pose_goal)
        return resp1.success
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)
        return e
    return False



@app.post('/navigate')
def navigate(navgoal: NavGoal):
    command_robot(1)
    resp = navigate_goal(navgoal.nav_goal_x, navgoal.nav_goal_y, navgoal.nav_goal_z)
    return resp

@app.post('/start_process')
def start_process():
    return 'true'

@app.post('/stop')
def stop():
    rospy.wait_for_service('cmd_vel_mux')
    try:
        resp1 = command_robot(0)
        return ''
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)
        return "Service call failed: %s"%e

@app.post('/pause_navigation')
def pause():
    rospy.wait_for_service('cmd_vel_mux')
    try:
        resp1 = command_robot(2)
        return ''
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)
        return "Service call failed: %s"%e

@app.post('/resume_navigation')
def resume():
    rospy.wait_for_service('cmd_vel_mux')
    try:
        resp1 = command_robot(1)
        return ''
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)
        return "Service call failed: %s"%e

@app.get('/navigation_status')
def get_navigation_status():
    try:
        return {"navigation_status_code" : status_msg}
    except rospy.ServiceException as e:
        print("call failed: %s"%e)
        return "call failed: %s"%e

@app.post('/start_docking')
def start_docking():
    try:
        #resp1 = command_robot(5)
        return ''
    except rospy.ServiceException as e:
        print("Service call to dock failed: %s"%e)
        return "Service call to dock failed: %s"%e

@app.get('/docking_status')
def get_docking_status():
    try:
        return {"docking_status_code"}
    except rospy.ServiceException as e:
        print("docking status call failed: %s"%e)
        return "docking status call failed: %s"%e

if __name__ == '__main__':
    try:
        uvicorn.run(app, host="0.0.0.0", port=3030, log_level="info")
        # rospy.spin()
    except rospy.ROSInterruptException:
        pass