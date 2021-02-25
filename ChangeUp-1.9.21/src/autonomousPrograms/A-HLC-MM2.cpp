#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _              _   _  _      ____           __  __  __  __  ____
    / \            | | | || |    / ___|         |  \/  ||  \/  ||___ \
   / _ \    _____  | |_| || |   | |      _____  | |\/| || |\/| |  __) |
  / ___ \  |_____| |  _  || |___| |___  |_____| | |  | || |  | | / __/
 /_/   \_\         |_| |_||_____|\____|         |_|  |_||_|  |_||_____|
Autonomous       Home row \ Left \ Cycle            Center Goal \ 2 Balls

Created on 2/22/2021 by Logan and Taylor
Updated on 2/26/2021 by Logan and Taylor

15 second Autonomous

3 Red balls
1 Blue balls
2 Goals

Best used with a partner who consistanty scores the Home Middle and Right Goal

GOAL 1
------
Line up with the Home middle Goal and cycle Goal
Cycle until the Robot has the opposing alliance's Ball
Filter Ball

GOAL 2
------
Line up with the ball in between the Center and Side Goal on the autonomous line
Drive towards Center Goal and push a Ball in
Line up with the Center Goal and Score Picked up Ball

-----------------------------------------------------------------------------*/
void a_HLC_MM2(){
// ---------- Preparation ---------- //
  //Capture the start time so we can score at the last moment
  startTime=pros::millis();
  drive->setState({27_in,13_in,-90_deg});   //Set the state for odometry
  maxSpeed=600;
  filter=true;

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  DriveCoordShort(26,30,-133,1);  // Line up with the Home right Goal
  setIntake(-127);  // Unfold Intake
  setDelivery(20);  // Unfold Delivery
  pros::delay(800); // Wait for Intake and Delivery
  setIntake(80);  // Spin Intake to pick up Balls
  maxSpeed=100;  // Drive Slowly into Goals
  DriveCoordShort(15,18,-133,0.75);  // Drive into the Home right Goal
  cycleScore(3,5,1);  // Cycle Goal until opposing ball is picked up
  DriveCoordShort(26,30,-133,1);  // Line up with the Home right Goal

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(35,48,3,2); // Line up with the ball 1
  while(ballFiltering()){pros::delay(10);}    //Filter the ball
  setIntake(127); // Spin Intake forward to pick up Ball
  setLift(90); // Stop scoring
  DriveCoordShort(37,60,3,0.8); // Pick up ball
  while(!ballIn()){pros::delay(10);}

  // ----- Ball 2 ---- //
  setIntake(-10);  // Unfold Intake
  DriveCoordShort(57,64,22,1.5); // Push in ball 2
  DriveCoordShort(50,50,43,0.9); // Back away from goal
  setDelivery(-10);
  setLift(-10);
  DriveCoordShort(63,61,43,0.9); // Drive into Goal
  while(pros::millis()<startTime+14250){pros::delay(10);} // Wait until the last second to shoot
  setDelivery(127); // Spin Delivery to score Ball
  setLift(127); // Spin Lift to score Ball
  pros::delay(500); // Wait for Ball to score
  DriveCoordShort(0,0,43,0.5); // Back away from goal
}
