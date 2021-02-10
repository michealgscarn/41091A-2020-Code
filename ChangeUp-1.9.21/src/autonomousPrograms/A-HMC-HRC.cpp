#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _                _   _  __  __   ____             _   _  ____    ____
    / \              | | | ||  \/  | / ___|           | | | ||  _ \  / ___|
   / _ \     _____   | |_| || |\/| || |       _____   | |_| || |_) || |
  / ___ \   |_____|  |  _  || |  | || |___   |_____|  |  _  ||  _ < | |___
 /_/   \_\           |_| |_||_|  |_| \____|           |_| |_||_| \_\ \____|
Autonomous         Home Row | Middle | Cycle        Home Row | Right | Cycle

Created on 1/25/2021 by Logan and Taylor
Updated on 2/11/2021 by Logan and Taylor

15 second Autonomous

2 Red balls
2 Blue balls
2 Goals

Best used with a partner who consistanty scores the Home Left Goal

PREPARE THE PROGRAM
-------------------
Set up the robot's Odometry positon.

GOAL 1
------
Line up with the Home middle Goal and cycle Goal
Cycle the Goal until the Robot has the opposing alliance's Ball
Filter Ball

GOAL 2
------
Line up with the Home left Goal and pick up Ball in front
Cycle the Goal until the Robot has the opposing alliance ball
Filter Ball

-----------------------------------------------------------------------------*/
void a_HMC_HRC(){
// ---------- Preparation ---------- //
  //Capture the start time so we can score at the last moment
  startTime=pros::millis();
  drive->setState({86_in,12_in,180_deg});   //Set the state for odometry
  maxSpeed=100;
  filter=true;
// ---------- Goal 1 (Home Row Wall) ---------- //
  // ----- Goal ----- //
  DriveCoordShort(71,37,180,1); // Line up with the Home middle Goal
  setDelivery(20);  // Unfold Hold
  setIntake(-127);
  pros::delay(800);
  setIntake(80);
  DriveCoordShort(71,20,180,1); // Drive into Goal
  cycleScore(2,3,1);
  DriveCoordShort(72,29,180,1); // Line up with the Home middle Goal
  setIntake(0);

// ---------- Goal 2 (Home Left Corner) ---------- //
  // ------ Ball 1 ----- //
  DriveCoordShort(111,33,139,2);  // Line up with Goal
  maxSpeed=100; // Slow the Robot Down
  setIntake(50);
  setLift(0);
  DriveCoordShort(127,16.9,136,1);  // Drive into Goal
  cycleScore(3,3,1);
  maxSpeed=100;

  DriveCoordShort(118,27,135,1.5); //Back from goal
  setIntake(0);
}
