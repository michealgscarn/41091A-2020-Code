#include "main.h"
using namespace okapi;

void a_HRC(){
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

  // ---------- GOAL 2 ---------- //
    // ----- Ball 1 ----- //
    maxSpeed=500; // Speed up the Robot
    DriveCoordShort(102.5,44.5,141,3); // Line up with the Home left Goal
}
