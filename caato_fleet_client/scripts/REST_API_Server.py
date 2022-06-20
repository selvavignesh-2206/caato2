#! /usr/bin/env python

import os
import rospy
import threading

from fastapi import FastAPI
import uvicorn


# Brings in the SimpleActionClient
import actionlib
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal

import json

app = FastAPI()

threading.Thread(target=lambda: rospy.init_node('fleet_client_node', disable_signals=True)).start()

nav_goal = [
    {'nav_goal_x': 0, 'nav_goal_y': 0, 'nav_goal_z': 0}
]

@app.get('/')
async def root():
    rospy.loginfo("I AM ALIVE!")
    return {"message": "Hello World"}


def movebase_client(nav_goal_x, nav_goal_y, nav_goal_z):

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
        return client.get_result()   

@app.route('/navigate', methods=['POST'])
def navigate():
    nav_goal = request.get_json()
    movebase_client(nav_goal["nav_goal_x"], nav_goal["nav_goal_y"], nav_goal["nav_goal_z"])
    return '', 204

@app.route('/start_process', methods=['POST'])
def start_process():
    return '', 204

@app.route('/stop', methods=['POST'])
def stop():
    return '', 204


if __name__ == '__main__':
    try:
        uvicorn.run(app, host="127.0.0.1", port=5000, log_level="info")
        rospy.spin()
    except rospy.ROSInterruptException:
        pass