#include "main.h"
using namespace okapi;
/*------------------------------------------
  ____   _     _  _  _
 / ___| | | __(_)| || | ___
 \___ \ | |/ /| || || |/ __|
  ___) ||   < | || || |\__ \
 |____/ |_|\_\|_||_||_||___/

Created on 7/15/2021 by Taylor and Logan
Last Updated on 1/16/2021 by Taylor and Logan

1 minute Autonomous

15 Red balls
11 Blue balls
9 Goals
122 points

PREPARE THE PROGRAM
-------------------
Set up the robot's Odometry positon

GOAL 1
------
Pick up the ball closest to the robot.
Drive towards and pick up the ball on the wall.
Score in the bottom left goal.

GOAL 2
------
Drive towards the ball left of center and pick up.
Pick up second ball in line of the middle left goal.
Score in the middle left goal while picking the blue ball.

GOAL 3
------
Drive up to the ball diagonal of the top left goal while filtering the blue ball.
Drive towards the ball diagonal of the top left goal and pick up the ball.
Reset odometery position from crossing the line and
Score in the goal while filtering one blue ball and holding the other.

GOAL 4
------
Drive up towards the red ball vertically in line with the top middle goal.
Pick up the ball and drive towards the top middle goal.
Score the ball while picking up the blue ball.

GOAL 5
------
Drive towards the ball diagonal of the top right goal while filtering the blue ball.
Pick up the red ball and score in the top right goal.

GOAL 6
------
Drive towards the ball right of center and pick up.
Pick up second ball in line of the middle right goal.
Score in the middle right goal.

GOAL 7
------
Drive towards the ball diagonal of the bottom right goal and pick up.
Drive up to the bottom right goal and score.

RESET ODOMETRY
--------------
Drive backwards and reset the robot's Odometry position.

GOAL 8
------
Pick up bottom ball against the right wall and drive towards the center goal.
Punch out two balls and score in the center goal.

GOAL 9
------
Drive towards the ball vertically in line with the bottom middle goal and pick up.
Score in the bottom middle goal while taking out the blue ball.

------------------------------------------*/


