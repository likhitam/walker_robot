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
 *  @file    main.cpp
 *  @author  Likhita Madiraju
 *  @date    11/20/2018
 *
 *  @brief Programming Assignment: Week 12, Working with Gazebo
 *
 *  @section DESCRIPTION
 *
 * Learning to use ROS Kinetic with Gazebo for simulating TurtleBot to
 * implement a simple walker algorithm.
 */

#include <walk.hpp>

int main(int argc, char **argv) {
  ros::init(argc, argv, "walk");
  // Create an object for Walk
  Walk walk;
  // Call the method to run the robot
  walk.run();
  return 0;
}
