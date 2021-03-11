#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _              _   _  _      ____           __  __  __  __  _           __  __  ____    ____
    / \            | | | || |    / ___|         |  \/  ||  \/  |/ |         |  \/  ||  _ \  / ___|
   / _ \    _____  | |_| || |   | |      _____  | |\/| || |\/| || |  _____  | |\/| || |_) || |
  / ___ \  |_____| |  _  || |___| |___  |_____| | |  | || |  | || | |_____| | |  | ||  _ < | |___
 /_/   \_\         |_| |_||_____|\____|         |_|  |_||_|  |_||_|         |_|  |_||_| \_\ \____|
Autonomous       Home row \ Left \ Cycle         Center Goal  \ 1 Ball  Middle Row \ Right \ Cycle

Created on 2/22/2021 by Logan and Taylor
Updated on 3/5/2021 by Logan and Taylor

15 second Autonomous

2 Red balls
3 Blue balls
3 Goals

Best used with a partner who consistanty scores the Home Middle and Right

GOAL 1
------
Drive into the Left corner Goal and score preload.
Cycle Goal until the Robot has the opposing alliance's Ball.
Filter Ball

GOAL 2
------
Drive towards the Center Goal and strafe to push ball in

GOAL 3
------
Drive towards the Autononous Line Right Goal and line up with Goal
Cycle the Autonomous Line Right Goal until the robot has both opposing alliance's Ball.

-----------------------------------------------------------------------------*/
void a_HLC_MM1_MRC(){
// ---------- Set Up ---------- //
  startTime=pros::millis(); // Set up a timer for autonomous
  drive->setState({27_in,13_in,-90_deg});   //Set the state for odometry
  maxSpeed=500; // Set the robot's speed as fast
  filter=true;  // Filter Ball after Cycling

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  DriveCoordShort(29,33,-133,1);  // Line up with the Home right Goal
  setLift(127);
  setIntake(-127);  // Unfold Intake
  pros::delay(800); // Wait for Intake and Delivery
  setLift(0);
  setIntake(80);  // Spin Intake to pick up Balls
  maxSpeed=100;  // Drive Slowly into Goals
  DriveCoordShort(12,16,-135.6,0.75);  // Drive into the Home right Goal
  cycleScore(3,5,1);  // Cycle Goal until opposing ball is picked up

  // ---------- GOAL 2 ---------- //
  // ----- Goal ----- //
    maxSpeed=80; // Speed up the Robot
    resetY=22;  // Set Y postion
    pros::Task lo(lineReset); // Begin line reset
    DriveCoordShort(25,25,-141.7,0.75); // Back away from Goal
    maxSpeed=500;
    setIntake(-20); // Spin in Reverse to Push ball into middle
    DriveCoordShort(58,57,-3.5,2); // Push Ball into Center Goal

// ---------- GOAL 3 ---------- //
  // ----- Ball & Goal ----- //
  DriveCoordShort(40,45,79.9,1.4); // Back away from Goal
  maxSpeed=150;

  DriveCoordShort(109.8,54,90,1.8); // Line up with Middle Right Goal
  DriveCoordShort(119.0,54,43.6,0.8);  // Get ready to cycle Middle Right Goal

  setIntake(127);
  maxSpeed=100; //  Slow down the Robot for Precision
  left_fr_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  left_bc_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_fr_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_bc_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  DriveCoordShort(125,61.5,50,0.75); // Drive into the Middle Right Goal
  setDrive(0,0,0,0);
  filter=false;
  cycleScore(3,3,1);  // Cycle Middle Right Goal
  cycleScoreSide(1,3,1);  // Cycle Middle Right Goal

  maxSpeed=500; // Speed up the Robot
  pros::delay(1);
  setIntake(-127);  // Prevent picking up alliance ball
  setLift(0); // Stop Lift
  setDelivery(0); // Stop Delivery
  DriveCoordShort(119,53,43.6,2);  // Get ready to cycle Middle Right Goal
}
