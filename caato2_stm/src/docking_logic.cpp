#include "caato2_stm/docking_logic.h"

void driveForward (double distance) {

    velocity = 0.15;

    time_to_wait = distance/velocity;

    error = m * log(distance * 100) - 

    dt = error/(velocity*100);

    if (td > 0)
    {
        time_to_wait += dt;
    }
    else
    {
        velocity = 0.05;

        time_to_wait = distance/velocity;

        error  = (0.395 * (distance * 100)) - 0.079

        dt = error/(velocity*100);

        time_to_wait += dt;

        startTime = Time::now()

        while ((Time::now() - startTime) < time_to_wait) 
        {
            drive_forward 
        }
    }
}

void linearApproach (const ) {

    geometry_msgs::Pose current_pose = 
    geometry_msgs::Point current_point = p.position;

    float x_pos = current_point.x;
    float y_pos = current_point.y;
    float z_pos = current_point.z;

    float epsilon = x_pos / fabst(x_pos);

    float beta = M_PI/2.0 - epsilon;

    float d = y_pos - fabst(x_pos) * tan()

    if (d < min_distance) 
    {
        moveAngle(M_PI);
        driveForward(0.5);
        moveAngle(-M_PI);
        linearApproach();
        break;
    } 
    else 
    {
        moveAngle(epsilon);
        alpha = 2 * M_PI;
        E = 0.3;

        while (alpha > E) 
        {
            alpha = ;
            driveForward();
        }
        moveAngle(-epsilon);
    }

}

void frontalDocking (....) {

    alpha_boundary = 2.0 * (M_PI/180.0);

    if (alpha_dock > alpha_docking)
    {
        omega = 2.0 * (M_PI/180.0);
    }
    else if (alpha_dock > -alpha_docking)
    {
        omega = -1.2 * (M_PI/180.0);   
    }
    else
    {
        omega = 0.0
    }

    /* @v param is the driven velocity */
    v = 0.07

    if (y_pos > stop_distance)
    {
        move(omega, v);
        frontalDocking();
    }                    
    else 
    {
        adjust();

        if (!is_recharging)
        {
            driveForward(-0.65);
            frontalDocking();
        }

        break;
    }  
}