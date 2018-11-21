/************************************************************************
 MIT License
 Copyright (c) 2018 Likhita Madiraju
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 *************************************************************************/

/**
 *  @copyright MIT License 2018 Likhita Madiraju
 *  @file    walk.cpp
 *  @author  Likhita Madiraju
 *  @date    11/20/2018
 *
 *  @brief Programming Assignment: Week 12, Working with Gazebo
 *
 *  @section DESCRIPTION
 *
 * Learning to use ROS Kinetic with Gazebo for simulating TurtleBot to
 * implement a simple walker algorithm.
 * Defined run function.
 */

#include <iostream>
#include <walk.hpp>

Walk::Walk() {
  // Attributes of Walk class initialization
  obstacle = 0;
  linspeedX = 0.1;
  angspeedZ = 1.0;
  msg.linear.x = 0.0;
  msg.linear.y = 0.0;
  msg.linear.z = 0.0;
  msg.angular.x = 0.0;
  msg.angular.y = 0.0;
  msg.angular.z = 0.0;
}

Walk::~Walk() {
  // Destructor stub
}

void Walk::laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
  // Proximity of obstacle to TurtleBot
  for (int i = 0; i < msg->ranges.size(); ++i) {
    if (msg->ranges[i] <= 0.75) {
      obstacle = 1;
      return;
    }
  }
  obstacle = 0;
}

void Walk::run() {
  ros::Publisher velocityPub = n.advertise<geometry_msgs::Twist>
                                ("/cmd_vel_mux/input/navi", 1000);
  sub = n.subscribe <sensor_msgs::LaserScan>
       ("/scan", 500, &Walk::laserCallback, this);
  ros::Rate loop_rate(10);

  while (ros::ok()) {
    // Check for collision detection
    if (obstacle == 1) {
      // If collision is detected
      msg.linear.x = 0.0;
      msg.angular.z = angspeedZ;
      ROS_INFO("Collision Detected");
    } else {
      // If there is no collision
      msg.angular.z = 0.0;
      msg.linear.x = linspeedX;
      ROS_INFO("Move forward");
    }
    velocityPub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
