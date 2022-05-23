
# CAATO2 
#### _(aka Changi Airport Autonomous Trolley Operator V2)_

### About
The CAATO is a Autonomous Ground Vehicle (AGV) developed for the testing of ROS2/[RMF](https://github.com/open-rmf). It's small footprint allows for additional payloads for various use-cases. Earlier for V1, CAATO was designed primarily to fit with a modular trolley docking mechanism to collect trolleys in Changi Airport.

### Installation
This installation assumes you have the following installed:
 1. [ROS1 Noetic](http://wiki.ros.org/noetic/Installation/Ubuntu)  
 2. [Github SSH key](https://careerkarma.com/blog/git-permission-denied-publickey/:~:text=Conclusion-,The%20%E2%80%9CPermission%20denied%20%28publickey%29.,add%20your%20key%20to%20Git) is already setup
```bash
#depedencies
sudo apt update && sudo apt install \
  git cmake python3-vcstool curl \
  qt5-default libmodbus-dev python3-colcon*\
  python3-rosdep \
  -y
  
python3 -m pip install flask-socketio

# creating your workspace
mkdir -p ~/caato2_ws/src
cd ~/caato2_ws

#get list of repositories and import to src
wget https://raw.githubusercontent.com/TRL-RMF/caato2/samuel/caato2_devel/caato2.repos
vcs import src < caato2.repos

# more dependencies + building
rosdep install --from-paths src --ignore-src --rosdistro noetic -y
source /opt/ros/noetic/setup.bash
colcon build --cmake-args -DCMAKE_BUILD_TYPE=Release
```

### Common commands
```
roslaunch caato2_gazebo caato2_mbc.launch
roslaunch atc_stm astm.frontbackAT.noGDB.launch
```
