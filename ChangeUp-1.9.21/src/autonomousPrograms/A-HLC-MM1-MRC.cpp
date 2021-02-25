#include "main.h"
using namespace okapi;
void a_HLC_MM1_MRC(){
// ---------- Set Up ---------- //
  startTime=pros::millis(); // Set up a timer for autonomous
  drive->setState({27_in,13_in,-90_deg});   //Set the state for odometry
  maxSpeed=500; // Set the robot's speed as fast
  filter=true;  // Filter Ball after Cycling

// ---------- GOAL 1 ---------- //
  // ----- Goal ----- //
  DriveCoordShort(27,30.3,-135.4,1);  // Line up with the Home right Goal
  setIntake(-127);  // Unfold Intake
  setDelivery(20);  // Unfold Delivery
  pros::delay(800); // Wait for Intake and Delivery
  setIntake(80);  // Spin Intake to pick up Balls
  maxSpeed=100;  // Drive Slowly into Goals
  DriveCoordShort(12,16,-135.6,0.75);  // Drive into the Home right Goal
  cycleScore(3,5,1);  // Cycle Goal until opposing ball is picked up

// ---------- GOAL 2 ---------- //
  // ----- Goal ----- //
  maxSpeed=100; // Speed up the Robot
  resetY=22;  // Set Y postion
  pros::Task lo(lineReset); // Begin line reset
  DriveCoordShort(25,25,-141.7,0.75); // Back away from Goal
  maxSpeed=500;
  setIntake(-20); // Spin in Reverse to Push ball into middle
  DriveCoordShort(58,59,-3.5,2); // Push Ball into Center Goal

// ---------- GOAL 3 ---------- //
  // ----- Ball & Goal ----- //
  DriveCoordShort(40,45,79.9,1.4); // Back away from Goal
  maxSpeed=150;
  DriveCoordShort(109.8,54,90,1.8); // Line up with Middle Right Goal
  DriveCoordShort(119.0,54,43.6,0.8);  // Get ready to cycle Middle Right Goal
  setIntake(127);
  maxSpeed=100; //  Slow down the Robot for Precision
  left_fr_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  left_bc_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_fr_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  right_bc_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  DriveCoordShort(122.5,62.5,53,0.75); // Drive into the Middle Right Goal
  filter=false;
  cycleScore(3,3,1);  // Cycle Middle Right Goal
  cycleScoreSide(1,3,1);  // Cycle Middle Right Goal
  maxSpeed=500; // Speed up the Robot
  pros::delay(1);
  setIntake(-127);  // Prevent picking up alliance ball
  setLift(0); // Stop Lift
  setDelivery(0); // Stop Delivery
  DriveCoordShort(119,53,43.6,2);  // Get ready to cycle Middle Right Goal
}
