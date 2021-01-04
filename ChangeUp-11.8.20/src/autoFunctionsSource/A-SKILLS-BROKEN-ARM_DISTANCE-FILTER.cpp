#include "main.h"
using namespace okapi;

void a_SKILLS_BROKEN_ARM_DISTANCE_FILTER(){
// ----------Prepare the Program----------//
startTime=pros::millis();   //Set up the timer
drive->setState({19_in,15_in,-90_deg});   //Set the state for odometry

//----------Goal 1 (Home Row Left Corner)----------//
  //-----Preparation-----//
  DriveCoordShort(18.5,16,-126,0.55);   //Turn to face goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setLift(127);   //Start running lift
  pros::delay(500);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 2 (Left Wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(49.7, 45, 6, 3);   //Move to line up with next ball while spinning to face it
  setIntake(-127);    //Deploy intake
  pros::delay(900);   //Wait for it to deploy

  setIntake(127);   //Run intake forward to pick up a ball
  setLift(127);   //Start running lift
  DriveCoordShort(50,70,5,1);   //Drive forward to pick up ball
  DriveCoordShort(50,70,-86,.75);   //Turn to face next ball
  DriveCoordShort(24,72,-88,0.5);   //Drive forward to pick up ball
  pros::delay(200);   //Wait for ball to pick up
  setIntake(0);    //Stop intake
  DriveCoordShort(22,71.8,-90,0.5);   //Drive into goal

  //-----Score in Goal-----//
  setDelivery(-40);   //Start running delivery slowly in reverse
  setLift(-40);   //Start running lift slowly in reverse
  pros::delay(400);   //Wait for ball to slowly move down
  FilterBall("blue",1);
  // setDelivery(127);   //Start running delivery
  // setLift(80);   //Start running lift
  // pros::delay(1000);   //Wait for ball to score
  //
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 3 (Back Left Corner)----------//
  //-----Transition to Goal-----//
  // pros::delay(100000);
  DriveCoordShort(38,71.8,-90,0.9);   //Back away from goal
  setIntake(127);
  setLift(60);
  setDelivery(-127);
  DriveCoordShort(42,95,6.7,1.4);   //Line up with ball
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(45,122,6.3,1.2);   //Pick up ball
  DriveCoordShort(31,119,-32.2,1.25);  //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(26,126,-37,0.75); //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);   //Stop intake
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Reset alignment----------//
  //-----Prepare-----//
  DriveCoordShort(29,92,6,1.25); //Back away from goal

  //-----Align-----//
  //While the left back and left front distance sensors are not equal within a margin of error and those values are not within a specific range...
  while((leftTrackFront.get()<leftTrackBack.get()-0.5 || leftTrackFront.get()>leftTrackBack.get()+0.5) || ((frontTrack.get() > 1500) || (frontTrack.get() < 900))){
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

  //---Put all motors on brake type hold to get accurate values---//
    left_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    left_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);

  setDrive(0,0,0,0);    //Stop the drive
  pros::delay(100000);
//----------Goal 4 (Back wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(48,101,90,2);   //Line up with ball
  setIntake(127);   //Start running intake forward
  setLift(127);   //Start running lift
  DriveCoordShort(69,98,90,0.85);   //Pick up ball
  DriveCoordShort(71,121,0,1.3);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(71,130,0,0.6);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);   //Stop running intake
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 5 (Back Right Corner)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(71.6,121,0,0.9); //Back away from goal
  DriveCoordShort(87,122,90,1.15); //Drive in front of ball
  setIntake(127);   //Start running intake forward
  setLift(127);   //Start running lift
  DriveCoordShort(110,121,87,1.9);    //Pick up ball
  DriveCoordShort(121,120,52,0.9);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(128.3,128.5,52.6,1);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);   //Stop running intake
  pros::delay(750);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Reset alignment----------//
  //-----Prepare-----//
  DriveCoordShort(109,125,95,0.9);   //Back from goal

  //-----Align-----//
  //While the left back and left front distance sensors are not equal within a margin of error and those values are not within a specific range...
  while((leftTrackFront.get()<leftTrackBack.get()-0.5 || leftTrackFront.get()>leftTrackBack.get()+0.5) || ((frontTrack.get() > 1200) || (frontTrack.get() < 500))){
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

  //---Put all motors on brake type hold to get accurate values---//
    left_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    left_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);

  setDrive(0,0,0,0);    //Stop the driv

