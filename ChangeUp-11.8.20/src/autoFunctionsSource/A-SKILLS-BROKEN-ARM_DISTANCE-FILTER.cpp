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

11 Red balls
7 Blue balls
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

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void a_SKILLS_BROKEN_ARM_DISTANCE_FILTER(){
// ---------- PREPARE THE PROGRAM ---------- //
startTime=pros::millis();   //Set up the timer
drive->setState({19_in,15_in,-90_deg});   //Set the state for odometry

// ---------- Goal 1 (Home Row Left Corner) ---------- //
  // ----- Preparation ----- //
  DriveCoordShort(18.5,16,-126,0.55);   //Turn to face goal

  // ----- Score in Goal ----- //
  setDelivery(127);   //Start running delivery
  setLift(127);   //Start running lift
  pros::delay(500);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

// ---------- Goal 2 (Left Wall) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(49.7, 42, 6, 3);   //Move to line up with next ball while spinning to face it
  setIntake(-127);    //Deploy intake
  pros::delay(900);   //Wait for it to deploy

  setIntake(127);   //Run intake forward to pick up a ball
  setLift(127);   //Start running lift
  DriveCoordShort(50,70,5,1);   //Drive forward to pick up ball
  DriveCoordShort(52,70,-86,.75);   //Turn to face next ball
  DriveCoordShort(24,72,-88,0.5);   //Drive forward to pick up ball
  pros::delay(200);   //Wait for ball to pick up
  setIntake(0);    //Stop intake
  DriveCoordShort(22,71.8,-90,0.5);   //Drive into goal

  // ----- Score in Goal ----- //
  setDelivery(-40);   //Start running delivery slowly in reverse
  setLift(-40);   //Start running lift slowly in reverse
  pros::delay(400);   //Wait for ball to slowly move down
  FilterBall("blue",1);

  // setDelivery(127);   //Start running delivery
  // setLift(80);   //Start running lift
  // pros::delay(1000);   //Wait for ball to score

  setIntake(-127);    //Run intake in reverse
  setDelivery(-127);   //Stop running delivery
  setLift(80);   //Stop running lift

// ---------- Goal 3 (Back Left Corner) ---------- //
  // ----- Transition to Goal----- //
  DriveCoordShort(46,71.8,-90,0.9);   //Back away from goal
  DriveCoordShort(44,95,6.7,1.4);   //Line up with ball
  pros::delay(300);
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(44,122,6.3,1.2);   //Pick up ball
  DriveCoordShort(31,119,-32.2,1.25);  //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(25,127,-37,0.75); //Drive into goal

  // ----- Score in Goal ----- //
  // setDelivery(127);   //Start running delivery
  // setIntake(0);   //Stop intake
  // pros::delay(550);   //Wait for ball to score
  FilterBall("blue", 1);
  pros::delay(100);
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

// ---------- Reset alignment ---------- //
  //-----Prepare-----//
  DriveCoordShort(29,92,6,1.25); //Back away from goal

  // ----- Align ----- //
  pros::Task yeet(filterWhileAlign);
  filtered=false;
  //While the left back and left front distance sensors are not equal within a margin of error and those values are not within a specific range...
  while((leftTrackFront.get()<leftTrackBack.get()-0.5 || leftTrackFront.get()>leftTrackBack.get()+0.5) || ((frontTrack.get() > 1500) || (frontTrack.get() < 900)) & (!filtered)){
    double pow=(leftTrackBack.get()-leftTrackFront.get());    //Create a local variable that calculates the difference in sensor values

    if(leftTrackBack.get()>leftTrackFront.get())    //if the back value is greater than the front value...
      pow+=10;    //...Add 10 to the local variable "pow"
    if(leftTrackBack.get()<leftTrackFront.get())    //if the back value is less than the front value...
      pow-=10;    //...Subtract 10 from the local variable "pow"

    setDrive(pow,pow,-pow,-pow);    //Set the drive using the local variable "pow"
    pros::delay(10);    //Delay to save power
  }

  //Reset state: X-Subtract 1 inch from the left front sensor distance plus distance from the center Y-Subtract the front sensor from 142 plus distance from the center THETA-0
  drive->setState({-1_in+(leftTrackFront.get()*0.0393701_in)+8.5_in,(142*1_in)-(frontTrack.get()*0.0393701_in)+5_in,0_deg});

  // ----- Put all motors on brake type hold to get accurate values ----- //
    left_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    left_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);

  setDrive(0,0,0,0);    //Stop the drive
