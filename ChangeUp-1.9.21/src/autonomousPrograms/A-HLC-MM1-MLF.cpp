#include "main.h"
using namespace okapi;

void a_HLC_MM1_MLF(){
  // ---------- Set Up ---------- //
    startTime=pros::millis(); // Set up a timer for autonomous
    drive->setState({27_in,13_in,-90_deg});   //Set the state for odometry
    maxSpeed=500; // Set the robot's speed as fast
    filter=true;  // Filter Ball after Cycling

  // ---------- GOAL 1 ---------- //
    // ----- Goal ----- //
    DriveCoordShort(29,33,-133,1);  // Line up with the Home right Goal
    setLift(127);
    setIntake(-127);  // Unfold Intake
    pros::delay(800); // Wait for Intake and Delivery
    setLift(0);
    setIntake(80);  // Spin Intake to pick up Balls
    DriveCoordShort(15,18,-135,0.75);  // Drive into the Home right Goal
    cycleScore(3,5,1);  // Cycle Goal until opposing ball is picked up

// ---------- GOAL 2 ---------- //
  // ----- Ball ----- //
  resetY=22;  // Set Y postion
  pros::Task lo(lineReset); // Begin line reset
  DriveCoordShort(23,22,-128,0.75); // Back away from Goal
  DriveCoordShort(36,47,4,1.9); // Line up with the ball 1
  while(ballFiltering()){pros::delay(10);}    //Filter the ball
  stopFilter=true;
  setIntake(127); // Spin Intake forward to pick up Ball
  setLift(90); // Stop scoring
  DriveCoordShort(35,60,4,0.8); // Pick up ball
  pros::delay(200);
  while(!ballIn()){pros::delay(10);}

  // ----- Goal ----- //
    maxSpeed=500; // Speed ip Robot
    setIntake(-20); // Spin in Reverse to Push ball into middle
    DriveCoordShort(61,62,7,2); // Push Ball into Center Goal

  // ---------- GOAL 3 ---------- //
    // ----- Ball & Goal ----- //
    DriveCoordShort(25,54,-47,2.5); // Line up with Middle Right Goal
    setIntake(127);
    maxSpeed=100; //  Slow down the Robot for Precision
    DriveCoordShort(19,65,-53,1.25); // Drive into the Middle Right Goal
    filter=false; // Don't filter the Ball
    cycleScore(2,3,1);  // Cycle Middle Right Goal
    maxSpeed=500; // Speed up the Robot
    pros::delay(1);
    setIntake(-127);  // Prevent picking up alliance ball
    setLift(0); // Stop Lift
    setDelivery(0); // Stop Delivery
    DriveCoordShort(25,54,-47,2.5); // Line up with Middle Right Goal
}