//----------Goal 6 (Right wall)----------//
  //-----Transition to Goal-----//
  setIntake(127);   //Start running intake forward
  setLift(80);   //Start running lift
  DriveCoordShort(91,93.8,184.5,12);   //Line up with next ball
  DriveCoordShort(90,69.8,184.5,1);   //Drive forward to pick up ball
  DriveCoordShort(90.9,71,92.9,0.75);   //Turn to face next ball
  DriveCoordShort(109,70,94,1.1);   //Line up with goal
  pros::delay(200);   //Wait for ball to pick up
  setIntake(0);   //Stop running the intake
  DriveCoordShort(119,71,91,1);   //Drive into goal

  //-----Score in Goal-----//
  setDelivery(-40);   //Start running delivery slowly in reverse
  setLift(-60);   //Start running lift slowly in reverse
  pros::delay(300);   //Wait for ball to slowly move down

  setDelivery(127);   //Start running lift again
  setLift(127);   //Start running delivery
  pros::delay(1250);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 7 (Bottom Right Corner)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(104,70,94,1);   //Back up from goal
  DriveCoordShort(100,45,184,8);   //Line up with ball
  setIntake(127);   //Start running intake forward
  setLift(127);   //Start running lift
  DriveCoordShort(100,18,183,2);    //Drive forward to pick up ball
  DriveCoordShort(109.7,21,134,0.75);    //Line up with goal
  setIntake(0);   //Stop running intake
  pros::delay(200);   //Wait a bit
  DriveCoordShort(117,14,138,0.75);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift


//----------Reset Alignment----------//
  //-----Prepare-----//
  DriveCoordShort(107,51,185,2.5); //Back away from goal

  //-----Align-----//
  //While the left back and left front distance sensors are not equal within a margin of error and those values are not within a specific range...
  while((leftTrackFront.get()<leftTrackBack.get()-0.5 || leftTrackFront.get()>leftTrackBack.get()+0.5) || ((frontTrack.get() > 1400) || (frontTrack.get() < 500))){
    double pow=(leftTrackBack.get()-leftTrackFront.get());    //Create a local variable that calculates the difference in sensor values

    if(leftTrackBack.get()>leftTrackFront.get())    //if the back value is greater than the front value...
      pow+=10;    //...Add 10 to the local variable "pow"
    if(leftTrackBack.get()<leftTrackFront.get())    //if the back value is less than the front value...
      pow-=10;    //...Subtract 10 from the local variable "pow"

    setDrive(pow,pow,-pow,-pow);    //Set the drive using the local variable "pow"
    pros::delay(10);    //Delay to save power
  }

  //Reset state: X-Subtract the left front sensor distance from 142 inches minus distance from the center Y-Add 2 to the front sensor from 142 plus distance from the center THETA-180
  drive->setState({(142*1_in)-(leftTrackFront.get()*0.0393701_in)-8.5_in,2_in+(frontTrack.get()*0.0393701_in)+5_in,180_deg});

  //---Put all motors on brake type hold to get accurate values---//
    left_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    left_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    right_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);

  setDrive(0,0,0,0);    //Stop the drive

//----------Goal 8 (Center)----------//
  //-----Transition to Goal-----//
  setIntake(127);   //Start running intake
  setLift(127);   //Start running lift
  DriveCoordShort(116.5,37,90,1.5);   //Line up with ball
  DriveCoordShort(125.5,37,90,1);    //Pick up ball
  DriveCoordShort(94,72,274,2.3);    //Drive in front of goal

  //-----Descore from Goal-----//
  setIntake(-127);   //Run intake in reverse
  setLift(0);   //Stop running lift

  DriveCoordShort(84.5,73,274,1);    //Drive in front of goal
  DriveCoordShort(93,73,274,0.75);   //Back away
  //
  // DriveCoordShort(84.5,73,274,1);    //Drive in front of goal
  // DriveCoordShort(93,73,274,1);   //Back away

  DriveCoordShort(84.5,73,274,0.75);    //Drive in front of goal
  DriveCoordShort(95.8,71.1,277,1);   //Back away

  //-----Transition to Score-----//
  DriveCoordShort(90,60,313,2);   //Line up with goal
  DriveCoordShort(82.6,67.7,314,1);   //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(1100);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery

//----------Goal 9 (Front Wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(95,55,309,3);   //Back away from goal
  DriveCoordShort(93,52,269,0.95);    //Turn to face ball
  setIntake(127);   //Start running intake to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(70,52,266,1.25);    //Pick up ball
  DriveCoordShort(70,31,180,1.3);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(70,23,180,0.5);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

  DriveCoordShort(142,20,-587,2);   //Back away from goal
}
