#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _              _   _  _      ____           _   _  __  __   ____           __  __  __  __  ____
    / \            | | | || |    / ___|         | | | ||  \/  | / ___|         |  \/  ||  \/  ||___ \
   / _ \    _____  | |_| || |   | |      _____  | |_| || |\/| || |      _____  | |\/| || |\/| |  __) |
  / ___ \  |_____| |  _  || |___| |___  |_____| |  _  || |  | || |___  |_____| | |  | || |  | | / __/
 /_/   \_\         |_| |_||_____|\____|         |_| |_||_|  |_| \____|         |_|  |_||_|  |_||_____|
 Autonomous      Home row \ Left \ Cycle      Home row \ Middle \ Cycle             Center    \ 2 Balls

Created on 2/22/2021 by Logan and Taylor
Updated on 3/5/2021 by Logan and Taylor

15 second Autonomous

4 Red balls
2 Blue balls
3 Goals

Best used with a partner who consistanty scores the Home Right Goal

GOAL 1
------
Line up with the Home Left Goal and cycle Goal
Cycle until the Robot has the opposing alliance's Ball
Filter Ball

GOAL 2
------
Line up with the Home Middle Goal and pick up Ball
Cycle the Home Left Goal until the Robot has the opposing alliance's Ball
Filter Ball

GOAL 3
------
Line up with the ball in between the Center and Side Goal on the autonomous line
Drive towards Center Goal and push a Ball in
Line up with the Center Goal and Score Picked up Ball

-----------------------------------------------------------------------------*/
void a_HLC_HMC_MM2(){
// ---------- Preparation ---------- //
  // Capture the start time so we can score at the last moment
  startTime=pros::millis();
  drive->setState({27_in,13_in,-90_deg});   //Set the state for odometry
  maxSpeed=600;
  filter=true;

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  setLift(127);
  DriveCoordShort(26,30,-133,1);  // Line up with the Home right Goal
  setLift(0);
  setIntake(-127);  // Unfold Intake
  setDelivery(20);  // Unfold Delivery
  pros::delay(800); // Wait for Intake and Delivery
  setIntake(80);  // Spin Intake to pick up Balls
  maxSpeed=100;  // Drive Slowly into Goals
  DriveCoordShort(14,17,-133,0.75);  // Drive into the Home right Goal
  cycleScore(3,5,1);  // Cycle Goal until opposing ball is picked up

// ---------- GOAL 2 ---------- //
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(57,29,-210,1.75); // Line up with the Home middle Goal
  while(ballFiltering()){pros::delay(10);}
  maxSpeed=300; // Slow down the Robot
  setLift(0);
  setDelivery(0);
  setIntake(0);
  DriveCoordShort(64,19,-210,0.8); // Drive into the Home middle Goal
  cycleScore(2,5,1);

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(57,29,-210,1); // Line up with the Home middle Goal
  DriveCoordShort(35,44,0,2); // Line up with the ball 1
  while(ballFiltering()){pros::delay(10);}    //Filter the ball
  setIntake(127); // Spin Intake forward to pick up Ball
  setLift(90); // Stop scoring
  DriveCoordShort(37,57.5,0,0.8); // Pick up ball
  while(!ballIn()){pros::delay(10);}

  // ----- Ball 2 ---- //
  setIntake(-10);  //
  DriveCoordShort(57,61.5,22,1.2); // Push in ball 2
  DriveCoordShort(50,50,43,0.9); // Back away from goal
  setDelivery(-10);
  setLift(-10);
  DriveCoordShort(63,61,43,0.9); // Drive into Goal
  while(pros::millis()<startTime+14250){pros::delay(10);} // Wait until the last second to shoot
  setDelivery(127); // Spin Delivery to score Ball
  setLift(127); // Spin Lift to score Ball
  pros::delay(500); // Wait for Ball to score
  setDrive(-127,-127,-127,-127);
  while(pros::millis()<startTime+15000){pros::delay(10);} // Wait until the last second to shoot
  setDrive(0,0,0,0);
}
