#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
  ____   _  __ ___  _      _      ____
 / ___| | |/ /|_ _|| |    | |    / ___|
 \___ \ | ' /  | | | |    | |    \___ \
  ___) || . \  | | | |___ | |___  ___) |
 |____/ |_|\_\|___||_____||_____||____/

 Created on 1/2/2021 by Logan and Taylor
 Last Updated on 1/27/2021 by Logan and Taylor

1 minute Autonomous

11 Red balls
9 Blue balls
9 Goals
116 points

PREPARE THE PROGRAM
-------------------
Set up the robot's Odometry positon

GOAL 1
------
Turn towards the bottom left goal and shoot preload in.

GOAL 2
------
Drive towards the ball left of center and pick up.
Pick up second ball in line of the middle left goal.
Score in the middle left goal while picking the blue ball.

GOAL 3
------
Drive up to the ball diagonal of the top left goal while filtering the blue ball.
Pick up the blall and drive up towards the top left goal.
Score in the goal while filtering one blue ball and holding the other.

RESET ODOMETERY
---------------
Drive backwards and reset the robot's Odometry position using the distance sensors

GOAL 4
------
Drive up towards the red ball vertically in line with the top middle goal.
Pick up the ball and drive towards the top middle goal.
Score the ball while picking up the blue ball.

GOAL 5
------
Drive towards the ball diagonal of the top right goal while filtering the blue ball.
Pick up the red ball and score in the top right goal.

RESET ODOMETRY
--------------
Drive backwards and reset the robot's Odometry position.

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

-----------------------------------------------------------------------------*/

