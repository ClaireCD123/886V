#include "main.h"
#include "pros/distance.hpp"

void powerDrive(double forwardPower, double turningPower){
    	left_front = forwardPower +  turningPower;
		left_back =  forwardPower + turningPower;
		right_front = forwardPower -  turningPower;   
		right_back = forwardPower -  turningPower;
}
void resetDriveSensors(){
    	left_front.tare_position();
		left_back.tare_position();
		right_front.tare_position();
		right_back.tare_position();
}
void move_backward(double distance){
    resetDriveSensors();
    double error = distance - left_front.get_position();
    double kP = 1.3;
    while(fabs(error) >= 4){
        error = distance - left_front.get_position();
        powerDrive(error*kP, 0);
    }
    powerDrive(0,0);
}
void move_forward(double distance){
    resetDriveSensors();
    double error = distance + right_front.get_position();
    double kP = 1.3;
    while(fabs(error) >= 4){
        error = distance + right_front.get_position();
        powerDrive(-error*kP, 0);
    }
    powerDrive(0,0);
}
void turn(double degrees){
    imu.tare_rotation();
    double error = degrees - imu.get_rotation();
    double kp = 1.2;
    while(fabs(error) >= 2){
          error = degrees - imu.get_rotation();
        powerDrive(0, kp*error);
    }
    powerDrive(0, 0);
}