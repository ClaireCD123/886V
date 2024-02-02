#include "main.h"

int timeSlot[5] = {0,0,0,0,0};

void startTimer(int slot){
    timeSlot[slot] = pros::millis();
}

double getTime(int slot){
 return(pros::millis() - timeSlot[slot]);
}