void A_SKILLS_JANUARY(){
// ---------- SET UP ---------- //
  drive->setState({58.75_in,16_in,-90_deg});
  maxSpeed=700;

// ---------- GOAL 1 ---------- //
  // ----- Unfold ----- //
  DriveCoordShort(58,24,-90,1); // Line up with ball
  setIntake(-127);  // Run intake in reverse to deploy
  setDelivery(127); // Spin the delivery forward
  pros::delay(1000);  // Wait for robot to unfold

  // ----- Ball 1 ----- //
  setDelivery(0); // Stop the Delivery
  setIntake(127); // Spin the Intake inward
  setLift(70);  // Spin the Lift forward
  DriveCoordShort(33,24.5,-90,1); // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(24.1,36.3,-88.9,1); // Line up with Ball
  DriveCoordShort(17,36.4,-88.9,1); // Pick up Ball

  // ----- Goal ----- //
  DriveCoordShort(21.9,21.8,-130.5,1);  // Line up with goal
  setIntake(0); // Stop the Intake
  setLift(0); // Stop the Lift
  setDelivery(0); // Stop the Delivery
  DriveCoordShort(15,15,-133.4,0.75);  // Drive into Goal
  FilterBall("blue",2); // Cycle 2 Balls while Filtering Blue


// ---------- GOAL 2 ---------- //
  // ----- Ball 1 ----- //
  setIntake(-127);  // Run intake in reverse
  setDelivery(-127);  // Stop running delivery
  setLift(80);  // Stop running lift
  DriveCoordShort(21.9,21.8,-130.5,1);  // Back up from Goal
  DriveCoordShort(48.5,48,3.8,2); // Line up with Ball
  setDelivery(0); // Stop the Delivery
  setIntake(127); // Run intake forward to pick up a ball
  setLift(60);  // Start running lift
  DriveCoordShort(49,70,5,1); // Drive forward to pick up ball

  // ----- Ball 2 ----- //
  DriveCoordShort(52,70,-86,.75); // Turn to face next ball
  DriveCoordShort(24,72,-88,0.5); // Drive forward to pick up ball
  pros::delay(200); // Wait for ball to pick up
  setIntake(0); // Stop intake

  // ----- Goal ---- //
  DriveCoordShort(19,76,-86.5,0.5); // Drive into goal
  // setDelivery(-40);   //Start running delivery slowly in reverse
  // setLift(-40);   //Start running lift slowly in reverse
  // pros::delay(400);   //Wait for ball to slowly move down
  setDelivery(127); // Start running delivery slowly in reverse
  setLift(80);  // Start running lift slowly in reverse
  pros::delay(400); // Wait for ball to slowly move down
  FilterBall("blue",1); // Cycle 1 Ball while Filtering Blue


// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  setIntake(-127);  // Spin the Intake in Reverse
  setDelivery(0);   // Stop the Delivery
  setLift(0); // Stop the Lift
  DriveCoordShort(46,71.8,-90,0.9); // Back away from goal
  setIntake(127); // Run intake in reverse
  setDelivery(-127);  // Stop running delivery
  setLift(90);  // Stop running lift
  DriveCoordShort(42,95,4.3,2); // Line up with ball
  setDelivery(0); //Stop running delivery
  setIntake(127); //Start running intake forward to pick up ball
  setLift(80);   //Start running lift

  // ----- Reset Position ----- //
  resetY=117.5; // Set the Y reset Position
  pros::Task yo(lineReset); // Start the Line Reset
  quickAlign("X");  // Reset the X position
  maxSpeed=80; // Drive Slowly across the Line
  DriveCoordShort(36,122,3.1,1.1);  // Pick up Ball
  maxSpeed=700; // Resume normal Speed

  // ----- Ball 2 ----- //
  DriveCoordShort(30,106,-90,1.1);  // Line up with ball
  DriveCoordShort(18.4,106,-90,1.1);  // Pick up Ball

  // ----- Goal ----- //
  DriveCoordShort(23.6,118,-50,1.1);  // Line up with Goal
  DriveCoordShort(17,125,-51,1.1);  // Drive into Goal
  setDelivery(-40); // Start running delivery slowly in reverse
  setLift(-40); // Start running lift slowly in reverse
  pros::delay(400); // Wait for ball to slowly move down
  FilterBall("blue",2); // Cycle the goal while Filtering Blue


// ---------- GOAL 4 ---------- //
  // ----- Ball 1 ----- //
  setIntake(-127);  // Run intake in reverse
  setDelivery(-127);  // Stop running delivery
  setLift(80);  // Stop running lift
  DriveCoordShort(23.6,117,-50,1.1);  // Back away from goal
  DriveCoordShort(51,92,90,2.25);  // Line up with Ball
  setIntake(127); // Run intake in reverse
  setDelivery(0); // Stop running delivery
  setLift(80);  // Stop running lift
  DriveCoordShort(72.5,92,90,1.1);  // Pick up Ball

  // ----- Goal ---- //
  setIntake(10);  // Run intake in reverse
  DriveCoordShort(72.8,118,-3,1.75); // Drive into Goal
  setLift(0); // Stop running lift
  FilterBall("blue",1); // Cycle 1 Ball while Filtering Blue


// ---------- GOAL 5 ---------- //
  // ----- Ball 1 ----- //
  setIntake(-127);  // Run intake in reverse
  setDelivery(-127);  // Stop running delivery
  setLift(80);  // Stop running lift
  DriveCoordShort(72.8,112,-3,1); // Drive away from Goal
  DriveCoordShort(85,115,92.5,2); // Line up with Ball
  quickAlignNorthEast("Y"); // Reset X and Theta position
  setIntake(127); // Run intake in reverse
  setDelivery(0); // Stop running delivery
  setLift(80);  // Stop running lift
  DriveCoordShort(106,114,93,1);  // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(117,108,93,1.25); // Line up with Ball
  DriveCoordShort(124.5,108,93,1); // Pick up Ball

  // ----- Goal ----- //
  setIntake(0);
  DriveCoordShort(121,121,45,1); // Line up with Goal
  setLift(0);
  DriveCoordShort(125.8,126,47,1); // Drive into Goal
  setDelivery(-40);   //Start running delivery slowly in reverse
  setLift(-40);   //Start running lift slowly in reverse
  pros::delay(400);   //Wait for ball to slowly move down
  FilterBall("blue",2);


// ---------- GOAL 6 ---------- //
  // ----- Ball 1 ----- //
  setIntake(-127);    //Run intake in reverse
  setDelivery(-127);   //Stop running delivery
  setLift(80);   //Stop running lift
  DriveCoordShort(116,116,45,1); // Drive from Goal
  DriveCoordShort(93,95,182,2); // Line up with Ball
  setIntake(127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(80);   //Stop running lift
  DriveCoordShort(93,72.5,180,1); // Pick up Ball
  // --------------------- NEW CODE -------------------- //
  DriveCoordShort(92,71,275,1);
  setLift(0);
  setIntake(-80);
  DriveCoordShortNoPID(82,70.5,278,1);
  DriveCoordShortNoPID(87,70.5,278,1);
  DriveCoordShortNoPID(82,70,280,1);
  DriveCoordShortNoPID(87,70.5,278,1);
  DriveCoordShortNoPID(82,70,280,1);
  setIntake(0);
  DriveCoordShort(79.6,62.8,323,1);
  setDelivery(127);
  setLift(127);
  pros::delay(800);
  setDelivery(0);
  setLift(0);
  //
  // // ----- Ball 2 ----- //
  // DriveCoordShort(92.5,68,93.5,1); // Line up with Ball
  // DriveCoordShort(113,68,92,1); // Pick up Ball
  // pros::delay(400); // Wait for Ball to be picked up
  //
  // // ----- Goal ----- //
  // setIntake(0); // Stop the Intake
  // setLift(0); // Stop the Lift
  // DriveCoordShort(115,65.8,95,1); // Drive into Goal
  // setDelivery(-40); // Start running delivery slowly in reverse
  // setLift(-40); // Start running lift slowly in reverse
  // pros::delay(400); // Wait for ball to slowly move down
  // FilterBall("blue",1); // Cycle 1 Ball while Filtering Blue
  //
  //
  // // ---------- GOAL 7 ---------- //
  // setIntake(-127);  // Run intake in reverse
  // setDelivery(-127);  // Stop running delivery
  // setLift(80);  // Stop running lift
  // pros::delay(99999999);
  // DriveCoordShort(113,68.5,92,1); // Back away from Goal
  // DriveCoordShort(109,44,182,2);  // Line up with Ball
  //
  // // ----- Reset Odometry ----- //
  // resetY=22;  // Set Y postion
  // pros::Task lo(lineReset); // Begin line reset
  // quickAlignNorthEast("X"); // Reset X and Theta position
  //
  // // ----- Ball 1 ----- //
  // maxSpeed=100; // Slow the Robot down
  // setDelivery(0); //Stop running delivery
  // setIntake(127); //Start running intake forward to pick up ball
  // setLift(60);  //Start running lift
  // DriveCoordShort(109,18,180,1); // Pick up Ball
  // maxSpeed=200; // Return the Robot to normal Speed
  //
  // // ----- Goal ----- //
  // DriveCoordShort(121,21,136,1);  // Line up with Goal
  // DriveCoordShort(126.4,16,136,1);  // Drive into Goal
  // FilterBall("blue",1); // Filter 1 Ball while Filtering Blue
  //
  //
  // // ---------- Goal 8 ---------- //
  // // ----- Ball 1 ----- //
  // setIntake(-127);  // Run intake in reverse
  // setDelivery(-127);  // Stop running delivery
  // setLift(80);  // Stop running lift
  // DriveCoordShort(113,34.7,88,1); // Line up with Ball
  // setDelivery(0); //Stop running delivery
  // setIntake(127); //Start running intake forward to pick up ball
  // setLift(60);  //Start running lift
  // DriveCoordShort(126,34.7,88,1); // Pick up Ball
  //
  // // ------ Goal ----- //
  // DriveCoordShort(89,62.8,-93,1); // Line up with Goal
  // setLift(0);
  // DriveCoordShort(83.7,63,-98,1); // Punch Goal
  // DriveCoordShort(89,62.8,-93,1); // Back away from Goal
  // DriveCoordShort(83.7,63,-98,1); // Punch Goal
  // DriveCoordShort(89,62.8,-93,1); // Back away from Goal
}
