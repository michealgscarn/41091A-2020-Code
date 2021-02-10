#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
  ____         _              _                _
 |  _ \  _ __ (_)__   __ ___ | |_  _ __  __ _ (_) _ __
 | | | || '__|| |\ \ / // _ \| __|| '__|/ _` || || '_ \
 | |_| || |   | | \ V /|  __/| |_ | |  | (_| || || | | |
 |____/ |_|   |_|  \_/  \___| \__||_|   \__,_||_||_| |_|

Created on 8/14/2020 by Logan and Taylor
Last Updated on 1/15/2021 by Logan

Drivetrain Commands in Driver and Autonomous Periods
Sets the Speeds of the Drive Motors
Uses the Controller to set the Speed of the Drivetrain in
• Robot-centeric Movements
• Field-centric Movements

-----------------------------------------------------------------------------*/

// ---------------- DRIVETRAIN VELOCITY ---------------- //
// Set the velocity of the Drivetrain motors.               //
void setDrive(double leftFront, double leftBack, double rightFront, double rightBack){

  left_fr_mtr = leftFront;
  left_bc_mtr = leftBack;
  right_fr_mtr = rightFront;
  right_bc_mtr = rightBack;
}


// ---------------- CONTROLLER DRIVETRAIN ---------------- //
// Set the velocity of the Drivetrain using the Controller.//
// Stop motors if the velocity is very small.              //
void setDriveMotors( double driveSpeed ){
  // Set drive velocity based on button presses
  int left_fr_pow = (controller.get_analog(ANALOG_LEFT_Y)+controller.get_analog(ANALOG_RIGHT_X)+controller.get_analog(ANALOG_LEFT_X))*driveSpeed;
  int left_bc_pow = (controller.get_analog(ANALOG_LEFT_Y)+controller.get_analog(ANALOG_RIGHT_X)-controller.get_analog(ANALOG_LEFT_X))*driveSpeed;
  int right_fr_pow = (controller.get_analog(ANALOG_LEFT_Y)-controller.get_analog(ANALOG_RIGHT_X)-controller.get_analog(ANALOG_LEFT_X))*driveSpeed;
  int right_bc_pow = (controller.get_analog(ANALOG_LEFT_Y)-controller.get_analog(ANALOG_RIGHT_X)+controller.get_analog(ANALOG_LEFT_X))*driveSpeed;

  // Stop the motors if the the controller is a small value to reduce drift
  if (abs(left_fr_pow) < 10)
    left_fr_pow = 0;
  if (abs(left_bc_pow) < 10)
    left_bc_pow = 0;
  if (abs(right_fr_pow) < 10)
    right_fr_pow = 0;
  if (abs(right_bc_pow) < 10)
    right_bc_pow = 0;

  // Apply the speed to the Drivetrain
  setDrive(left_fr_pow, left_bc_pow,right_fr_pow,right_bc_pow);
}


// ---------------- FIELD CENTRIC CONTROLLER ---------------- //
// Drive using Controller input.                              //
// Run the motors using the field centric algorithm.          //
void setDriveMotorsFieldCentric(){
  // Input the X, Y, and theta speed
  DriveFieldCentric(controller.get_analog(ANALOG_LEFT_X),controller.get_analog(ANALOG_LEFT_Y),controller.get_analog(ANALOG_RIGHT_X));
}