void a_SKILLS_BROKEN_ARM_DISTANCE_FILTER_IGNITE(){
// ---------- PREPARE THE PROGRAM ---------- //
startTime=pros::millis();   //Set up the timer
drive->setState({19_in,15_in,-90_deg});   //Set the state for odometry
maxSpeed=250;
filter=true;

// ---------- Goal 1 (Home Row Left Corner) ---------- //
  // ----- Preparation ----- //
  DriveCoordShort(18.5,16,-125,0.55);   //Turn to face goal

  // ----- Score in Goal ----- //
  setDelivery(127);   //Start running delivery
  setLift(127);   //Start running lift
  pros::delay(500);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

// ---------- Goal 2 (Left Wall) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(46.5, 42, 7, 3);   //Move to line up with next ball while spinning to face it
  setIntake(-127);    //Deploy intake
  pros::delay(900);   //Wait for it to deploy

  setIntake(127);   //Run intake forward to pick up a ball
  setLift(127);   //Start running lift
  DriveCoordShort(46.5,70,7,1);   //Drive forward to pick up ball
  DriveCoordShort(55,69,-86,.75);   //Turn to face next ball
  DriveCoordShort(24,71,-88,1);   //Drive forward to pick up ball
  pros::delay(300);   //Wait for ball to pick up
  setIntake(0);    //Stop intake
  DriveCoordShort(21,71.8,-90,0.5);   //Drive into goal
  pros::delay(400);
  // ----- Score in Goal ----- //
  setDelivery(-80);   //Start running delivery slowly in reverse
  setLift(-80);   //Start running lift slowly in reverse
  pros::delay(100);   //Wait for ball to slowly move down
  cycleScore(1,2,1);

// ---------- Goal 3 (Back Left Corner) ---------- //
  // ----- Transition to Goal----- //
  DriveCoordShort(46,71.2,-90,1.2);   //Back away from goal
  DriveCoordShort(40.5,95,3,1.4);   //Line up with ball
  pros::delay(300);
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  resetY=117.5; // Set the Y reset Position
  pros::Task yo(lineReset); // Start the Line Reset
  quickAlign("X");  // Reset the X position
  // pros::delay(1000000);
  maxSpeed=80;
  DriveCoordShort(37.5,123,3,2);   //Pick up ball
  maxSpeed=250;
  DriveCoordShort(30,113,-45,1.2);  //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(13.5,122.5,-45,0.75); //Drive into goal

  // ----- Score in Goal ----- //
  // setDelivery(127);   //Start running delivery
  // setIntake(0);   //Stop intake
  // pros::delay(550);   //Wait for ball to score
  filter=false;
  cycleScore(1,3,1);
  filter=true;
// ---------- Reset alignment ---------- //
  //-----Prepare-----//
  DriveCoordShort(30,106,-40,1.25); //Back away from goal //---------NEW CODE--------//

// ---------- Goal 4 (Back wall) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(48,93,89,1.5);   //Line up with ball
  cycleScoreFilter();
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(70,93,89,0.85);   //Pick up ball
  DriveCoordShort(73,113,0,1.2);    //Line up with goal   48, 93
  setIntake(0);   //Stop running intake
  DriveCoordShort(73,124,0,0.6);    //Drive into goal

  // ----- Score in Goal ----- //
  // setDelivery(127);   //Start running delivery
  // setIntake(0);   //Stop running intake
  // pros::delay(550);   //Wait for ball to score
  cycleScore(1,3,1);

// ---------- Goal 5 (Back Right Corner) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(73.6,107,0,0.9); //Back away from goal
  DriveCoordShort(85,115,90,1.15); //Drive in front of ball
  // quickAlignNorthEast("Y"); // Reset X and Theta position
  pros::delay(100);
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(112,115,87,1.9);    //Pick up ball
  DriveCoordShort(115,112,52,0.75);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(132,130.5,55,1);    //Drive into goal

  // ----- Score in Goal ----- //
  // FilterBall("blue", 2);
  // setIntake(-127);    //Run intake in reverse
  // pros::delay(400);
  // setDelivery(-127);
  // setLift(-127);
  // pros::delay(300);
  // setDelivery(-127);   //Stop running delivery
  // setLift(127);   //Stop running lift
  cycleScore(1,3,1);

  DriveCoordShort(125,123.5,53,1);    //Drive into goal

// ---------- Goal 6 (Right wall) ---------- //
  // ---- Transition to Goal ---- //
  DriveCoordShort(93,97.8,184.5,1.7);   //Line up with next ball
  pros::delay(300);
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(90);   //Start running lift
  DriveCoordShort(94,68.8,184.5,1);   //Drive forward to pick up ball
  DriveCoordShort(85,70,92.9,0.75);   //Turn to face next ball
  DriveCoordShort(112,70,97,1.1);   //Line up with goal
  pros::delay(200);   //Wait for ball to pick up
  setIntake(0);   //Stop running the intake
  DriveCoordShort(123,70,96,1);   //Drive into goal
  pros::delay(250);
  setDelivery(-50);
  setLift(-50);
  pros::delay(100);

  // ----- Score in Goal ----- //
  filter=false;
  cycleScore(1,3,1);
  filter=true;
// ---------- Goal 7 (Bottom Right Corner) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(104,70,94,1);   //Back up from goal
  pros::Task dfdsfds(cycleScoreFilter);
  DriveCoordShort(101,45,184,8);   //Line up with ball
  // ----- Reset Odometry ----- //
  resetY=22;  // Set Y postion
  pros::Task lo(lineReset); // Begin line reset
  quickAlignNorthEast("X"); // Reset X and Theta position

  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  maxSpeed=80;
  DriveCoordShort(106,18,183,1.5);    //Drive forward to pick up ball
  maxSpeed=250;
  DriveCoordShort(119,21,137,0.65);    //Line up with goal
  setIntake(0);   //Stop running intake
  pros::delay(200);   //Wait a bit
  DriveCoordShort(138,10,137,0.75);    //Drive into goal

  //-----Score in Goal-----//
  filter=false;
  cycleScore(1,3,1);
  filter=true;

  DriveCoordShort(125,21,138,1); //Back away from goal

// ---------- Goal 8 (Center) ---------- //
  // ----- Transition to Goal-----//
  DriveCoordShort(116.5,35,90,1.5);   //Line up with ball 199 33
  cycleScoreFilter();


  setIntake(127);   //Start running intake
  setLift(127);   //Start running lift
  setDelivery(0);
  DriveCoordShort(127.5,35,90,0.9);    //Pick up ball
  setIntake(127);   //Start running intake
  setLift(127);   //Start running lift
  setDelivery(0);
  DriveCoordShort(94,66,274,2.3);    //Drive in front of goal
  pros::delay(400);

  // ----- Descore from Goal ----- //
  setIntake(-127);   //Run intake in reverse
  setLift(0);   //Stop running lift
  setDelivery(0);

  // maxSpeed=600;
  //
  // DriveCoordShort(80,69,274,1);    //Drive in front of goal
  // DriveCoordShort(100,69,274,0.75);   //Back away

  DriveCoordShort(80,70,274,1);    //Drive in front of goal
  pros::delay(500);
  DriveCoordShort(85,55,318,0.75);   //Back away

  // DriveCoordShort(84.5,73,274,0.75);    //Drive in front of goal
  // DriveCoordShort(95.8,73,277,0.75);   //Back away

  // maxSpeed=200;

  // ----- Transition to Score ----- //
  // DriveCoordShort(85.7,61.6,313,2);   //Line up with goal
  setIntake(0);
  DriveCoordShort(83.6,71,314,1);   //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setLift(127);
  pros::delay(1100);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery

// ---------- Goal 9 (Front Wall) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(96,48,309,3);   //Back away from goal
  DriveCoordShort(93,49,273,0.85);    //Turn to face ball
  setIntake(127);   //Start running intake to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(70,49,273,1.15);    //Pick up ball
  DriveCoordShort(72,28,180,1.3);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(68,20,180,0.5);    //Drive into goal

  // ----- Score in Goal ----- //
  // setDelivery(127);   //Start running delivery
  // pros::delay(550);   //Wait for ball to score
  cycleScore(1,3,1);
  DriveCoordShort(70,40,180,0.5);   //Back away from goal
}
