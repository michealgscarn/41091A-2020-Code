#include "main.h"
using namespace okapi;
/*-----------------------------------
INSERT ASCII ART HERE

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
Line up with the Home middle Goal and shoot preload

GOAL 2
------
Line up with the Home left Goal and pick up Ball in front
Cycle the Goal until the Robot has the opposing alliance ball

-------------------------------------*/
void a_HMC_HRC(){
// ---------- Preparation ---------- //
  //Capture the start time so we can score at the last moment
  startTime=pros::millis();
  drive->setState({86.5_in,14.5_in,180_deg});   //Set the state for odometry

// ---------- Goal 1 (Home Row Wall) ---------- //
  // ----- Goal ----- //
  DriveCoordShort(72,33,180,1); // Line up with the Home middle Goal
  setDelivery(20);  // Unfold Hold
  DriveCoordShort(71,20,183,1); // Drive into Goal
  setDelivery(127); // Score Ball
  setLift(127); // Lift Ball to Deliver
  pros::delay(600); // Score for 0.6 Seconds

// ---------- Goal 2 (Home Left Corner) ---------- //
  // ------ Ball 1 ----- //
  DriveCoordShort(111,34,139,2);  // Line up with Goal
  setIntake(-127); // Deploy Intake
  setLift(0); // Stop the Lift
  setDelivery(0); // Stop the Delivery
  pros::delay(1000);  // Wait for Intake to Unfold
  setIntake(127); // Spin the Intake forward
  maxSpeed=100; // Slow the Robot Down
  DriveCoordShort(127,17.9,136,2);  // Drive into Goal
  FilterBall("",3); // Cycle the goal until the Robot has the opposing alliance's Ball

  setIntake(-127);  // Spin the Intake in reverse to prevent pulling out a Ball
  pros::delay(500); // Wait for Ball to Deliver
  setLift(0); // Continue Lift to filter
  setDelivery(0); // Continue Delivery to filter
  maxSpeed=600; // Speed up the Robot
  DriveCoordShort(118,28,135,1.5); //Back from goal
  setIntake(0);
}
