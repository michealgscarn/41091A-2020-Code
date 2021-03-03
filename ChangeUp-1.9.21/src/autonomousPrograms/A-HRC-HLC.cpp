#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _              _   _  ____    ____           _   _  _      ____
    / \            | | | ||  _ \  / ___|         | | | || |    / ___|
   / _ \    _____  | |_| || |_) || |      _____  | |_| || |   | |
  / ___ \  |_____| |  _  ||  _ < | |___  |_____| |  _  || |___| |___
 /_/   \_\         |_| |_||_| \_\ \____|         |_| |_||_____|\____|
Autonomous          Home \ Right \ Cycle          Home \ Left \ Cycle

Created on 2/8/2021 by Logan and Taylor
Updated on 3/5/2021 by Logan and Taylor

15 second Autonomous

2 Red balls
2 Blue balls
2 Goals

Best used with a partner who scores in the Middle Home Goal

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
void a_HRC_HLC(){
// ---------- Set Up ---------- //
  startTime=pros::millis(); // Set up a timer for autonomous
  drive->setState({116.125_in,14_in,90_deg});   //Set the state for odometry
  maxSpeed=500; // Set the robot's speed as fast

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  setLift(127);
  DriveCoordShort(115.4,32,141,1);  // Line up with the Home right Goal
  setIntake(-127);
  setLift(0);
  setDelivery(20);
  pros::delay(800);
  setIntake(80);
  maxSpeed=80;
  DriveCoordShort(128.87,15.9,141,1);  // Drive into the Home right Goal
  cycleScore(3,5,1);

// ---------- GOAL 2 ---------- //
  // ----- Ball 1 ----- //
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(32.5,44.5,141,3); // Line up with the Home left Goal
  DriveCoordShort(29.7,33,215.5,1.5); // Line up with the Home left Goal
  setIntake(50); // Spin Intake forward to pick up Ball

  // ----- Goal ----- //
  maxSpeed=100; //  Slow down the Robot
  DriveCoordShort(14.6,19.5,222,1); // Drive into Home left Goal
  filter=true;
  cycleScore(3,3,1);  // Score until picked up ball has reached the top of Robot

// ---------- GOAL 3 ---------- //
  // ----- Ball & Goal ----- //
  maxSpeed=1000;  // GOT TO GO FAST
  DriveCoordShort(40,40,232,0.5); // Back away from Goal
  setIntake(-20);  // Spin Intake slowly to push the Ball in
  DriveCoordShort(56.6,60.3,374,1.75);  // Line up with next Ball for Driver Control
  DriveCoordShort(40,40,232,0.5); // Back away from Goal
}