// ---------- Goal 4 (Back wall) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(48,99,90,2);   //Line up with ball
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(69,99,90,0.85);   //Pick up ball
  DriveCoordShort(71,121,0,1.3);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(71,130.5,0,0.6);    //Drive into goal

  // ----- Score in Goal ----- //
  // setDelivery(127);   //Start running delivery
  // setIntake(0);   //Stop running intake
  // pros::delay(550);   //Wait for ball to score
  FilterBall("blue",1);
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

// ---------- Goal 5 (Back Right Corner) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(71.6,121,0,0.9); //Back away from goal
  setIntake(127);    //Run intake in reverse
  setDelivery(-127);   //Stop running delivery
  setLift(60);   //Stop running lift
  DriveCoordShort(87,122,90,1.15); //Drive in front of ball
  pros::delay(100);
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(110,121,87,1.9);    //Pick up ball
  DriveCoordShort(110,120,52,0.9);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(128.3,129.5,52.6,1);    //Drive into goal

  // ----- Score in Goal ----- //
  // setDelivery(127);   //Start running delivery
  // setIntake(0);   //Stop running intake
  // pros::delay(750);   //Wait for ball to score
  FilterBall("blue",1);
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

// ---------- Reset alignment ---------- //
  // ----- Prepare ----- //
  DriveCoordShort(109,125,95,0.9);   //Back from goal

  // ----- Align ----- //
  pros::Task yeet2(filterWhileAlign);
  filtered=false;
  //While the left back and left front distance sensors are not equal within a margin of error and those values are not within a specific range...
  while((leftTrackFront.get()<leftTrackBack.get()-0.5 || leftTrackFront.get()>leftTrackBack.get()+0.5) || ((frontTrack.get() > 1200) || (frontTrack.get() < 500)) & (!filtered)){
    double pow=(leftTrackBack.get()-leftTrackFront.get());    //Create a local variable that calculates the difference in sensor values

    if(leftTrackBack.get()>leftTrackFront.get())    //if the back value is greater than the front value...
      pow+=10;    //...Add 10 to the local variable "pow"
    if(leftTrackBack.get()<leftTrackFront.get())    //if the back value is less than the front value...
      pow-=10;    //...Subtract 10 from the local variable "pow"

    setDrive(pow,pow,-pow,-pow);    //Set the drive using the local variable "pow"
    pros::delay(10);    //Delay to save power
  }

  //Reset state: X-Subtract the left front sensor distance from 142 minus distance from the center Y-Subtract the front sensor from 142 plus distance from the center THETA-90
  drive->setState({(142*1_in)-(frontTrack.get()*0.0393701_in)-5_in,(142*1_in)-(leftTrackFront.get()*0.0393701_in)-8.5_in,90_deg});

  // ----- Put all motors on brake type hold to get accurate values ----- //
    left_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    left_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);

  setDrive(0,0,0,0);    //Stop the driv

// ---------- Goal 6 (Right wall) ---------- //
  // ---- Transition to Goal ---- //
  DriveCoordShort(91,93.8,184.5,12);   //Line up with next ball
  pros::delay(300);
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(80);   //Start running lift
  DriveCoordShort(90,69.8,184.5,1);   //Drive forward to pick up ball
  DriveCoordShort(90.9,71,92.9,0.75);   //Turn to face next ball
  DriveCoordShort(109,70,94,1.1);   //Line up with goal
  pros::delay(200);   //Wait for ball to pick up
  setIntake(0);   //Stop running the intake
  DriveCoordShort(119,71,91,1);   //Drive into goal

  // ----- Score in Goal ----- //
  setDelivery(-40);   //Start running delivery slowly in reverse
  setLift(-60);   //Start running lift slowly in reverse
  pros::delay(300);   //Wait for ball to slowly move down

  setDelivery(127);   //Start running lift again
  setLift(127);   //Start running delivery
  pros::delay(1250);   //Wait for ball to score
  // FilterBall("blue",1);
  // pros::delay(400);
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

