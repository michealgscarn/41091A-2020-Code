#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _              _   _  ____    ____           __  __  __  __  ____
    / \            | | | ||  _ \  / ___|         |  \/  ||  \/  ||___ \
   / _ \    _____  | |_| || |_) || |      _____  | |\/| || |\/| |  __) |
  / ___ \  |_____| |  _  ||  _ < | |___  |_____| | |  | || |  | | / __/
 /_/   \_\         |_| |_||_| \_\ \____|         |_|  |_||_|  |_||_____|
Autonomous           Home \ Right \ Cycle           Center Goal \ 2 Balls

Created on 2/22/2021 by Logan and Taylor
Updated on 2/25/2021 by Logan and Taylor

15 second Autonomous

2 Red balls
1 Blue balls
1 Goal

Best used with a partner who cycles the Left Corner and Middle Goal

GOAL 1
------
Drive into the Right corner Goal and score preload.
Cycle Goal until the Robot has the opposing alliance's Ball.
Filter Ball

GOAL 2
------
Line up with the ball in between the Center and Side Goal on the autonomous line
Drive towards Center Goal and push a Ball in
Line up with the Center Goal and Score Picked up Ball

 -----------------------------------------------------------------------------*/
void a_HRC_MM2(){
// ---------- Set Up ---------- //
  startTime=pros::millis(); // Set up a timer for autonomous
  drive->setState({116.125_in,14_in,90_deg});   //Set the state for odometry
  maxSpeed=500; // Set the robot's speed as fast
  filter=true;

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  DriveCoordShort(115,30,133,1);  // Line up with the Home right Goal
  setIntake(-127);
  setDelivery(20);
  pros::delay(800);
  setIntake(80);
  maxSpeed=80;
  DriveCoordShort(125,17,133,1);  // Drive into the Home right Goal
  cycleScore(3,5,1);
  DriveCoordShort(110,35,133,1);  // Line up with the Home right Goal

// ---------- GOAL 2 ---------- //
  // ----- Ball 1 ----- //
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(71,45,-90,1.5); // Back away from goal
  DriveCoordShort(35,48,3,1.5); // Line up with the ball 1
  while(ballFiltering()){pros::delay(10);}    //Filter the ball
  setIntake(127); // Spin Intake forward to pick up Ball
  setLift(90); // Stop scoring
  DriveCoordShort(37,62,3,0.8); // Pick up ball
  while(!ballIn()){pros::delay(10);}

  // ----- Ball 2 ---- //
  setIntake(-10);  // Unfold Intake
  DriveCoordShort(57,64,22,1.5); // Push in ball 2
  DriveCoordShort(54,54,43,0.9); // Back away from goal
  setDelivery(-10);
  setLift(-10);
  DriveCoordShort(63,61,43,0.9); // Drive into Goal
  while(pros::millis()<startTime+14250){pros::delay(10);} // Wait until the last second to shoot
  setDelivery(127); // Spin Delivery to score Ball
  setLift(127); // Spin Lift to score Ball
  pros::delay(500); // Wait for Ball to score
  DriveCoordShort(0,0,43,1); // Back away from goal
}
