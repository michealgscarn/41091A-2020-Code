#include "main.h"
 using namespace okapi;
//HELPER FUNCTIONS
void setLift(int power){
  lift_mtr = power;
}

 //LIFT CONTROL FUNCTIONS
 void setLiftMotor(){
   //Set lift speed based on button presses
   int power = 100 * controller.get_digital(DIGITAL_R1) + 127 * (controller.get_digital(DIGITAL_R2) + controller.get_digital(DIGITAL_L1) - (controller.get_digital(DIGITAL_L2) ) );
   setLift(power);
 }
