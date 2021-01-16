#include "main.h"
using namespace okapi;
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

 $$$$$$\  $$\       $$\ $$\ $$\
$$  __$$\ $$ |      \__|$$ |$$ |
$$ /  \__|$$ |  $$\ $$\ $$ |$$ | $$$$$$$\
\$$$$$$\  $$ | $$  |$$ |$$ |$$ |$$  _____|
 \____$$\ $$$$$$  / $$ |$$ |$$ |\$$$$$$\
$$\   $$ |$$  _$$<  $$ |$$ |$$ | \____$$\
\$$$$$$  |$$ | \$$\ $$ |$$ |$$ |$$$$$$$  |
 \______/ \__|  \__|\__|\__|\__|\_______/

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

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/


void A_SKILLS_JANUARY(){
  // ----- SET UP ----- //
  drive->setState({58.75_in,16_in,-90_deg});
  maxSpeed=220;

// ---------- GOAL 1 ---------- //
  // ----- Unfold ----- //
  DriveCoordShort(58,24,-90,1);   //Line up with ball
  setIntake(-127);    //Run intake in reverse to deploy
  setDelivery(127);   //Spin the delivery forward
  pros::delay(1000);    //Wait for robot to unfold

  // ----- Ball 1 ----- //
  setDelivery(0);
  setIntake(127);
  setLift(80);
  DriveCoordShort(33.8,24,-90,1);

  // ----- Ball 2 ----- //
  DriveCoordShort(24.1,36.3,-88.9,1);
  DriveCoordShort(17,36.4,-88.9,1);

  // ----- Goal ----- //
  DriveCoordShort(21.9,21.8,-130.5,1);
  setIntake(0);
  setLift(0);
  setDelivery(0);
  DriveCoordShort(15,15,-133.4,1);
  FilterBall("blue",1);

// ---------- GOAL 2 ---------- //
  // ----- Ball 1 ----- //
  setDelivery(-127);
  setIntake(-127);
  setLift(80);
  DriveCoordShort(21.9,21.8,-130.5,3);
  DriveCoordShort(48.5,51.2,3.8,2);
  setDelivery(0);
  setIntake(127);   //Run intake forward to pick up a ball
  setLift(60);   //Start running lift
  DriveCoordShort(49,70,5,1);   //Drive forward to pick up ball

  // ----- Ball 2 ----- //
  DriveCoordShort(52,70,-86,.75);   //Turn to face next ball
  DriveCoordShort(24,72,-88,0.5);   //Drive forward to pick up ball
  pros::delay(200);   //Wait for ball to pick up
  setIntake(0);    //Stop intake

  // ----- Goal ---- //
  DriveCoordShort(21,71.8,-90,0.5);   //Drive into goal
  setDelivery(-40);   //Start running delivery slowly in reverse
  setLift(-40);   //Start running lift slowly in reverse
  pros::delay(400);   //Wait for ball to slowly move down
  FilterBall("blue",1);

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  setIntake(-127);    //Run intake in reverse
  setDelivery(-127);   //Stop running delivery
  setLift(80);   //Stop running lift
  DriveCoordShort(46,71.8,-90,0.9);   //Back away from goal
  DriveCoordShort(40.2,99.4,4.3,1.1);   //Line up with ball
  pros::delay(300);
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(60);   //Start running lift
  // ----- Reset Position ----- //
  resetY=118.5;
  pros::Task yo(lineReset);
  DriveCoordShort(42.2,121.2,3.1,1.1);
  quickAlign();
  drive->setState({fabs(XYVal)*1_in,drive->getState().y,thetaVal*1_deg});

  // ----- Ball 2 ----- //
  DriveCoordShort(30.6,105.1,-86.4,1.1);   //Line up with ball
  DriveCoordShort(24.2,105.8,-88.2,1.1);
  DriveCoordShort(27.7,122.1,-44.3,1.1);
  DriveCoordShort(24.2,126.5,-46.3,1.1);
  setDelivery(-40);   //Start running delivery slowly in reverse
  setLift(-40);   //Start running lift slowly in reverse
  pros::delay(400);   //Wait for ball to slowly move down
  FilterBall("blue",1);

// ---------- GOAL 4 ---------- //
  setIntake(-127);    //Run intake in reverse
  setDelivery(-127);   //Stop running delivery
  setLift(80);   //Stop running lift
  DriveCoordShort(27.7,122.1,-44.3,1.1);
}
