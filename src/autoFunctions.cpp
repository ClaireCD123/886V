#include "main.h"
#include "pros/distance.hpp"

void shooterOn(){
	shooter = -127; 
}
void shooterOff(){
	shooter = 0; 
}
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
void move_backward(double distance, int time){
    startTimer(1);
    resetDriveSensors();
    double error = distance - left_front.get_position();
    double kP = 1.3;
    while(fabs(error) >= 4 && time >= getTime(1)){
        error = distance - left_front.get_position();
        powerDrive(error*kP, 0);
    }
    powerDrive(0,0);
}
void move_forward(double distance, int time){
    startTimer(2);
    resetDriveSensors();
    double error = distance + right_front.get_position();
    double kP = 1.3;
    while(fabs(error) >= 4 && time >= getTime(2)){
        error = distance + right_front.get_position();
        powerDrive(-error*kP, 0);
    }
    powerDrive(0,0);
}
void turn(double degrees, int time){
    startTimer(3);
    imu.tare_rotation();
    double error = degrees - imu.get_rotation();
    double kp = 1.2;
    while(fabs(error) >= 2 && time >= getTime(3)){
          error = degrees - imu.get_rotation();
        powerDrive(0, kp*error);
    }
    powerDrive(0, 0);
}

void AWPdefensive(){
	move_forward(800,1000);
    turn(55,1000);
    grabber = 65;
    move_forward(400,1000);


}

void AutoSkills(){
	/* SKILLS AUTONOMOUS */
	move_backward(1500, 3000);
	delay(500);
	move_forward(300,1000); //prepare for second push
	delay(500);
	move_backward(700, 1000); //second push
	delay(500);
	move_forward(500,1000);
	delay(500);
	turn(-90,1500);
	delay(500);
	move_backward(300,1000);
	wings.set_value(1);
	shooterOn(); //turn on flywheel 
	delay(33000);
	shooterOff(); //turn off flywheel
	wings.set_value(0);
	delay(500);
	turn(60, 1000);
	delay(500);
	move_forward(2000,1000);
	delay(500);
	turn(-25, 1000);
	delay(500);
	move_forward(15000,1000);
	delay(300);
	move_forward(3500,1000);
	delay(500);
	move_backward(400,1000);
	delay(500);
	move_forward(700, 1000);
	delay(500);
	move_backward(300,1000);
	delay(500);
	turn(-80, 1000);
	delay(500);
	move_forward(2000,1000);
	delay(500);
	turn(-40, 1000);
	wings.set_value(1);
	move_backward(1700,1000);
	delay(500);
	wings.set_value(0);
	delay(300);
	move_forward(1000,1000);
	delay(500);
	turn(-75, 1000);
	delay(300);
	move_backward(600,1000 );
	delay(300);
	wings.set_value(1);
	delay(500);
	turn(77,1000);
	delay(500); 
	move_backward(1300, 1000);
	delay(500);  
	move_forward(500,1000);
	delay(500);
	move_backward(700,1000); //kills messi
}