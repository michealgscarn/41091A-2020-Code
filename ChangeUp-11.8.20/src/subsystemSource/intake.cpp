#include "main.h"
 using namespace okapi;
//HELPER FUNCTIONS
void setIntake(int power){
  left_int_mtr = power;
  right_int_mtr = power;
}

 //INTAKE CONTROL FUNCTIONS
 void setIntakeMotors(){
   //Set intake speed based on button presses
   int power = 127 * (controller.get_digital(DIGITAL_L1) - controller.get_digital(DIGITAL_L2)-controller.get_digital(DIGITAL_A));
   setIntake(power);
 }
