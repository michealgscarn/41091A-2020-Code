#include "main.h"
using namespace okapi;
/*----------------------------------
     _                _   _  ____   _             _   _  __  __  _
    / \              | | | ||  _ \ / |           | | | ||  \/  |/ |
   / _ \     _____   | |_| || |_) || |   _____   | |_| || |\/| || |
  / ___ \   |_____|  |  _  ||  _ < | |  |_____|  |  _  || |  | || |
 /_/   \_\           |_| |_||_| \_\|_|           |_| |_||_|  |_||_|
Autonomous          Home | Right | 1 Ball       Home | Middle | 1 Ball
          _   _  _      _             __  __  __  __  _
          | | | || |    / |           |  \/  ||  \/  |/ |
          | |_| || |    | |   _____   | |\/| || |\/| || |
          |  _  || |___ | |  |_____|  | |  | || |  | || |
          |_| |_||_____||_|           |_|  |_||_|  |_||_|
          Home | Left | 1 Ball             Center | 1 Ball

Created on 1/17/2021 by Logan and Taylor
Updated on 1/19/2021 by Logan and Taylor

15 second Autonomous

4 Red balls
0 Blue balls
4 Goals

Best used with a partner who has no consistant Autonomous

PREPARE THE PROGRAM
-------------------
Set up the robot's Odometry positon.

GOAL 1
------
Drive into the Right corner Goal and score preload.
Pick up ball in front of Goal.

GOAL 2
------
Drive towards the Home middle Goal and score picked up ball.

GOAL 3
------
Drive towards the Home left Goal and pick up the Ball in front of the goal.
Score the Ball into the Home Left Goal.

GOAL 4
------
Drive towards the center Goal and push the ball left towards the Goal into.

----------------------------------*/


void a_HR1_HM1_HL1_MM1(){
// ---------- Set Up ---------- //
  startTime=pros::millis(); // Set up a timer for autonomous
  drive->setState({117.5_in,16.75_in,90_deg});   //Set the state for odometry
  maxSpeed=500; // Set the robot's speed as fast

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  DriveCoordShort(125,22,139,1);  // Line up with the Home right Goal
  setLift(100);  // Start Lift to Pick up Ball in front of Ball
  setDelivery(127); // Spin the Delivery forward to score the ball into the Goal
  DriveCoordShort(129,14,140,0.6);  // Drive into the Home right Goal
  setLift(127); // Spin the lift forward to deliver
  FilterBallNoIn("",1); // Score in the goal until bottom Ball is detected
  setDelivery(80);  // Slow Delivery down to prevent shooting both Balls in
  pros::delay(400); // Give preload more time to score
  cycleGoal("blue",1);  // Score until the second ball is on the top of the robot


// ---------- GOAL 2 ---------- //
  pros::delay(100); // Get a better placement for ball.
  setDelivery(0); // Stop scoring
  setLift(90);  // Raise second Ball up to top of the Robot
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(72,30,180,2); // Line up with the Home middle Goal
  maxSpeed=200; // Slow down the Robot
  DriveCoordShort(72,22,180,1); // Drive into the Home middle Goal
  setLift(127); // Spin the Lift forward to Deliver
  setDelivery(127); // Spin the Delivery forward to Score Ball
  pros::delay(600); // Wait for Ball to Score


// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  setDelivery(0); // Stop scoring
  setLift(0); // Stop scoring
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(40,48,226,1.5); // Line up with the Home left Goal
  setLift(80);  // Spin the Lift forward to pick up Ball
  setLift(127); // Spin the Lift forward to Deliver
  setIntake(-127);  // Unfold Intake
  pros::delay(800); // Wait for Intake to unfold
  setIntake(127); // Spin Intake forward to pick up Ball
  DriveCoordShort(19.6,27.5,232,1.5); // Drive to pick up Ball

  // ----- Goal ----- //
  setIntake(0); // Stop Intake to Prevent picking up more Balls
  maxSpeed=100; //  Slow down the Robot
  DriveCoordShort(12,20.6,232,1.5); // Drive into Home left Goal
  setDelivery(127); // Spin the Delivery forward to score
  pros::delay(300); // Wait
  cycleGoal("",1);  // Score until picked up ball has reached the top of Robot
  pros::delay(1100);  // Wait for Ball to be scored


// ---------- GOAL 4 ---------- //
  // ----- Ball & Goal ----- //
  setDelivery(0); // Stop scoring
  setLift(0); // Stop scoring
  setIntake(-80); // Spin Intake in revers to prevent Pulling bottom Ball out
  maxSpeed=1000;  // GOT TO GO FAST
  DriveCoordShort(58,61,380,2.5); // Drive towards Center Goal
  setIntake(-5);  // Spin Intake slowly to push the Ball in
  DriveCoordShort(68,61,380,1); // Strafe Ball into Center Goal
  DriveCoordShort(44,50.7,366,1.75);  // Line up with next Ball for Driver Control
}
