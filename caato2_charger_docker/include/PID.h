/**
 * @file PID.h
 * @author Selva 
 * @param Kp - proportional gain
 * @param Ki - Integral gain
 * @param Kd - Derivative gain
 * @param dt - loop interval time
 * @param max - maximum value of manipulated variable
 * @param min - minimum value of manipulated variable 
 * @version 0.1
 * @date 2022-08-30
 * @copyright Copyright (c) 2022
 */

#ifndef PID_H
#define PID_H

class PIDImpl {

    public:
        
        void setValues(double dt, double max, double min, double Kp, double Kd, double Ki);

        double getDt();

        double calculate(double setpoint, double pv);

        PIDImpl();

        ~PIDImpl();

    private:

        double _dt, _max, _min, _Kp, _Kd, _Ki, _prev_error, _integral;

}

class PID {

    public:

        void setValues(double dt, double max, double min, double Kp, double Kd, double Ki);

        double getDt();

        PID(double dt, double max, double min, double Kp, double Kd, double Ki);

        double calculate( double setpoint, double pv );

        ~PID();

    private:

        PIDImpl pimpl{0.0,0.0,0.0,0.0,0.0,0.0};

};


#endif