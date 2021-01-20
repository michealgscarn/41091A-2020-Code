#include "main.h"
using namespace okapi;
/*
     _                _   _  __  __  _             _   _  _      ____             __  __  __  __  _
    / \              | | | ||  \/  |/ |           | | | || |    / ___|           |  \/  ||  \/  |/ |
   / _ \     _____   | |_| || |\/| || |   _____   | |_| || |   | |       _____   | |\/| || |\/| || |
  / ___ \   |_____|  |  _  || |  | || |  |_____|  |  _  || |___| |___   |_____|  | |  | || |  | || |
 /_/   \_\           |_| |_||_|  |_||_|           |_| |_||_____|\____|           |_|  |_||_|  |_||_|
Autonomous       Home row | Middle | 1 Ball     Home row | Left | Cycle               Center    | 1 Ball

Created on 10/10/2021 by Logan and Taylor
Updated on 1/19/2021 by Logan and Taylor

15 second Autonomous

2 Red balls
1 Blue balls
2 Goals

Best used with a partner who consistanty scores the Home Left Goal

PREPARE THE PROGRAM
-------------------
Set up the robot's Odometry positon.

GOAL 1
------
Line up with the Home middle Goal and score preload

GOAL 2
------
Line up with the Home left Goal and pick up Ball
Score picked up Ball into the Home left Goal

GOAL 3
------
Drive towards Center Goal and push a Ball in

 */
void a_HM1_HLC_MM1(){

// ---------- Preparation ---------- //
  //Capture the start time so we can score at the last moment
  startTime=pros::millis();
  drive->setState({55.5_in,14_in,180_deg});   //Set the state for odometry


// ---------- Goal 1 (Home Row Wall) ---------- //
  // ----- Goal ----- //
  DriveCoordShort(70.8,29,180,1); // Line up with the Home middle Goal
  setDelivery(20);  // Unfold Hood
  DriveCoordShort(70.8,19.4,180,1); // Drive into the Home middle Goal
  setDelivery(127); // Spin the Delivery forward to Score The Ball
  setLift(127); // Spin the Lift forward to Deliver
  pros::delay(600); // Wait for 0.6 seconds to score


// ---------- Goal 2 (Home Row Left Corner) ---------- //
  // ----- Goal ----- //
  DriveCoordShort(34.5,40,221,2); // Line up with the Home left Goal
  setIntake(-127);    //Run intakes backwards to deploy
  setLift(0); // Stop the Lift
  setDelivery(0); // Stop the Delivery
  pros::delay(1000);  // Wait for Intake to unfold
  setIntake(127); // Spin the Intake forward to pick up Ball
  maxSpeed=100; // Drive slowly
  DriveCoordShort(14,16,223,2); // Drive into Goal
  FilterBall("",3); // Cycle Goal until the Robot has the opposing alliance's Ball


// ---------- Goal 3 (Center) ---------- //
  // ------ Goal ----- //
  setIntake(-127);  // Spin the Intake in reverse to prevent pulling out a Ball
  pros::delay(500); // Wait for Ball to be scored
  setLift(0); // Continue Lift to filter
  setDelivery(0); // Continue Delivery to filter
  maxSpeed=600; // Drive Faster
  DriveCoordShort(27,28,223,1.5); //Back from goal
  setIntake(0); // Stop Intake
  DriveCoordShort(64.5,58,370,2.5); // Push Ball into Goal
  setIntake(-5);  // Spin intake in reverse
  DriveCoordShort(38.9,44,364,1); // Back Away from Goal
}