// ---------- Goal 7 (Bottom Right Corner) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(104,70,94,1);   //Back up from goal
  DriveCoordShort(100,45,184,8);   //Line up with ball
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(95,20,183,2);    //Drive forward to pick up ball
  DriveCoordShort(109.7,21,134,0.75);    //Line up with goal
  setIntake(0);   //Stop running intake
  pros::delay(200);   //Wait a bit
  DriveCoordShort(119,14,138,0.75);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift


// ---------- Reset Alignment ---------- //
  // ----- Prepare ----- //
  DriveCoordShort(107,51,185,2.5); //Back away from goal
  setIntake(0);

  // ----- Align ----- //
  pros::Task yeet3(filterWhileAlign);
  filtered=false;
  //While the left back and left front distance sensors are not equal within a margin of error and those values are not within a specific range...
  while((leftTrackFront.get()<leftTrackBack.get()-0.5 || leftTrackFront.get()>leftTrackBack.get()+0.5) || ((frontTrack.get() > 1400) || (frontTrack.get() < 500)) & (!filtered)){
    double pow=(leftTrackBack.get()-leftTrackFront.get());    //Create a local variable that calculates the difference in sensor values

    if(leftTrackBack.get()>leftTrackFront.get())    //if the back value is greater than the front value...
      pow+=10;    //...Add 10 to the local variable "pow"
    if(leftTrackBack.get()<leftTrackFront.get())    //if the back value is less than the front value...
      pow-=10;    //...Subtract 10 from the local variable "pow"

    setDrive(pow,pow,-pow,-pow);    //Set the drive using the local variable "pow"
    pros::delay(10);    //Delay to save power
  }

  //Reset state: X-Subtract the left front sensor distance from 142 inches minus distance from the center Y-Add 2 to the front sensor from 142 plus distance from the center THETA-180
  drive->setState({(142*1_in)-(leftTrackFront.get()*0.0393701_in)-8.5_in,4_in+(frontTrack.get()*0.0393701_in)+5_in,180_deg});

  // ----- Put all motors on brake type hold to get accurate values ----- //
    left_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    left_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);

  setDrive(0,0,0,0);    //Stop the drive

// ---------- Goal 8 (Center) ---------- //
  // ----- Transition to Goal-----//
  setIntake(127);   //Start running intake
  setLift(127);   //Start running lift
  setDelivery(0);
  DriveCoordShort(116.5,39,90,1.5);   //Line up with ball
  DriveCoordShort(125.5,39,90,1);    //Pick up ball
  DriveCoordShort(94,74,274,2.3);    //Drive in front of goal

  // ----- Descore from Goal ----- //
  setIntake(127);   //Run intake in reverse
  setLift(0);   //Stop running lift

  DriveCoordShort(84.5,75,274,1);    //Drive in front of goal
  DriveCoordShort(93,75,274,0.75);   //Back away
  //
  // DriveCoordShort(84.5,73,274,1);    //Drive in front of goal
  // DriveCoordShort(93,73,274,1);   //Back away

  DriveCoordShort(84.5,75,274,0.75);    //Drive in front of goal
  DriveCoordShort(95.8,73.1,277,1);   //Back away

  // ----- Transition to Score ----- //
  DriveCoordShort(90,63,313,2);   //Line up with goal
  DriveCoordShort(82.6,69,314,1);   //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(1100);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery

// ---------- Goal 9 (Front Wall) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(95,56,309,3);   //Back away from goal
  DriveCoordShort(93,55,269,0.95);    //Turn to face ball
  setIntake(127);   //Start running intake to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(70,55,266,1.25);    //Pick up ball
  DriveCoordShort(70,31,180,1.3);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(70,23,180,0.5);    //Drive into goal

  // ----- Score in Goal ----- //
  // setDelivery(127);   //Start running delivery
  // pros::delay(550);   //Wait for ball to score
  FilterBall("blue",1);
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

  DriveCoordShort(70,40,180,0.5);   //Back away from goal
}
