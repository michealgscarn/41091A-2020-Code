
#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
  __  __         _
 |  \/  |  __ _ (_) _ __
 | |\/| | / _` || || '_ \
 | |  | || (_| || || | | |
 |_|  |_| \__,_||_||_| |_|

Created on 7/14/2020 by Logan and Taylor
Last Updated on 3/5/2021 by Logan

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
  // ----- Controller ----- //
  pros::Task controllerDisplay(controllerDisplaySel);  // Start Controller display to see info
  pros::Task controllerVibrate(controllerVibrateTemp);  // Start Controller vibration to see info
  // ----- Brain ----- //
  pros::Task brainDisplay(brainDisplayAlign); // Display information to the Brain
  // ----- Ball Updates ----- //
  pros::Task ballUpdate(ballCountTask); // Update ball count since the start of the program
  // pros::Task ballExitUpdate(ballExitCountTask); // Update ball count since the start of the program
  pros::Task filterUpdate(filterCountTask); // Update filter count since the start of the program
  // ----- Optical Flashlights ----- //
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

  // ----- HOME LEFT CYCLE + CENTER + MIDDLE RIGHT CYCLE -------------------- //
  // 15 second autonomous                                                     //
  // Used when partner consistantly scores in Home Left and Home Right        //
  if(autoSel=="a_HLC_MM1_MRC")
  a_HLC_MM1_MRC();
  // ------------------------------------------------------------------------ //

  // ----- HOME LEFT CYCLE + CENTER + HOME RIGHT CYCLE ---------------------- //
  // 15 second autonomous                                                     //
  // Used When Partner Gets Right Corner Goal                                 //
  else if(autoSel=="a_HLC_MM1_HRC")
  a_HLC_MM1_HRC();
  // ------------------------------------------------------------------------ //

  // ----- HOME RIGHT CYCLE + HOME MIDDLE CYCLE + CENTER -------------------- //
  // 15 second autonomous                                                     //
  // Used when partner consistantly scores in Home Left                       //
  else if(autoSel=="a_HRC_HMC_MM2")
  a_HRC_HMC_MM2();
  // ------------------------------------------------------------------------ //

  // ----- HOME ROW CYCLE --------------------------------------------------- //
  // 15 second autonomous                                                     //
  // Used when partner has no consistant auto                                 //
  else if(autoSel=="a_HRC_HMC_HLC")
  a_HRC_HMC_HLC_D();
  // ------------------------------------------------------------------------ //

  // ------ HOME LEFT CYCLE + HOME MIDDLE CYCLE + CENTER -------------------- //
  // 15 second autonomous                                                     //
  // Used when partner consistantly scores in Home Right                      //
  else if(autoSel=="a_HLC_HMC_MM2")
  a_HLC_HMC_MM2();
  // ------------------------------------------------------------------------ //

  // ----- HOME RIGHT + CENTER ---------------------------------------------- //
  // 15 second autonomous                                                     //
  // Used when partner consistantly score Home Middle and Home Left           //
  else if(autoSel=="a_HRC_MM2")
  a_HRC_MM2();
  // ------------------------------------------------------------------------ //

  // ----- HOME LEFT CYCLE + CENTER ----------------------------------------- //
  // 15 second autonomous                                                     //
  // Used when partner consistantly score Home Middle and Home Right          //
  else if(autoSel=="a_HLC_MM2")
  a_HLC_MM2();
  // ------------------------------------------------------------------------ //

  // ----- SKILLS ----------------------------------------------------------- //
  // 1 minute autonomous                                                      //
  // Skills Autonomous                                                        //
  else if(autoSel=="Skills")
    A_SKILLS_JANUARY_FEBRUARY_2021();
  // ------------------------------------------------------------------------ //

  // ----- DEFAULT ---------------------------------------------------------- //
  // If there is no auto selected                                             //
  // Run the default autonomous                                               //
  else
  A_SKILLS_JANUARY_FEBRUARY_2021();
  // ------------------------------------------------------------------------ //
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
    extraDriver();

    pros::delay(10); //wait for motors to update
  }
}
