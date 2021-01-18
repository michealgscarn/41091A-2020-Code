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
  if(autoSel=="HR1-HMC-HL1-MM1")
    a_HMP_HL1_HR1();
  // -------------------------------- //

  // ----------- HOME MIDDLE CYCLE + LEFT CYCLE ----------- //
  // 15 second autonomous                                   //
  // 2 Red balls                                            //
  // 2 Blue ball                                            //
  // 2 Goals                                                //
  else if(autoSel=="HMC-HLC-MM1")
    // a_HMC_HLC_MM1();
    pros::delay(0);
  // ----------------------------------------------------- //

  // ----------- HOME MIDDLE + LEFT CYCLE + CENTER ----------- //
  // 15 second autonomous                                      //
  // 3 Red balls                                               //
  // 1 Blue ball                                               //
  // 3 Goals                                                   //
  // Center Goal                                               //
  else if(autoSel=="HMP-HLC-MM1")
    A_HMP_HLC_MM1();
  // --------------------------------------------------------- //

  // ----------- RIGHT CYCLE ----------- //
  // 10 second autonomous                //
  // 2 Red balls                         //
  // 1 Blue balls                        //
  // 1 Goal                              //
  else if(autoSel=="HMC-HRC")
    a_HRF();
  // ----------------------------------- //

  // ----------- HOME MIDDLE CYCLE + RIGHT CYCLE ----------- //
  // 15 second autonomous                                      //
  // 2 Red balls                                               //
  // 2 Blue balls                                              //
  // 2 Goals                                                   //
  else if(autoSel=="MMF-HLC")
    a_HMC_HRC();
  // --------------------------------------------------------- //

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
  // a_HR1_HMC_HL1_MM1();
  a_MMF_HLC_HMC();
  // a_SKILLS_BROKEN_ARM_DISTANCE_FILTER_115();
  // ------------------------------- //

  // switch (auton_sel) {
   //  // ----------- HOME ROW ----------- //
   //  // 15 second autonomous             //
   //  // 2 Red balls                      //
   //  // 2 Blue ball                      //
   //  // 3 Goals                          //
   //  // Home row bonus                   //
   //  case 1:
   //    a_HMP_HL1_HR1();
   //  break;
   //  // -------------------------------- //
   //
   // // ----------- HOME MIDDLE CYCLE + LEFT CYCLE ----------- //
   // // 15 second autonomous                                   //
   // // 2 Red balls                                            //
   // // 2 Blue ball                                            //
   // // 2 Goals                                                //
   //  case 2:
   //    a_HMC_HLC();
   //  break;
   //  // ----------------------------------------------------- //
   //
   //  // ----------- HOME MIDDLE + LEFT CYCLE + CENTER ----------- //
   //  // 15 second autonomous                                      //
   //  // 3 Red balls                                               //
   //  // 1 Blue ball                                               //
   //  // 3 Goals                                                   //
   //  // Center Goal                                               //
   //  case 3:
   //    A_HMP_HLC_MM1();
   //  break;
   //  // --------------------------------------------------------- //
   //
   //  // ----------- RIGHT CYCLE ----------- //
   //  // 10 second autonomous                //
   //  // 2 Red balls                         //
   //  // 1 Blue balls                        //
   //  // 1 Goal                              //
   //  case 4:
   //    a_HRF();
   //  break;
   //  // ----------------------------------- //
   //
   //  // ----------- HOME MIDDLE CYCLE + RIGHT CYCLE ----------- //
   //  // 15 second autonomous                                      //
   //  // 2 Red balls                                               //
   //  // 2 Blue balls                                              //
   //  // 2 Goals                                                   //
   //  case 5:
   //    a_HMC_HRC();
   //  break;
   //  // --------------------------------------------------------- //
   //
   //  // ----------- SKILLS ----------- //
   //  // 1 minute autonomous            //
   //  // 11 Red balls                   //
   //  // 7 Blue balls                   //
   //  // 9 Goals                        //
   //  case 6:
   //    a_SKILLS_BROKEN_ARM_DISTANCE_FILTER();
   //  break;
   //  // ------------------------------ //
   //
   //  // ----------- DEFAULT ----------- //
   //  default:
   //  // a_HR1_HMC_HL1_MM1();
   //  a_MMF_HLC_HMC();
   //  // a_SKILLS_BROKEN_ARM_DISTANCE_FILTER_115();
   //  break;
   //  // ------------------------------- //
}


// ---------------- DRIVER CONTROL ---------------- //
// Robot is driven by a human.                      //
// Run the robot based on joystick and button inputs//
// Display Odometry details.                        //

void opcontrol() {
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
