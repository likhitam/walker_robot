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
 *  @file    walk.hpp
 *  @author  Likhita Madiraju
 *  @date    11/20/2018
 *
 *  @brief Programming Assignment: Week 12, Working with Gazebo
 *
 *  @section DESCRIPTION
 *
 * Learning to use ROS Kinetic with Gazebo for simulating TurtleBot to
 * implement a simple walker algorithm.
 * Define the functions to run TurtleBot and process laser values
 */

#ifndef INCLUDE_WALK_HPP_
#define INCLUDE_WALK_HPP_

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"

class Walk {
 public:
  /**
   *   @brief Default constructor
   *   @param none
   *   @return none
   */
  Walk();
  /**
   *   @brief Default destructor
   *   @param none
   *   @return none
   */
  ~Walk();
  /**
   *   @brief This function is used to obtain laser data
   *   @param message of type LaserScan
   *   @return none
   */
  void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
  /**
   *   @brief This function is used to run the robot
   *   @param none
   *   @return none
   */
  void run();

 private:
  geometry_msgs::Twist msg;
  ros::NodeHandle n;
  ros::Publisher velocityPub;
  ros::Subscriber sub;
  int obstacle;
  float linspeedX;
  float angspeedZ;
};

#endif  // INCLUDE_WALK_HPP_
