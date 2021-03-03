#include "main.h"
using namespace okapi;
/*-------------------------------------------------------------------------------------------------------
     _              __  __  __  __  _____           _   _  _      ____
    / \            |  \/  ||  \/  ||  ___|         | | | || |    / ___|
   / _ \    _____  | |\/| || |\/| || |_     _____  | |_| || |   | |
  / ___ \  |_____| | |  | || |  | ||  _|   |_____| |  _  || |___| |___
 /_/   \_\         |_|  |_||_|  |_||_|             |_| |_||_____|\____|
Autonomous                  Center | Fill              Home | Left | Cycle

Created on 1/25/21 by Logan and Taylor
Last updated on 3/5/21 by Logan and Taylor

15 second Autonomous

4 Red balls
1 Blue balls
2 Goals

Best used with Partner who consistantly scores Home right and Home middle

GOAL 1
------
Pick up the ball on the autonomous line directly in front of the robot.
Strafe a ball into the center goal.
Score the preload and picked up ball into center goal.

GOAL 2
------
Line up with bottom left corner ball.
Pick up bottom left corner ball and score in goal.

-------------------------------------------------------------------------------------------------------*/
void a_MMF_HLC(){
  drive->setState({32_in,15.5_in,0_deg}); // Set up State
  startTime=pros::millis();   //Set up the timer
  maxSpeed=300; // Set Maximum Speed

//---------- GOAL 1 (CENTER) ----------//
  // ----- Ball 1 ----- //
  setLift(127);
  setIntake(-127); // Unfold Intake
  setDelivery(30); // Unfold Hood
  DriveCoordShort(38, 40, 0, 1.5); // Line up with ball
  setIntake(127); // Start Intake
  setLift(80); // Start Lift
  setDelivery(0); // Stop Delivery
  maxSpeed=100; // Set Maximum Speed
  DriveCoordShort(38, 63, 1, 1); // Pick up Ball

  // ----- Ball 2 ----- //
  maxSpeed=400; // Set Maximum Speed
  DriveCoordShort(59.1, 63.2, 1, 1); // Push Ball into Center goal
  setLift(0);

  // ----- Goal ----- //
  DriveCoordShort(54, 54.3, 16, 0.75); // Back away from ball
  DriveCoordShort(56.6, 54.2, 44, 0.75); // Line up with goal
  setIntake(0); // Stop intake
  maxSpeed=200; // Set Maximum Speed
  DriveCoordShort(61.4, 61.4, 45, 1.2); // Drive into goal
  setDelivery(-60); // Start delivery to shoot ball in
  setLift(-40); // Start lift to lift ball into goal
  pros::delay(400); // Wait for ball to deliver
  setDelivery(127); // Start delivery to shoot ball in
  setLift(60); // Start lift to lift ball into goal
  pros::delay(1000); // Wait for ball to deliver


// ----------- GOAL 2 (HOME LEFT) ---------- //
  // ----- Ball 1 ----- //
  maxSpeed=800; // Set Maximum Speed
  DriveCoordShort(41.2, 40.8, 49, 1); // Back away from goal
  setDelivery(0); // Stop delivering the ball
  setIntake(127); // Begin intake
  DriveCoordShort(27.1, 27.8, -129, 1.25); // Line up with ball
  maxSpeed=200; // Set Maximum Speed
  DriveCoordShort(20.3, 20.5, -131, 0.8); // Pick up ball
  pros::delay(400); // Wait for ball to be picked up
  setIntake(0); // Stop intake

  // ----- Goal ----- //
  DriveCoordShort(12.4, 16.2, -139, 1); // Drive into goal
  setDelivery(127); // Start delivery to shoot ball in
  setLift(80); // Start lift to lift ball into goal
  pros::delay(200); // Wait for ball to deliver
  FilterBall("no",2); // Score ball into goal
  pros::delay(300);
  setIntake(-127); // Stop intake
  pros::delay(800);
  setLift(0); // Continue Lift to filter
  setDelivery(0); // Continue Delivery to filter
  maxSpeed=800; // Set Maximum Speed
  DriveCoordShort(22.4, 26.8, -137, 2); // Back up from goal
}
