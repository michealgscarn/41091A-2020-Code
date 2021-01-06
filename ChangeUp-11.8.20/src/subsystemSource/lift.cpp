#include "main.h"
 using namespace okapi;
 /*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

 $$\       $$\  $$$$$$\    $$\
 $$ |      \__|$$  __$$\   $$ |
 $$ |      $$\ $$ /  \__|$$$$$$\
 $$ |      $$ |$$$$\     \_$$  _|
 $$ |      $$ |$$  _|      $$ |
 $$ |      $$ |$$ |        $$ |$$\
 $$$$$$$$\ $$ |$$ |        \$$$$  |
 \________|\__|\__|         \____/

Created By Logan and Taylor
Last Updated By Logan

LIFT SPEED
----------
Set the velocity of the Lift motor.

CONTROLLER LIFT
---------------
Set the velocity of the Lift based on Controller input

 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

// $$$$$$$$$$$$$$$$ LIFT SPEED $$$$$$$$$$$$$$$$ //
// Set the velocity of the Lift motor.          //

void setLift(int power){
  lift_mtr = power; //Set the velocity of the Lift
}

// $$$$$$$$$$$$$$$$ CONTROLLER LIFT $$$$$$$$$$$$$$$$ //
// Set the velocity of the Lift using the Controller.//

 void setLiftMotor(){
   int power = 100 * controller.get_digital(DIGITAL_R1) + 127 * (controller.get_digital(DIGITAL_R2) + controller.get_digital(DIGITAL_L1) - (controller.get_digital(DIGITAL_L2) ) ); // Set lift velocity based on button presses
   setLift(power); // Apply the velocity of the the Lift
 }
