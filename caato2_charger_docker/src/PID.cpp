
#include "caato2_reverse_docker/PID.h"
#include <cmath>
#include <ros/ros.h>

PID::PID(double dt, double max, double min, double Kp, double Kd, double Ki)
{
  pimpl.setValues(dt, max, min, Kp, Kd, Ki);
}

double PID::calculate(double setpoint, double pv)
{
  return pimpl.calculate(setpoint, pv);
}

PID::~PID()
{
}

double PID::getDt()
{
  return pimpl.getDt();
}

void PID::setValues(double dt, double max, double min, double Kp, double Kd, double Ki)
{
  pimpl.setValues(dt, max, min, Kp, Kd, Ki);
}

/**
 * PID Implementation 
 * 
 */

double PIDImpl::calculate(double setpoint, double pv)
{
  // error
  double error = setpoint - pv;

  // Proportional portion
  double Pout = _Kp * error;

  // Integral portion
  _integral += error * _dt;
  double Iout = _Ki * _integral;

  // Derivative portion
  double derivative = (error - _prev_error) / _dt;
  double Dout = _Kd * derivative;

  // Total output
  double output = Pout + Iout + Dout;
  // ROS_INFO("output = %f", output);

  // Limit to max/min
  if (output > _max)
  {
    output = _max;
    // ROS_INFO("more than max %f", _max);
  }
  else if (output < _min)
  {
    // ROS_INFO("less than min %f, actual value %f", _min, output);
    output = _min;
  }

  // Save error to previous error
  _prev_error = error;

  return output;
}

PIDImpl::~PIDImpl()
{
}

PIDImpl::~PIDImpl()
{
}

double PIDImpl::getDt()
{
  return _min;
}

void PIDImpl::setValues(double dt, double max, double min, double Kp, double Kd, double Ki)
{
  _dt = dt;
  _max = max;
  _min = min;
  _Kp = Kp;
  _Kd = Kd;
  _Ki = Ki;
}