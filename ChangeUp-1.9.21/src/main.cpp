#include "main.h"
using namespace okapi;
/*------------------------------------
  __  __         _
 |  \/  |  __ _ (_) _ __
 | |\/| | / _` || || '_ \
 | |  | || (_| || || | | |
 |_|  |_| \__,_||_||_| |_|

Created on 7/14/2020 by Logan and Taylor
Last Updated on 1/8/2021 by Logan

The Main function Initializes the program as it starts.
It starts autonomous, driver control and everything competition.
It is the most important program because it references all others.

------------------------------------*/

// ---------------- INITIALIZE ---------------- //
// Sets up all sensors, motors and tasks.       //
// Starts all tasks.                            //
// Initializes autonomous selector.             //
// Turns optical sensor lights to max.          //
void initialize() {
  pros::Task controllerDisplay(contDisplay);  // Start Controller display to see info

  // AutoSelect();  //Start Brain autonomous selector to select before autonomous period
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
  encCallibrate=0;
  while(encCallibrate<200){
    encCallibrate+=1;
    pros::delay(1);
  }
}


// ---------------- AUTONOMOUS ---------------- //
// The robot drives on its own.                 //
// Starts autnomous from a chosen autonomous.   //
void autonomous() {

  // ----------- HOME ROW ----------- //
  // 15 second autonomous             //
  // 2 Red balls                      //
  // 2 Blue ball                      //
  // 3 Goals                          //
  // Home row bonus                   //
  if(autoSel=="a_HR1_HMC_HL1_MM1")
    a_HR1_HMC_HL1_MM1();
  // -------------------------------- //

  // ----------- HOME MIDDLE CYCLE + LEFT CYCLE ----------- //
  // 15 second autonomous                                   //
  // 2 Red balls                                            //
  // 2 Blue ball                                            //
  // 2 Goals                                                //
  else if(autoSel=="a_HMC_HLC")
    a_HMC_HLC();
  // ----------------------------------------------------- //

  // ----------- HOME MIDDLE + LEFT CYCLE + CENTER ----------- //
  // 15 second autonomous                                      //
  // 3 Red balls                                               //
  // 1 Blue ball                                               //
  // 3 Goals                                                   //
  // Center Goal                                               //
  else if(autoSel=="a_HMC_HRC")
    a_HMC_HRC();
  // --------------------------------------------------------- //

  // ----------- RIGHT CYCLE ----------- //
  // 10 second autonomous                //
  // 2 Red balls                         //
  // 1 Blue balls                        //
  // 1 Goal                              //
  else if(autoSel=="a_MMF_HLC_HMC")
    a_MMF_HLC_HMC();
  // ----------------------------------- //

  // ----------- SKILLS ----------- //
  // 1 minute autonomous            //
  // 11 Red balls                   //
  // 7 Blue balls                   //
  // 9 Goals                        //
  else if(autoSel=="Skills")
    A_SKILLS_JANUARY();
  // ------------------------------ //

  // ----------- DEFAULT ----------- //
  else
  // a_HMC_HRC();
  // a_HMC_HLC();
  // a_HR1_HMC_HL1_MM1();
  // a_MMF_HLC_HMC();
  a_SKILLS_BROKEN_ARM_DISTANCE_FILTER();
  // ------------------------------- //
}


// ---------------- DRIVER CONTROL ---------------- //
// Robot is driven by a human.                      //
// Run the robot based on joystick and button inputs//
// Display Odometry details.                        //

void opcontrol() {
  drive->setState({86.5_in,14.5_in,180_deg});   //Set the state for odometry

// Continually update the screen to show OdomDebug information.
  while(true){

    //get the subsystems on the robot
    setDeliveryMotor();
    setIntakeMotors();
    setLiftMotor();
    setDriveMotors(1);

    extraDriver();
    pros::delay(20); //wait for motors to update
  }
}
