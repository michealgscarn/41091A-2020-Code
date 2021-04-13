#include "main.h"
using namespace okapi;
/*------------------------------------------
  ____   _     _  _  _
 / ___| | | __(_)| || | ___
 \___ \ | |/ /| || || |/ __|
  ___) ||   < | || || |\__ \
 |____/ |_|\_\|_||_||_||___/

Created on 7/6/2020 by Taylor and Logan
Last Updated on 2/26/2021 by Taylor and Logan

1 minute Autonomous

13 Red balls  (Max - 14)
11 Blue balls (Max - 15)
9 Goals       (Max - 9)
121 points    (Max - 126)

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



void A_SKILLS_JANUARY_FEBRUARY_2021(){
// ---------- SET UP ---------- //
  drive->setState({58.75_in,16_in,-90_deg});
  maxSpeed=500;

// ---------- GOAL 1 ---------- //
  // ----- Unfold ----- //
  setIntake(-127);  // Run intake in reverse to deploy
  setLift(-127); // Spin the delivery forward
  DriveCoordShort(58,26,-90,0.9); // Line up with ball

  // ----- Ball 1 ----- //
  setDelivery(0); // Stop the Delivery
  setIntake(127); // Spin the Intake inward
  setLift(95);  // Spin the Lift forward
  DriveCoordShort(33,26,-90,0.8); // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(26.1,36,-88.9,0.9); // Line up with Ball
  DriveCoordShort(18,36,-88.9,0.6); // Pick up Ball

  // ----- Goal ----- //
  // setLift(60); // Stop the Lift
  setDelivery(0); // Stop the Delivery
  DriveCoordShort(21.9,21.8,-130.5,0.9);  // Line up with goal
  setLift(-40);
  setDelivery(-40);
  setIntake(0); // Stop the Intake
  DriveCoordShort(15,16,-134,0.6);  // Drive into Goal
  cycleScoreCorner(2,3,2);

// ---------- GOAL 2 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(30,30,-130.5,0.85);  // Back up from Goal
  DriveCoordShort(48,48,3.8,1.55); // Line up with Ball
  setDelivery(0); // Stop the Delivery
  setIntake(127); // Run intake forward to pick up a ball
  setLift(90);  // Start running lift
  DriveCoordShort(47,70,5,0.9); // Drive forward to pick up ball

  // ----- Ball 2 ----- //
  DriveCoordShort(58,70,-85,.75); // Turn to face next ball

  // ----- Goal ---- //
  setLift(0);  // Start running lift
  setLift(90);  // Start running lift
  setIntake(80); // Run intake forward to pick up a ball
  DriveCoordShort(22,75,-86,1); // Drive into goal
  cycleScore(2,3,2);

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(27,75.8,-90,0.5); // Back away from goal
  DriveCoordShort(40,95,4.3,1.35); // Line up with ball
  stopFilter=true;
  setDelivery(0); //Stop running delivery
  setIntake(127); //Start running intake forward to pick up ball
  setLift(80);   //Start running lift

  // ----- Reset Position ----- //
    setDelivery(0); //Stop running delivery
    setIntake(127); //Start running intake forward to pick up ball
    setLift(90);   //Start running lift
  quickAlign(36,1);
  DriveCoordShort(37,117,-2,1);  // Pick up Ball
  // ----- Ball 2 ----- //
  DriveCoordShort(31.8,107,-93,1.1);  // Line up with ball
  DriveCoordShort(19.5,107,-93,0.6);  // Pick up Ball

  // ----- Goal ----- //
  DriveCoordShort(24.8,120,-52,0.9);  // Line up with Goal
  setIntake(0);
  pros::Task yello(cycleScoreSetup);
  DriveCoordShort(14,125,-42,0.6);  // Drive into Goal
  cycleScoreCorner(2,3,2);


// ---------- GOAL 4 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(30,116,-50,1);  // Back away from goal
  DriveCoordShort(47.8,94,87,1.5);  // Line up with Ball
  setIntake(127); // Run intake in reverse
  setDelivery(0); // Stop running delivery
  setLift(80);  // Stop running lift
  DriveCoordShort(69,94,88,1);  // Pick up Ball
  pros::delay(200);

  // ----- Goal ---- //
  setIntake(10);  // Run intake in reverse
  DriveCoordShort(74,122,0,1.25); // Drive into Goal
  cycleScore(1,3,1);

// ---------- GOAL 5 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(70.7,112,-2.5,0.9); // Drive away from Goal
  DriveCoordShort(83.9,120,90,1.7); // Line up with Ball
  setLift(127);  // Stop running lift
  while(ballFiltering()){pros::delay(10);}
  setIntake(127); // Run intake in reverse
  setLift(127);  // Stop running lift
  setDelivery(0); // Stop running delivery
  stopFilter=true;
  DriveCoordShort(104.4,120,90,0.9);  // Pick up Ball
  quickAlign(104,2);

  // ----- Ball 2 ----- //
  DriveCoordShort(117.5,107,86.4,0.8); // Line up with Ball
  DriveCoordShort(125,109,87.6,0.8); // Pick up Ball
  setLift(90);

  // ----- Goal ----- //
  DriveCoordShort(121.9,120.7,41.7,0.8); // Line up with Goal
  setIntake(0);
  setLift(0);
  DriveCoordShort(128,128,41.7,0.75); // Drive into Goal
  cycleScoreCorner(2,3,2);


// ---------- GOAL 6 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(118,117,41.7,0.75); // Drive from Goal
  DriveCoordShort(96,96.2,181,1.55); // Line up with Ball
  setIntake(127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(127);   //Stop running lift
  DriveCoordShort(95,75,180,0.75); // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(92,72.6,93,0.9); // Line up with Ball

  // ----- Goal ----- //
  // pros::Task setUpGoal6(cycleScoreSetup);
  setLift(0);
  setIntake(80);
  DriveCoordShort(122.8,71.8,92.9,1); // Drive into Goal
  cycleScore(2,2.25,2); // Cycle 1 Ball while Filtering Blue

  // ---------- GOAL 7 ---------- //
  DriveCoordShort(109.6,70,94,0.5); // Back away from Goal
  DriveCoordShort(106,47,180,1.8);  // Line up with Ball
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  maxSpeed=100;
  while(ballFiltering()){pros::delay(10);}
  stopFilter=true;
  setLift(127);   //Start running lift
  DriveCoordShort(105,26.6,180,1);    //Drive forward to pick up ball
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  quickAlign(103.5,3);

  maxSpeed=500;
  DriveCoordShort(119,27.5,132.5,0.55);    //Line up with goal
  pros::delay(200);   //Wait a bit
  setIntake(0);   //Stop running intake
  setDelivery(-40);
  setLift(-40);
  DriveCoordShort(130,16.7,134,0.5);    //Drive into goal

  //-----Score in Goal-----//
  cycleScoreCorner(2,3,2);
  DriveCoordShort(119,27.5,134,1); //Back away from goal

// ---------- Goal 8 (Center) ---------- //
  // ----- Transition to Goal-----//
  DriveCoordShort(108.8,38.2,88,1);   //Line up with ball

  setIntake(127);   //Start running intake
  setLift(127);   //Start running lift
  setDelivery(0);
  DriveCoordShort(124.4,38.5,86.5,0.9);    //Pick up ball
  setIntake(127);   //Start running intake
  setLift(80);   //Start running lift
  setDelivery(0);
  DriveCoordShort(94.7,68,266,1.9);    //Drive in front of goal
  pros::delay(400);

  setIntake(-20);
  setDelivery(0);
  maxSpeed=500;
  DriveCoordShortNoPID(84,68,270,0.7);    //Drive in front of goal
  DriveCoordShortNoPID(91,68,270,0.7);    //Drive in front of goal
  DriveCoordShortNoPID(84,68,270,0.7);    //Drive in front of goal
  DriveCoordShortNoPID(91,68,270,0.7);    //Drive in front of goal
  DriveCoordShortNoPID(84,68,270,0.7);    //Drive in front of goal
  maxSpeed=500;
  DriveCoordShort(79.5,59.5,318,0.7);   // Line up to shoot
  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setLift(127);
  pros::delay(800);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery

// ---------- Goal 9 (Front Wall) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(98.6,71.8,270,0.85);   //Back away from goal
  DriveCoordShort(91.4,60,236.5,0.6);    //Turn to face ball
  setIntake(127);   //Start running intake to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(71,48.5,242,0.7);    //Pick up ball
  pros::delay(200);
  setLift(0);   //Start running lift
  DriveCoordShort(72,28,180,1.2);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(73,18.7,176.5,0.5);    //Drive into goal

  // ----- Score in Goal ----- //
  cycleScore(2,3,1);
  DriveCoordShort(70,40,180,0.5);   //Back away from goal
}
