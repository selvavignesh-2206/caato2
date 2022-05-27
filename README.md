
# CAATO2 
#### _(aka Changi Airport Autonomous Trolley Operator V2)_

### About
The CAATO is a Autonomous Ground Vehicle (AGV) developed for the testing of ROS2/[RMF](https://github.com/open-rmf). It's small footprint allows for additional payloads for various use-cases. Earlier for V1, CAATO was designed primarily to fit with a modular trolley docking mechanism to collect trolleys in Changi Airport.

### Installation
This installation assumes you have the following installed:
 1. [ROS1 Noetic](http://wiki.ros.org/noetic/Installation/Ubuntu)  
 2. [Github SSH key](https://careerkarma.com/blog/git-permission-denied-publickey/) is already setup
 3. [Realsense SDK 2.0](https://github.com/IntelRealSense/librealsense/blob/master/doc/distribution_linux.md) - will be covered below in case

#### Realsense Installation 
adapted from original repo but included for ease of installation.
```bash
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE || sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE
```
```bash
sudo add-apt-repository "deb https://librealsense.intel.com/Debian/apt-repo $(lsb_release -cs) main" -u
```
```bash
sudo apt-get install librealsense2-dkms librealsense2-utils librealsense2-dev librealsense2-dbg -y
```

#### CAATO2 Packages Installation
```bash
#depedencies
sudo apt update && sudo apt install \
  git cmake python3-vcstool curl \
  qt5-default libmodbus-dev python3-colcon*\
  python3-rosdep python3-pip \
  ros-noetic-ddynamic-reconfigure\
  ros-noetic-base-local-planner\
  ros-noetic-move-base-msgs\
  -y
``` 
```bash
python3 -m pip install flask-socketio
```
```bash
# creating your workspace
mkdir -p ~/caato2_ws/src
cd ~/caato2_ws
```
```bash
#get list of repositories and import to src
wget https://raw.githubusercontent.com/TRL-RMF/caato2/samuel/caato2_devel/caato2.repos
vcs import src < caato2.repos
```
```bash
# more dependencies + building
sudo rosdep init
rosdep update
rosdep install --from-paths src --ignore-src --rosdistro noetic -y
```
```bash
source /opt/ros/noetic/setup.bash
colcon build 
```

### Potential Errors
```bash
Could not determine ref type of version : git@github.com: Permission denied (publickey). 
fatal: Could not read from remote repository... 
```
If you get the above error, you need to make you sure set up your Github SSH key as mentioned in requirement #2. Once set up, git clone a random repository to test if the ssh works. When prompted with your ECDSA key fingerprint, make sure you click "yes" to wanting to continue connecting. After that the vcs import src < caato2.repos step should work fine.

### Additional dependencies for some systems
```bash
sudo apt-get install ros-noetic-desktop-full ros-noetic-map-server ros-noetic-amcl ros-noetic-move-base ros-noetic-dwa-local-planner -y
```

### Common commands
```
roslaunch caato2_gazebo caato2_mbc.launch
roslaunch atc_stm astm.frontbackAT.noGDB.launch
```
