#include "main.h"
 using namespace okapi;
 /*-----------------------------------------------------------------------------
    ___         _          _
  |_ _| _ __  | |_  __ _ | | __ ___
   | | | '_ \ | __|/ _` || |/ // _ \
   | | | | | || |_| (_| ||   <|  __/
  |___||_| |_| \__|\__,_||_|\_\\___|

 Created on 10/14/2020 by Logan and Taylor
 Last Updated on 1/15/2021 by Logan

 Intake Commands in Driver and Autonomous Periods
 Sets the Speeds of the Intake Motors
 Uses the Controller to set the Speed of the Intake

-----------------------------------------------------------------------------*/

 // ---------------- INTAKE VELOCITY ---------------- //
 // Set the speed of the Intake motors.               //

void setIntake(int power){
  // Set the velocity of the Intake motors
  left_int_mtr = power;
  right_int_mtr = power;
}


// ---------------- CONTROLLER INTAKE ---------------- //
// Set the velocity of the Intake using the Controller.//

 void setIntakeMotors(){
   int power = 127 * (controller.get_digital(DIGITAL_L1) - controller.get_digital(DIGITAL_L2));    // Set intake speed based on button presses
   setIntake(power); // Appy the velocity to the Intake
 }
