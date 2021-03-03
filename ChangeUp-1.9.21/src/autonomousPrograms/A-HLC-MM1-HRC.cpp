#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _              _   _  _      ____           __  __  __  __  _           _   _  __  __   ____
    / \            | | | || |    / ___|         |  \/  ||  \/  |/ |         | | | ||  \/  | / ___|
   / _ \    _____  | |_| || |   | |      _____  | |\/| || |\/| || |  _____  | |_| || |\/| || |
  / ___ \  |_____| |  _  || |___| |___  |_____| | |  | || |  | || | |_____| |  _  || |  | || |___
 /_/   \_\         |_| |_||_____|\____|         |_|  |_||_|  |_||_|         |_| |_||_|  |_| \____|
Autonomous       Home Row \ Left \ Cycle           Center Goal  \ 1       Home Row \ Middle \ Cycle

Created on 2/22/2021 by Logan and Taylor
Updated on 3/5/2021 by Logan and Taylor

15 second Autonomous

4 Red balls
2 Blue balls
3 Goals

Best used with a partner who scores in the Middle Home Goal

GOAL 1
------
Drive into the Left corner Goal and score preload.
Cycle Goal until the Robot has the opposing alliance's Ball.
Filter Ball

GOAL 2
------
Drive towards the Center Goal and strafe to push ball in

GOAL 3
------
Drive towards the Home Right Goal and pick up the Ball in front of the goal.
Cycle the Home Right Goal until the robot has the opposing alliance's Ball.

 -----------------------------------------------------------------------------*/
void a_HLC_MM1_HRC(){
  // ---------- Set Up ---------- //
    startTime=pros::millis(); // Set up a timer for autonomous
    drive->setState({27_in,13_in,-90_deg});   //Set the state for odometry
    maxSpeed=500; // Set the robot's speed as fast
    filter=true;  // Filter Ball after Cycling

  // ---------- GOAL 1 ---------- //
    // ----- Goal ----- //
    setLift(127);
    DriveCoordShort(26,30,-135,1);  // Line up with the Home right Goal
    setLift(0);
    setIntake(-127);  // Unfold Intake
    setDelivery(20);  // Unfold Delivery
    pros::delay(800); // Wait for Intake and Delivery
    setIntake(80);  // Spin Intake to pick up Balls
    maxSpeed=100;  // Drive Slowly into Goals
    DriveCoordShort(15,18,-135,0.75);  // Drive into the Home right Goal
    cycleScore(3,5,1);  // Cycle Goal until opposing ball is picked up

// ---------- GOAL 2 ---------- //
  // ----- Goal ----- //
    maxSpeed=100; // Slow down the Robot
    DriveCoordShort(24,29,-141.7,0.75); // Back away from Goal
    maxSpeed=500; // Speed ip Robot
    setIntake(-20); // Spin in Reverse to Push ball into middle
    DriveCoordShort(55,60,7,2); // Push Ball into Center Goal

  // ---------- GOAL 3 ---------- //
    // ----- Ball & Goal ----- //
    DriveCoordShort(44,44,10,1.4); // Back away from Goal
    maxSpeed=150; // Slow down the Robot
    DriveCoordShort(109,38,143,2.5); // Line up with Middle Right Goal
    setIntake(127);
    maxSpeed=100; //  Slow down the Robot for Precision
    DriveCoordShort(125,18,143,1.25); // Drive into the Middle Right Goal
    filter=false; // Don't filter the Ball
    cycleScore(3,3,1);  // Cycle Middle Right Goal
    maxSpeed=500; // Speed up the Robot
    pros::delay(1);
    setIntake(-127);  // Prevent picking up alliance ball
    setLift(0); // Stop Lift
    setDelivery(0); // Stop Delivery
    DriveCoordShort(115,24,147,2);  // Get ready to cycle Middle Right Goal
}
