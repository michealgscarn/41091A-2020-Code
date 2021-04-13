#include "main.h"
 using namespace okapi;
 /*-----------------------------------------------------------------------------
   _      _   __  _
  | |    (_) / _|| |_
  | |    | || |_ | __|
  | |___ | ||  _|| |_
  |_____||_||_|   \__|

Created on 8/14/2020 by Logan and Taylor
Last Updated on 1/15/2021 by Logan

Lift Commands in Driver and Autonomous Periods
Sets the Speed of the Lift Motor
Uses the Controller to set the Speed of the Lift

-----------------------------------------------------------------------------*/

// ---------------- LIFT SPEED ---------------- //
// Set the velocity of the Lift motor.          //
void setLift(int power){
  lift_mtr = power; //Set the velocity of the Lift
}


// ---------------- CONTROLLER LIFT ---------------- //
// Set the velocity of the Lift using the Controller.//
 void setLiftMotor(){
   int power = 70 * controller.get_digital(DIGITAL_R1) + !controller.get_digital(DIGITAL_R1)*(127 * (controller.get_digital(DIGITAL_R2) + controller.get_digital(DIGITAL_L1) - (controller.get_digital(DIGITAL_L2) ) ) ); // Set lift velocity based on button presses
   // int power = 0; // Set lift velocity based on button presses
   setLift(power); // Apply the velocity of the the Lift
 }
