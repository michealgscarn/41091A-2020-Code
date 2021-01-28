#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _                _   _  ____    ____             _   _  __  __   ____             _   _  _      ____
    / \              | | | ||  _ \  / ___|           | | | ||  \/  | / ___|           | | | || |    / ___|
   / _ \     _____   | |_| || |_) || |       _____   | |_| || |\/| || |       _____   | |_| || |   | |
  / ___ \   |_____|  |  _  ||  _ < | |___   |_____|  |  _  || |  | || |___   |_____|  |  _  || |___| |___
 /_/   \_\           |_| |_||_| \_\ \____|           |_| |_||_|  |_| \____|           |_| |_||_____|\____|
Autonomous           Home | Right | Cycle           Home | Middle | Cycle             Home | Left | Cycle

Created on 1/26/2021 by Logan and Taylor
Updated on 1/28/2021 by Logan and Taylor

15 second Autonomous

4 Red balls
3 Blue balls
3 Goals

Best used with a partner who has no consistant Autonomous

PREPARE THE PROGRAM
-------------------
Set up the robot's Odometry positon.

GOAL 1
------
Drive into the Right corner Goal and score preload.
Cycle Goal until the Robot has the opposing alliance's Ball.
Filter Ball

GOAL 2
------
Drive towards the Home middle Goal

GOAL 3
------
Drive towards the Home left Goal and pick up the Ball in front of the goal.
Score the Ball into the Home Left Goal.

GOAL 4
------
Drive towards the center Goal and push the ball left towards the Goal into.

-----------------------------------------------------------------------------*/


void a_HRC_HMC_HLC(){
// ---------- Set Up ---------- //
  startTime=pros::millis(); // Set up a timer for autonomous
  drive->setState({117.5_in,16.75_in,90_deg});   //Set the state for odometry
  maxSpeed=500; // Set the robot's speed as fast

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  DriveCoordShort(112,32,139,1);  // Line up with the Home right Goal
  setIntake(-127);
  setDelivery(20);
  pros::delay(800);
  setIntake(80);
  maxSpeed=100;
  DriveCoordShort(130,14,140,1);  // Drive into the Home right Goal
  cycleScore(3,5);

// ---------- GOAL 2 ---------- //
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(72,30,180,2); // Line up with the Home middle Goal
  while(ballFiltering()){pros::delay(10);}
  maxSpeed=200; // Slow down the Robot
  setLift(0);
  setDelivery(0);
  setIntake(80);
  DriveCoordShort(72,22,180,1); // Drive into the Home middle Goal
  cycleScore(2,5);

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(72,35,180,2); // Back away from Home middle Goal
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(40,48,226,1.5); // Line up with the Home left Goal
  setIntake(80);
  DriveCoordShort(12,18.6,229,1.5); // Drive to pick up Ball
  filter=false;
  cycleScore(3,3);

// ---------- DRIVER SET UP ---------- //
  // ----- Ball & Goal ----- //
  maxSpeed=1000;  // GOT TO GO FAST
  DriveCoordShort(17,25.6,232,0.5); // Back away from Goal
  setIntake(-5);  // Spin Intake slowly to push the Ball in
  // DriveCoordShort(50,59,380,3); // Strafe Ball into Center Goal
  // DriveCoordShort(68,59,380,1); // Strafe Ball into Center Goal
  DriveCoordShort(38,50.7,366,1.75);  // Line up with next Ball for Driver Control
}
