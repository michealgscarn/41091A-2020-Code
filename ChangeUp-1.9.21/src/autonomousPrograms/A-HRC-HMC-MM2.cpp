#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _              _   _  ____    ____           _   _  __  __   ____           __  __  __  __  ____
    / \            | | | ||  _ \  / ___|         | | | ||  \/  | / ___|         |  \/  ||  \/  ||___ \
   / _ \    _____  | |_| || |_) || |      _____  | |_| || |\/| || |      _____  | |\/| || |\/| |  __) |
  / ___ \  |_____| |  _  ||  _ < | |___  |_____| |  _  || |  | || |___  |_____| | |  | || |  | | / __/
 /_/   \_\         |_| |_||_| \_\ \____|         |_| |_||_|  |_| \____|         |_|  |_||_|  |_||_____|
Autonomous      Home Row \ Middle \ Cycle       Home Row \ Right \ Cycle               Center  \ 2 Balls

Created on 2/21/2021 by Logan and Taylor
Updated on 3/5/2021 by Logan and Taylor

15 second Autonomous

3 Red balls
2 Blue balls
3 Goals

Best used with a partner who consistanty scores the Home Left Goal

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

GOAL 3
------
Line up with the alliance ball to the right of the left goal on the alliance line
Pick up ball and strafe to push the other alliance ball in the Center Goal
Line up with Center Goal and shoot Ball in

-----------------------------------------------------------------------------*/
void a_HRC_HMC_MM2(){
  // ---------- Set Up ---------- //
    startTime=pros::millis(); // Set up a timer for autonomous
    drive->setState({116.125_in,14_in,90_deg});   //Set the state for odometry
    maxSpeed=500; // Set the robot's speed as fast
    filter=true;

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  DriveCoordShort(113.4,34,141,1);  // Line up with the Home right Goal
  setLift(127);
  setIntake(-127);
  setDelivery(20);
  pros::delay(800);
  setLift(0);
  setIntake(80);
  maxSpeed=80;
  DriveCoordShort(125,17,133,1);  // Drive into the Home right Goal
  cycleScore(3,5,1);

// ---------- GOAL 2 ---------- //
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(82,32,206,1.9); // Line up with the Home middle Goal
  while(ballFiltering()){pros::delay(10);}
  maxSpeed=300; // Slow down the Robot
  setLift(0);
  setDelivery(0);
  setIntake(0);
  DriveCoordShort(76,21,205,0.8); // Drive into the Home middle Goal
  cycleScore(2,5,1);

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  maxSpeed=500; // Speed up the Robot
  DriveCoordShort(71,45,182,1.5); // Back away from goal
  DriveCoordShort(36,48,360,1.5); // Line up with the ball 1
  while(ballFiltering()){pros::delay(10);}    //Filter the ball
  setIntake(127); // Spin Intake forward to pick up Ball
  setLift(90); // Stop scoring
  left_fr_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  left_bc_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_fr_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_bc_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  DriveCoordShort(36,59,360,0.8); // Pick up ball
  while(!ballIn()){pros::delay(10);}
  pros::delay(600);

  // ----- Ball 2 ---- //
  setIntake(-10);  // Unfold Intake
  DriveCoordShort(57,63,382,1.5); // Push in ball 2
  setIntake(127); // Spin Intake forward to pick up Ball
  DriveCoordShort(50,54,403,0.9); // Back away from goal
  setDelivery(-10);
  setLift(-10);
  setIntake(-10);
  DriveCoordShort(63,61,403,0.9); // Drive into Goal
  while(pros::millis()<startTime+14250){pros::delay(10);} // Wait until the last second to shoot
  setDelivery(127); // Spin Delivery to score Ball
  setLift(127); // Spin Lift to score Ball
  pros::delay(500); // Wait for Ball to score
  DriveCoordShort(0,0,403,1); // Back away from goal
}
