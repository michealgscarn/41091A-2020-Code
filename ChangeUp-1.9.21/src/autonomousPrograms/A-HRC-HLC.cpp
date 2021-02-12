#include "main.h"
using namespace okapi;
void a_HRC_HLC(){
// ---------- Set Up ---------- //
  startTime=pros::millis(); // Set up a timer for autonomous
  drive->setState({116.125_in,14_in,90_deg});   //Set the state for odometry
  maxSpeed=500; // Set the robot's speed as fast

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  DriveCoordShort(115.4,32,141,1);  // Line up with the Home right Goal
  setIntake(-127);
  setDelivery(20);
  pros::delay(800);
  setIntake(80);
  maxSpeed=80;
  DriveCoordShort(128.87,15.9,141,1);  // Drive into the Home right Goal
  cycleScore(3,5,1);

  // ---------- GOAL 3 ---------- //
    // ----- Ball 1 ----- //
    maxSpeed=500; // Speed up the Robot
    DriveCoordShort(32.5,44.5,141,3); // Line up with the Home left Goal
    DriveCoordShort(29.7,33,215.5,1.5); // Line up with the Home left Goal
    setIntake(50); // Spin Intake forward to pick up Ball
    // DriveCoordShort(28,32,226,1.5); // Drive to pick up Ball

    // ----- Goal ----- //
    // setIntake(0); // Stop Intake to Prevent picking up more Balls
    maxSpeed=100; //  Slow down the Robot
    DriveCoordShort(14.6,19.5,222,1); // Drive into Home left Goal
    filter=true;
    cycleScore(3,3,1);  // Score until picked up ball has reached the top of Robot

// ---------- DRIVER SET UP ---------- //
  // ----- Ball & Goal ----- //
  maxSpeed=1000;  // GOT TO GO FAST
  DriveCoordShort(40,40,232,0.5); // Back away from Goal
  setIntake(-20);  // Spin Intake slowly to push the Ball in
  DriveCoordShort(56.6,60.3,374,1.75);  // Line up with next Ball for Driver Control
  DriveCoordShort(40,40,232,0.5); // Back away from Goal
}
