#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
  __  __         _
 |  \/  |  __ _ (_) _ __
 | |\/| | / _` || || '_ \
 | |  | || (_| || || | | |
 |_|  |_| \__,_||_||_| |_|

Created on 7/14/2020 by Logan and Taylor
Last Updated on 1/28/2021 by Logan

The Main function Initializes the program as it starts.
It starts autonomous, driver control and everything competition.
It is the most important program because it references all others.

-----------------------------------------------------------------------------*/

// ---------------- INITIALIZE ---------------- //
// Sets up all sensors, motors and tasks.       //
// Starts all tasks.                            //
// Initializes autonomous selector.             //
// Turns optical sensor lights to max.          //
void initialize() {
  pros::Task controllerDisplay(contDisplay);  // Start Controller display to see info

  pros::Task screenUpdate(legacyDisplayGrid); // Display information to the Brain

  pros::Task ballUpdate(ballCountTask); // Update ball count since the start of the program
  pros::Task filterUpdate(filterCountTask); // Update filter count since the start of the program

  // Set the Optical Flashlights as max
  bottomColor.set_led_pwm(100);
  middleColor.set_led_pwm(100);
  topColor.set_led_pwm(100);
}


// ---------------- DISABLED ---------------- //
// Period of program when robot is disabled.  //
void disabled() {
}


 // ---------------- COMPETITION INITIALIZE ---------------- //
 // Initialize sensors and others at the start of a comp.    //
 // Don't start autonous until the encoders are callibrated. //
 void competition_initialize() {
   pros::delay(200);
  encCallibrate=200;
}


// ---------------- AUTONOMOUS ---------------- //
// The robot drives on its own.                 //
// Starts autnomous from a chosen autonomous.   //
void autonomous() {

  // ----------- HOME ROW ----------- //
  // 15 second autonomous             //
  // Used When Partner Has No Auto    //
  // 3 Red balls                      //
  // 3 Blue balls                     //
  // 3 Goals                          //
  // 6 points + Auto Bonus Point      //
  // Home row bonus                   //
  if(autoSel=="a_HRC_HMC_HLC")
    a_HRC_HMC_HLC();
  // -------------------------------- //

  // ----------- HOME MIDDLE CYCLE + LEFT CYCLE + CENTER ----------- //
  // 15 second autonomous                                            //
  // Used When Partner Gets Right Corner Goal                        //
  // 3 Red balls                                                     //
  // 2 Blue balls                                                    //
  // 3 Goals                                                         //
  // 5 points                                                        //
  else if(autoSel=="a_HMC_HLC_MM1")
    a_HMC_HLC_MM1();
  // --------------------------------------------------------------- //

  // ----------- HOME MIDDLE + LEFT CYCLE + CENTER ----------- //
  // 15 second autonomous                                      //
  // Used When Partner Gets Left Corner Goal                   //
  // 3 Red balls                                               //
  // 2 Blue balls                                              //
  // 2 Goals                                                   //
  // 5 points                                                  //
  else if(autoSel=="a_HMC_HRC")
    a_HMC_HRC();
  // --------------------------------------------------------- //

  // ----------- FILL CENTER + CYCLE LEFT CORNER ----------- //
  // 15 second autonomous                                    //
  // Used when Partner Gets Right + Middle                   //
  // 4 Red balls                                             //
  // 1 Blue balls                                            //
  // 2 Goals                                                 //
  // 4 points                                                //
  else if(autoSel=="a_MMF_HLC")
    a_MMF_HLC();
  // ------------------------------------------------------- //

  // ----------- SKILLS ----------- //
  // 1 minute autonomous            //
  // 11 Red balls                   //
  // 9 Blue balls                   //
  // 9 Goals                        //
  // 113 Points                     //
  else if(autoSel=="Skills")
    a_SKILLS_BROKEN_ARM_DISTANCE_FILTER_IGNITE();
  // ------------------------------ //

  // ----------- DEFAULT ----------- //
  // If there is no auto selected    //
  // Run the default autonomous      //
  else
  a_SKILLS_BROKEN_ARM_DISTANCE_FILTER_IGNITE();
  // ------------------------------- //
}


// ---------------- DRIVER CONTROL ---------------- //
// Robot is driven by a human.                      //
// Run the robot based on joystick and button inputs//
// Display Odometry details.                        //

void opcontrol() {

// Continually update the screen to show OdomDebug information.
  while(true){

    // get the subsystems on the robot
    setDeliveryMotor();
    setIntakeMotors();
    setLiftMotor();
    setDriveMotors(1.5);

    // Utilize the remaining Controller Buttonns
    extraDriver();
    pros::delay(10); //wait for motors to update
  }
}
