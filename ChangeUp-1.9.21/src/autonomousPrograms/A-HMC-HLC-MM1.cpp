#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _                _   _  __  __   ____             _   _  _      ____             __  __  __  __  _
    / \              | | | ||  \/  | / ___|           | | | || |    / ___|           |  \/  ||  \/  |/ |
   / _ \     _____   | |_| || |\/| || |       _____   | |_| || |   | |       _____   | |\/| || |\/| || |
  / ___ \   |_____|  |  _  || |  | || |___   |_____|  |  _  || |___| |___   |_____|  | |  | || |  | || |
 /_/   \_\           |_| |_||_|  |_| \____|           |_| |_||_____|\____|           |_|  |_||_|  |_||_|
Autonomous         Home row | Middle | Cycle     Home row | Left | Cycle               Center    | 1 Ball

Created on 1/25/2021 by Logan and Taylor
Updated on 2/11/2021 by Logan and Taylor

15 second Autonomous

3 Red balls
2 Blue balls
3 Goals

Best used with a partner who consistanty scores the Home Right Goal

PREPARE THE PROGRAM
-------------------
Set up the robot's Odometry positon.

GOAL 1
------
Line up with the Home middle Goal and cycle Goal
Cycle until the Robot has the opposing alliance's Ball
Filter Ball

GOAL 2
------
Line up with the Home left Goal and pick up Ball
Cycle the Home Left Goal until the Robot has the opposing alliance's Ball
Filter Ball

GOAL 3
------
Drive towards Center Goal and push a Ball in

-----------------------------------------------------------------------------*/
void a_HMC_HLC_MM1(){

// ---------- Preparation ---------- //
  //Capture the start time so we can score at the last moment
  startTime=pros::millis();
  drive->setState({57_in,12_in,180_deg});   //Set the state for odometry
  maxSpeed=600;
  filter=true;

// ---------- Goal 1 (Home Row Wall) ---------- //
  // ----- Goal ----- //
  DriveCoordShort(70,30,180,1); // Line up with the Home middle Goal
  setIntake(-127);
  setDelivery(20);  // Unfold Hood
  pros::delay(800); // Wait for Intake and Hood to unfold
  maxSpeed=100;
  DriveCoordShort(70,20.5,180,1); // Drive into the Home middle Goal
  cycleScore(2,3,1);
  maxSpeed=600;
  DriveCoordShort(70,40,180,1); // Line up with the Home middle Goal
  setIntake(0);

// ---------- Goal 2 (Home Row Left Corner) ---------- //
DriveCoordShort(30,33,221,1.75); // Line up with the Home left Goal
  // ----- Goal ----- //
  setLift(0); // Stop the Lift
  setDelivery(0); // Stop the Delivery
  setIntake(50); // Spin the Intake forward to pick up Ball
  maxSpeed=100; // Drive slowly
  DriveCoordShort(14.8,17.2,227,1.5); // Drive into Goal
  cycleScore(3,5,1);


// ---------- Goal 3 (Center) ---------- //
  // ------ Goal ----- //
  maxSpeed=600; // Drive Faster
  DriveCoordShort(27,28,223,1.5); //Back from goal
  setIntake(0); // Stop Intake
  DriveCoordShort(66,62,380,2); // Push Ball into Goal
  setIntake(-5);  // Spin intake in reverse
  DriveCoordShort(38.9,44,364,1); // Back Away from Goal
}
