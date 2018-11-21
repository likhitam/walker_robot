# walker_robot
<p align="left">
<a href='https://opensource.org/licenses/MIT'><img src='https://img.shields.io/badge/License-MIT-brightgreen.svg'/></a>
</p>

## Project Description

This project uses ROS Kinetic Version with C++11 features to create a package for controlling turtleBot using a simple walker algorithm in Gazebo.

## Assumptions 
1. ROS Kinetic Version is used for this project.
2. catkin is a build for ROS that is used for this project.

## Build Steps 
Please execute the following commands to build the package:

```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone --recursive https://github.com/likhitam/walker_robot.git
cd ..
catkin_make

```

## Running Steps
Please execute the following steps after building the package to run it:
1. Open two terminals.
2. Make sure that a roscore is up and running.
3. In the first terminal execute the following commands: 

```
cd ~/catkin_ws
catkin_make
source ./devel/setup.bash
roscore

```
4. Now let us launch walk node

```
cd ~/catkin_ws
source ./devel/setup.bash
roslaunch walker_robot launch.launch

```

5. Launch with enabling recording of the message generated on the topic chatter by running the following command:
```
roslaunch walker_robot launch.launch record:=true
```
To launch without recording the messages execute the followig command:
```
roslaunch walker_robot launch.launch record:=false
```
To play the recorded messages execute in the results folder the following command:
```
cd ~/catkin_ws/src/beginner_tutorials/results
rosbag play record.bag
```

6. The talker and listener nodes will continuously run. To end the process enter CTRL+C in both three terminals.
