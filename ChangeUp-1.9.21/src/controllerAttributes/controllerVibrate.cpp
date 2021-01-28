#include "main.h"
#include <iostream>
#include<string>
using namespace std;
using namespace okapi;
/*-----------------------------------------------------------------------------
 __     __ _  _                  _
 \ \   / /(_)| |__   _ __  __ _ | |_  ___
  \ \ / / | || '_ \ | '__|/ _` || __|/ _ \
   \ V /  | || |_) || |  | (_| || |_|  __/
    \_/   |_||_.__/ |_|   \__,_| \__|\___|
Created on 1/8/2021 by Logan and Taylor
Last updated on 1/8/2021 by Logan

Alert the driver of events that need attention.  These events include
• Motors Overheating

-----------------------------------------------------------------------------*/
void controllerVibrateTemp(){
  while(true){
    // If any of the motors are overheated
    if(left_fr_mtr.get_temperature()>=55||right_fr_mtr.get_temperature()>=55||
    left_bc_mtr.get_temperature()>=55||right_bc_mtr.get_temperature()>=55||
    lift_mtr.get_temperature()>=55||del_mtr.get_temperature()>=55||
    left_int_mtr.get_temperature()>=55||right_int_mtr.get_temperature()>=55)
    {
      controller.rumble("-");
    }
    pros::delay(10);
  }
}
