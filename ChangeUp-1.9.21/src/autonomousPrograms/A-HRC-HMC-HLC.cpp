#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _              _   _  ____    ____           _   _  __  __   ____           _   _  _      ____
    / \            | | | ||  _ \  / ___|         | | | ||  \/  | / ___|         | | | || |    / ___|
   / _ \    _____  | |_| || |_) || |      _____  | |_| || |\/| || |      _____  | |_| || |   | |
  / ___ \  |_____| |  _  ||  _ < | |___  |_____| |  _  || |  | || |___  |_____| |  _  || |___| |___
 /_/   \_\         |_| |_||_| \_\ \____|         |_| |_||_|  |_| \____|         |_| |_||_____|\____|
Autonomous           Home \ Right \ Cycle          Home \ Middle \ Cycle          Home \ Left \ Cycle

Created on 1/25/2021 by Logan and Taylor
Updated on 3/5/2021 by Logan and Taylor

15 second Autonomous

4 Red balls
3 Blue balls
3 Goals

Best used with a partner who scores 1 Ball in the Home Middle Goal

GOAL 1
------
Drive into the Right corner Goal and score preload.
Cycle Goal until the Robot has the opposing alliance's Ball.
Filter Ball

GOAL 2
------
Drive towards the Home middle Goal.
Cycle the Home Middle Goal until the robot has the opposing alliance's Ball.
Filter Ball

GOAL 3
------
Drive towards the Home left Goal and pick up the Ball in front of the goal.
Score the Ball into the Home Left Goal.

-----------------------------------------------------------------------------*/
void a_HRC_HMC_HLC(){
// ---------- Set Up ---------- //
  startTime=pros::millis(); // Set up a timer for autonomous
  drive->setState({116.125_in,14_in,90_deg});   //Set the state for odometry
  maxSpeed=500; // Set the robot's speed as fast
  filter=true;

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  DriveCoordShort(113.4,34,141,1);  // Line up with the Home right Goal
  setIntake(-127);
  setLift(127);
  setDelivery(20);
  pros::delay(800);
  setLift(0);
  setIntake(80);
  maxSpeed=100;
  DriveCoordShort(125,17,135,1);  // Drive into the Home right Goal
  cycleScore(3,2.75,1);

// ---------- GOAL 2 ---------- //
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(83,32,206,1.75); // Line up with the Home middle Goal
  while(ballFiltering()){pros::delay(10);}
  maxSpeed=100; // Slow down the Robot
  setLift(0);
  setDelivery(0);
  setIntake(0);
  DriveCoordShort(76,21,205,0.9); // Drive into the Home middle Goal
  cycleScore(2,2.25,1);

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  setDelivery(0); // Stop scoring
  setLift(0); // Stop scoring
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(72,40,180,2); // Back away from the Home middle Goal
  DriveCoordShort(29,35,228,2); // Line up with the Home left Goal
  // DriveCoordShort(27,35,228,0.75); // Line up with the Home left Goal
  setIntake(50); // Spin Intake forward to pick up Ball

  // ----- Goal ----- //
  maxSpeed=100; //  Slow down the Robot
  DriveCoordShort(11,19,228,0.75); // Drive into Home left Goal
  filter=false;
  cycleScore(3,2.25,1);  // Score until picked up ball has reached the top of Robot

  maxSpeed=1000;  // GOT TO GO FAST
  DriveCoordShort(27,35.6,232,1); // Back away from Goal
}
