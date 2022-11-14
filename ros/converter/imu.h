#pragma once
#ifndef ROSWRAPPER_CONVERTER_IMU_H
#define ROSWRAPPER_CONVERTER_IMU_H

#include "modules/sensordata/imu.h"
#include <sensor_msgs/Imu.h>

namespace converter {

void to_ros_msg(sensor_msgs::Imu& msg, const sensordata::IMU& data) {
  msg.header.stamp.fromSec(data.time);
  msg.angular_velocity.x    = data.gyr.x();
  msg.angular_velocity.y    = data.gyr.y();
  msg.angular_velocity.z    = data.gyr.z();
  msg.linear_acceleration.x = data.acc.x();
  msg.linear_acceleration.y = data.acc.y();
  msg.linear_acceleration.z = data.acc.z();
  msg.orientation.w         = data.rot.w();
  msg.orientation.x         = data.rot.x();
  msg.orientation.y         = data.rot.y();
  msg.orientation.z         = data.rot.z();
}

void from_ros_msg(const sensor_msgs::Imu& msg, sensordata::IMU& data) {
  data.time    = msg.header.stamp.toSec();
  data.gyr.x() = msg.angular_velocity.x;
  data.gyr.y() = msg.angular_velocity.y;
  data.gyr.z() = msg.angular_velocity.z;
  data.acc.x() = msg.linear_acceleration.x;
  data.acc.y() = msg.linear_acceleration.y;
  data.acc.z() = msg.linear_acceleration.z;
  data.rot.w() = msg.orientation.w;
  data.rot.x() = msg.orientation.x;
  data.rot.y() = msg.orientation.y;
  data.rot.z() = msg.orientation.z;
}

}  // namespace converter

#endif  // ROSWRAPPER_CONVERTER_IMU_H