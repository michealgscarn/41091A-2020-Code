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
void a_HRC_HMC_HLC_D(){
// ---------- Set Up ---------- //
  startTime=pros::millis(); // Set up a timer for autonomous
  drive->setState({116.125_in,14_in,90_deg});   //Set the state for odometry
  maxSpeed=600; // Set the robot's speed as fast
  filter=true;

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  // pros::Task Ayup(deploy);
  DriveCoordShort(113.4,33,141,1);  // Line up with the Home right Goal
  deploy();   //Deploy the intake and hoods
  maxSpeed=300;
  DriveCoordShort(125,15.5,135,1);  // Drive into the Home right Goal
  cycleScore(3,2.75,1);   //Cycle out the opponent ball and score 3 alliance balls

// ---------- GOAL 2 ---------- //
  maxSpeed=600; // Speed up the Robot
  DriveCoordShort(122,18,141,.25);  // Back away from Home right Goal
  DriveCoordShort(81,32,200,1.5); // Line up with the Home middle Goal
  while(ballFiltering()){pros::delay(10);}
  maxSpeed=300; // Slow down the Robot
  setLift(0);
  setDelivery(0);
  setIntake(0);
  DriveCoordShort(73,21.5,195,1); // Drive into the Home middle Goal
  cycleScore(2,4,1);    //Cycle out opponent ball and score one alliance ball

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  setDelivery(0); // Stop scoring
  setLift(0); // Stop scoring
  maxSpeed=600; // Speed up the Robot
  DriveCoordShort(72,40,180,1.75); // Back away from the Home middle Goal

  DriveCoordShort(33,36,270,1.7); // Drive to point for reset odom
  quickAlign(26,4); // Reset odom
  DriveCoordShort(36,36,223,0.8); // Line up with Home Left Goal
  setIntake(50); // Spin Intake forward to pick up Ball

  // ----- Goal ----- //
  maxSpeed=300; //  Slow down the Robot
  DriveCoordShort(14,16,230,1); // Drive into Home left Goal
  filter=false;
  cycleScore(3,2.25,1);  // Score until picked up ball has reached the top of Robot

  maxSpeed=1000;  // GOTTA GO FAST
  DriveCoordShort(27,35.6,232,1); // Back away from Goal
}
