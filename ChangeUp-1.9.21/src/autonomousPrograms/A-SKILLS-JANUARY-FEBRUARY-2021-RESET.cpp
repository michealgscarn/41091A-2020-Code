#include "main.h"
using namespace okapi;
/*------------------------------------------
  ____   _     _  _  _
 / ___| | | __(_)| || | ___
 \___ \ | |/ /| || || |/ __|
  ___) ||   < | || || |\__ \
 |____/ |_|\_\|_||_||_||___/

Created on 7/15/2020 by Taylor and Logan
Last Updated on 2/25/2021 by Taylor and Logan

1 minute Autonomous

14 Red balls  (Max - 14)
15 Blue balls (Max - 15)
9 Goals       (Max - 9)
126 points    (Max - 126)

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


void A_SKILLS_JANUARY_FEBRUARY_2021_RESET(){
// ---------- SET UP ---------- //
  drive->setState({58.75_in,16_in,-90_deg});
  maxSpeed=500;

// ---------- GOAL 1 ---------- //
  // ----- Unfold ----- //
  setIntake(-127);  // Run intake in reverse to deploy
  setDelivery(127); // Spin the delivery forward
  DriveCoordShort(58,24,-90,0.8); // Line up with ball

  // ----- Ball 1 ----- //
  setDelivery(0); // Stop the Delivery
  setIntake(127); // Spin the Intake inward
  setLift(95);  // Spin the Lift forward
  DriveCoordShort(33,24,-90,0.8); // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(26.1,35.3,-88.9,0.9); // Line up with Ball
  DriveCoordShort(17,35.4,-88.9,0.6); // Pick up Ball

  // ----- Goal ----- //
  setDelivery(0); // Stop the Delivery
  DriveCoordShort(21.9,21.8,-130.5,0.9);  // Line up with goal
  setIntake(0); // Stop the Intake
  DriveCoordShort(10,10,-131.4,0.5);  // Drive into Goal
  cycleScoreCorner(2,3,2);

// ---------- GOAL 2 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(30,30,-130.5,0.85);  // Back up from Goal
  DriveCoordShort(47,48,3.8,1.55); // Line up with Ball
  setDelivery(0); // Stop the Delivery
  setIntake(127); // Run intake forward to pick up a ball
  setLift(90);  // Start running lift
  DriveCoordShort(47,70,5,0.9); // Drive forward to pick up ball

  // ----- Ball 2 ----- //
  DriveCoordShort(52,70,-86,.75); // Turn to face next ball

  // ----- Goal ---- //
  setLift(0);  // Start running lift
  setLift(90);  // Start running lift
  setIntake(80); // Run intake forward to pick up a ball
  DriveCoordShort(19,75,-86.5,1); // Drive into goal
  cycleScore(2,3,2);

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(27,75.8,-90,0.5); // Back away from goal
  DriveCoordShort(37,95,4.3,1.35); // Line up with ball
  stopFilter=true;
  setDelivery(0); //Stop running delivery
  setIntake(127); //Start running intake forward to pick up ball
  setLift(80);   //Start running lift

  // ----- Reset Position ----- //
    setDelivery(0); //Stop running delivery
    setIntake(127); //Start running intake forward to pick up ball
    setLift(90);   //Start running lift
  resetY=117.5; // Set the Y reset Position
  pros::Task yo(lineReset); // Start the Line Reset
  quickAlign(36,1);
  maxSpeed=100; // Drive Slowly across the Line
  DriveCoordShort(35,122,3.1,1);  // Pick up Ball
  maxSpeed=500; // Resume normal Speed

  // ----- Ball 2 ----- //
  DriveCoordShort(30,106,-90,1.1);  // Line up with ball
  DriveCoordShort(19,106,-90,0.6);  // Pick up Ball

  // ----- Goal ----- //
  DriveCoordShort(23.6,120,-50,0.9);  // Line up with Goal
  setIntake(0);
  pros::Task yello(cycleScoreSetup);
  DriveCoordShort(14,131,-51,0.6);  // Drive into Goal
  cycleScoreCorner(2,3,2);


// ---------- GOAL 4 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(30,110,-50,1);  // Back away from goal
  DriveCoordShort(51,93,90,1.5);  // Line up with Ball
  setIntake(127); // Run intake in reverse
  setDelivery(0); // Stop running delivery
  setLift(80);  // Stop running lift
  DriveCoordShort(72.5,93,90,1);  // Pick up Ball

  // ----- Goal ---- //
  setIntake(10);  // Run intake in reverse
  DriveCoordShort(74,119,-3,1.25); // Drive into Goal
  cycleScore(1,3,1);

// ---------- GOAL 5 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(72.8,110,-3,0.9); // Drive away from Goal
  DriveCoordShort(87,116,91,1.7); // Line up with Ball
  setLift(127);  // Stop running lift

  quickAlign(116,2);

  setIntake(127); // Run intake in reverse
  setLift(127);  // Stop running lift
  setDelivery(0); // Stop running delivery
  stopFilter=true;
  DriveCoordShort(106,116,93,0.9);  // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(117,108.5,93,0.8); // Line up with Ball
  DriveCoordShort(127,108.5,93,0.9); // Pick up Ball

  // ----- Goal ----- //
  DriveCoordShort(121,121,45,0.8); // Line up with Goal
  setIntake(0);
  setLift(0);
  DriveCoordShort(129.5,130.5,50,0.75); // Drive into Goal
  cycleScoreCorner(2,3,2);


// ---------- GOAL 6 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(116,116,45,1); // Drive from Goal
  DriveCoordShort(96,95,182,1.55); // Line up with Ball
  setIntake(127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(127);   //Stop running lift
  DriveCoordShort(93,72.5,180,0.75); // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(92.5,73,93.5,0.9); // Line up with Ball

  // ----- Goal ----- //
  // pros::Task setUpGoal6(cycleScoreSetup);
  setLift(0);
  setIntake(80);
  DriveCoordShort(124,73,92,1); // Drive into Goal
  cycleScore(2,2.25,2); // Cycle 1 Ball while Filtering Blue

// ---------- GOAL 7 ---------- //
  DriveCoordShort(113,73,92,0.5); // Back away from Goal
  DriveCoordShort(105,50,182,1.8);  // Line up with Ball
  while(ballFiltering()){pros::delay(10);}

  // ----- Reset Odometry ----- //
  resetY=22.5;  // Set Y postion
  pros::Task lo(lineReset); // Begin line reset
  quickAlign(106,3);
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  maxSpeed=100;
  while(ballFiltering()){pros::delay(10);}
  stopFilter=true;
  setLift(127);   //Start running lift
  DriveCoordShort(106,23,183,1);    //Drive forward to pick up ball
  maxSpeed=500;
  DriveCoordShort(119,21,137,0.55);    //Line up with goal
  pros::delay(200);   //Wait a bit
  setIntake(0);   //Stop running intake
  DriveCoordShort(137,10,135,0.5);    //Drive into goal

  //-----Score in Goal-----//
  cycleScoreCorner(2,3,1);
  DriveCoordShort(116,30,145,1); //Back away from goal

// ---------- Goal 8 (Center) ---------- //
  // ----- Transition to Goal-----//
  DriveCoordShort(108,34,90,1);   //Line up with ball

  setIntake(127);   //Start running intake
  setLift(127);   //Start running lift
  setDelivery(0);
  DriveCoordShort(125.5,34,90,0.9);    //Pick up ball
  setIntake(127);   //Start running intake
  setLift(80);   //Start running lift
  setDelivery(0);
  DriveCoordShort(94,64,270,1.9);    //Drive in front of goal
  pros::delay(400);

  // ----- Descore from Goal ----- //
  setIntake(-127);   //Run intake in reverse
  setLift(-30);   //Stop running lift
  setDelivery(-30);
  DriveCoordShortNoPID(75,64.5,270,0.35);    //Drive in front of goal
  DriveCoordShortNoPID(92,65,270,0.35);    //Drive in front of goal
  DriveCoordShortNoPID(75,65,270,0.35);    //Drive in front of goal
  DriveCoordShortNoPID(92,65,270,0.35);    //Drive in front of goal
  DriveCoordShortNoPID(75,65,270,0.35);    //Drive in front of goal

  DriveCoordShort(81.5,56.5,318,0.7);   // Line up to shoot
  setIntake(0);

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setLift(127);
  pros::delay(800);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery

// ---------- Goal 9 (Front Wall) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(96,48,309,0.85);   //Back away from goal
  DriveCoordShort(93,45.5,273,0.6);    //Turn to face ball
  setIntake(127);   //Start running intake to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(70,45.5,273,0.7);    //Pick up ball
  pros::delay(200);
  setLift(0);   //Start running lift
  DriveCoordShort(72,28,180,1.2);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(72,18,180,0.5);    //Drive into goal

  // ----- Score in Goal ----- //
  cycleScore(2,3,1);
  DriveCoordShort(70,40,180,0.5);   //Back away from goal
}