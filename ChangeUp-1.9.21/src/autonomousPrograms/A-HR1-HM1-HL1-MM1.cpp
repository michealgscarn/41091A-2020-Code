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
Updated on 2/11/2021 by Logan and Taylor

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


void a_HR1_HM1_HL1_MM1(){
  // ---------- Set Up ---------- //
    startTime=pros::millis(); // Set up a timer for autonomous
    drive->setState({116.125_in,14_in,90_deg});   //Set the state for odometry
    maxSpeed=500; // Set the robot's speed as fast
    filter=false;

  // ---------- GOAL 1 ---------- //
    // ----- Goal ----- //
    setLift(127);
    DriveCoordShort(121.8,24.2,137.5,1);  // Line up with the Home right Goal
    maxSpeed=80;
    DriveCoordShort(129.3,15.5,140.3,0.6);  // Drive into the Home right Goal
    cycleScoreNoIntake(1,0.75,1);


  // ---------- GOAL 2 ---------- //
    setLift(90);  // Raise second Ball up to top of the Robot
    maxSpeed=500; // Speed up the Robot
    DriveCoordShort(72,30,180,2); // Line up with the Home middle Goal
    maxSpeed=200; // Slow down the Robot
    DriveCoordShort(71.4,19.2,183.4,1); // Drive into the Home middle Goal
    setLift(127); // Spin the Lift forward to Deliver
    setDelivery(127); // Spin the Delivery forward to Score Ball
    pros::delay(600); // Wait for Ball to Score


  // ---------- GOAL 3 ---------- //
    // ----- Ball 1 ----- //
    setDelivery(0); // Stop scoring
    setLift(0); // Stop scoring
    maxSpeed=500; // Speed up the Robot
    DriveCoordShort(44,48,225,1.5); // Line up with the Home left Goal
    setIntake(-127);  // Unfold Intake
    DriveCoordShort(25.5,33.5,236.5,1.5); // Line up with the Home left Goal
    setIntake(50); // Spin Intake forward to pick up Ball
    // DriveCoordShort(28,32,226,1.5); // Drive to pick up Ball

    // ----- Goal ----- //
    // setIntake(0); // Stop Intake to Prevent picking up more Balls
    maxSpeed=100; //  Slow down the Robot
    DriveCoordShort(12.7,16.5,223,1); // Drive into Home left Goal
    filter=true;
    cycleScore(3,3,1);  // Score until picked up ball has reached the top of Robot

  // ---------- GOAL 4 ---------- //
    // ----- Ball & Goal ----- //
    maxSpeed=500;  // GOT TO GO FAST
    DriveCoordShort(35.5,39,226,2.5); // Drive towards Center Goal
    setIntake(-20);  // Spin Intake slowly to push the Ball in
    DriveCoordShort(62,64,360,2.5); // Strafe Ball into Center Goal
    DriveCoordShort(33,45,360,1.75);  // Line up with next Ball for Driver Control
}
