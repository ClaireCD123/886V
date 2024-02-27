#include "main.h"
#include "pros/distance.hpp"

void shooterOn(){
	shooter = -100; 
   
}
void shooterOff(){
	shooter = 0; 
}

void armUp(double time){
    arm1=-100;
    arm2=-100;
    delay(time);
    arm1=0;
    arm2=0;
}

void armDown(double time){
    arm1=100;
    arm2=100;
    delay(time);
    arm1=0;
    arm2=0;
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
void move_backward(double distance, int time, double kP){
    startTimer(1);
    resetDriveSensors();
    double error = distance - left_front.get_position();
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
    double kp = 2.0;
    while(fabs(error) >= 2 && time >= getTime(3)){
          error = degrees - imu.get_rotation();
        powerDrive(0, kp*error);
    }
    powerDrive(0, 0);
}

//__________________________________________________________

void AWPdefensive(){
	move_forward(250,1000);
    delay(200);
    wings.set_value(1);
    delay(500);
    turn(-50,1000);
    delay(300);
    wings.set_value(0);
    delay(300);
    turn(-100,1000);
    delay(300);
    move_backward(300,1000,1.3);
    delay(300);
    turn(16,1000);
    delay(300);
    move_backward(1777,3800,1.3);
    delay(300);
    move_forward(700,1000);
    delay(300);
    turn(-40,1000);
    delay(200);
    move_forward(1111,1000);
    delay(200);
    turn(-10,1000);
    delay(200);
    move_forward(1600,1000);
}

// __________________________________________________

void AWPoffensive(){
    move_backward(3000,1000,1.3);
    move_forward(200,1000);
    move_backward(500,1000,1.3);
    move_forward(200,1000);

}

//______________________________________________________


void AutoSkills(){
	/* SKILLS AUTONOMOUS */
    hang.set_value(1);
	move_backward(1500, 3000,1.3);
	delay(500);
	move_forward(300,1000); //prepare for second push
	delay(500);
	move_backward(1000, 1000,1.3); //second push
	delay(500);
	move_forward(400,1000);
	delay(500);
	turn(-88,1500);
	delay(800);
    wings.set_value(1);
	move_backward(300,1000,1.3);
    armUp(600);
	shooterOn(); //turn on flywheel 
	delay(14000);
    armUp(300);
	shooterOff(); //turn off flywheel
    armDown(666);
	wings.set_value(0);
	delay(500);
	turn(40, 1000);
	delay(500);
	move_forward(1900,1000);
	delay(500);
	turn(-20, 1000);
	delay(500);
	move_forward(3500,1111); //going to other side
	delay(300);
    turn(11,1000);
	move_forward(3500,1000); //.
	delay(500);
	move_backward(400,1000,1.3);
	delay(500);
	move_forward(1000, 1000);
	delay(500);
	move_backward(300,1000,1.3);
	delay(500);
	turn(-75, 1000);
	delay(500);
	move_forward(2000,1000);
	delay(500);
	turn(-28, 1000);
	wings.set_value(1);
	move_backward(1700,1000,1.3);
	delay(500);
	wings.set_value(0);
	delay(300);
	move_forward(1000,1000);
	delay(500);
	turn(-75, 1000);
	delay(300);
	move_backward(600,1000,1.3);
	delay(300);
	wings.set_value(1);
	delay(500);
	turn(77,1000);
	delay(500); 
	move_backward(1300, 1000,1.3);
	delay(500);  
	move_forward(500,1000);
	delay(500);
	move_backward(700,1000,1.3); 
}

//_________________________________________________________

void defensive(){
    hang.set_value(1);
    armUp(111);
    move_forward(2000,1000);
    delay(300);
    turn(30,1000);
    grabber=65;
    move_forward(333,1000);
    delay(300);
    turn(-22,1000);
    delay(300);
    move_backward(2000,1000,1);
    delay(500);
    turn(50,1000);
    move_forward(555,1000);
    delay(500);
    grabber=-65;
    delay(300);
    move_forward(880,1000);
    delay(1000);
    grabber=0;
}

//___________________________________________________________

void idk(){
    move_backward(2000,4100,0.1);



}