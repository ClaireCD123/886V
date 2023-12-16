#include "main.h"

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_front(20);
    pros::Motor left_back(10);
	pros::Motor right_front(11);
	pros::Motor right_back(1);
	pros::Motor shooter(6);
	pros::Motor grabber(2);
	pros::Motor arm(9);


	
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
/*double inches_to_ticks(double inches){
	double internal =(double)900,   
	external = (double)1,
	diameter =4.125,
	pi = 3.1415926;

	return ((inches/pi/diameter/external*internal));
}


void drive_forward(double distance){
int target = inches_to_ticks(distance);
	left_mtr.tare_position();
	while(target>left_mtr.get_position()){
left_mtr	= 127;
right_mtr	= 127;
	}
left_mtr	= -5;
right_mtr	= -5;
delay(99.9);
left_mtr	= 0;
right_mtr	= 0;
delay (1000);
}



void turn_right(double distance){
int target = inches_to_ticks(distance);
	left_mtr.tare_position();
	while(target>left_mtr.get_position()){
left_mtr	= 127;
right_mtr	= -127;
	}
left_mtr	= -5;
right_mtr	= 5;
delay(99.9);    
left_mtr	= 0;
right_mtr	= 0;
delay (1000);
}

void turn_left(double distance){
int target = inches_to_ticks(distance);
	left_mtr.tare_position();
	while(-target<left_mtr.get_position()){
left_mtr	= -127;
right_mtr	= 127;
	}
left_mtr	= 5;
right_mtr	= -5;
delay(99.9);
left_mtr	= 0;
right_mtr	= 0;

}
void drive_backward(double distance){
int target = inches_to_ticks(distance);
	left_mtr.tare_position();
	while(target>left_mtr.get_position()){
left_mtr	= -127;
right_mtr	= -127;
	}
left_mtr	= 5;
right_mtr	= 5;
delay(99.9);
left_mtr	= 0;
right_mtr	= 0;

}

// void raise_arm(){
// arm_mtr.move_absolute(height,100);
// }







void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
//
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
/**
drive_forward
turn 90 degrees right
drive_forward
turn 90 degrees right
drive_forward
drive_backward
turn 90 degrees left
drive_forward
raise_arm
drive_backward
turn 180 degrees right 
drive_forward
lower_arm
drive_backward
raise_arm 
drive_forward
SECOND     
drive_backward
turn 90 degrees left
drive_forward
turn 90 degrees left
drive_forward
raise_arm
drive_backward
turn 180 degrees right
turn 90 degrees right
drive_forward
turn 90 degrees left
drive_forward
lower_arm
drive_backward
raise_arm
drive_forward
THIRD
drive_backward
lower_arm
turn 90 degrees right
drive_forward
turn 90 degrees right
drive_forward
raise_arm
drive_backward
turn 180 degrees right
drive_forward
turn 90 degrees left
drive_forward
turn 90 degrees right
drive_forward
lower_arm
drive_backwards
raise_arm 
drive_forward
*/



}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	double leftX;
	double leftY;
	while (true) {
		leftY = master.get_analog(ANALOG_LEFT_Y);
		leftX = -master.get_analog(ANALOG_LEFT_X);
		left_front = leftY + leftX;
		left_back = leftY + leftX;
		right_front = -leftY + leftX;   
		right_back = -leftY + leftX;

		if(master.get_digital(DIGITAL_X) == 1){
			shooter = -130w;
		}else if(master.get_digital(DIGITAL_Y) == 1){
		
			shooter = 0;
		}
		if(master.get_digital(DIGITAL_R2) == 1){
			arm = 100;
		}else if(master.get_digital(DIGITAL_R1) == 1){
			arm = -100;
		}else{
			arm = 0;
		}
		if(master.get_digital(DIGITAL_L2) == 1){
			grabber = 100;
		}else if(master.get_digital(DIGITAL_L1) == 1){
			grabber = -120;
		}else{
			grabber = 0;
		}
	}
} 
