#include "main.h"
 using namespace okapi;
 /*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

 $$$$$$\            $$\               $$\
 \_$$  _|           $$ |              $$ |
   $$ |  $$$$$$$\ $$$$$$\    $$$$$$\  $$ |  $$\  $$$$$$\
   $$ |  $$  __$$\\_$$  _|   \____$$\ $$ | $$  |$$  __$$\
   $$ |  $$ |  $$ | $$ |     $$$$$$$ |$$$$$$  / $$$$$$$$ |
   $$ |  $$ |  $$ | $$ |$$\ $$  __$$ |$$  _$$<  $$   ____|
 $$$$$$\ $$ |  $$ | \$$$$  |\$$$$$$$ |$$ | \$$\ \$$$$$$$\
 \______|\__|  \__|  \____/  \_______|\__|  \__| \_______|

 Created on 10/14/2020 by Logan and Taylor
 Last Updated on 1/15/2021 by Logan

 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

 // $$$$$$$$$$$$$$$$ INTAKE VELOCITY $$$$$$$$$$$$$$$$ //
 // Set the speed of the Intake motors.               //

void setIntake(int power){
  // Set the velocity of the Intake motors
  left_int_mtr = power;
  right_int_mtr = power;
}


// $$$$$$$$$$$$$$$$ CONTROLLER INTAKE $$$$$$$$$$$$$$$$ //
// Set the velocity of the Intake using the Controller.//

 void setIntakeMotors(){
   int power = 127 * (controller.get_digital(DIGITAL_L1) - controller.get_digital(DIGITAL_L2)-controller.get_digital(DIGITAL_A));    // Set intake speed based on button presses
   setIntake(power); // Appy the velocity to the Intake
 }
