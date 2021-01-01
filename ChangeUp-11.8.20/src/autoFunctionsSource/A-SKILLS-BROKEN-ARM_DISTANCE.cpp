#include "main.h"
using namespace okapi;

void a_SKILLS_BROKEN_ARM_DISTANCE(){
//----------Prepare the Program----------//
startTime=pros::millis();   //Set up the timer
drive->setState({19_in,15_in,-90_deg});   //Set the state for odometry

//----------Goal 1 (Home Row Left Corner)----------//
  //-----Preparation-----//
  DriveCoordShort(18.5,16,-126,0.75);   //Turn to face goal

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
  pros::delay(1500);   //Wait for it to deploy
  setIntake(127);   //Run intake forward to pick up a ball
  setLift(127);   //Start running lift
  DriveCoordShort(50,70,5,1);   //Drive forward to pick up ball
  DriveCoordShort(50,70,-86,1);   //Turn to face next ball
  DriveCoordShort(24,72,-88,0.5);   //Drive forward to pick up ball
  pros::delay(200);   //Wait for ball to pick up
  setIntake(0);    //Stop intake
  DriveCoordShort(22,71.8,-90,0.5);   //Drive into goal

  //-----Score in Goal-----//
  setDelivery(-40);   //Start running delivery slowly in reverse
  setLift(-40);   //Start running lift slowly in reverse
  pros::delay(400);   //Wait for ball to slowly move down

  setDelivery(127);   //Start running delivery
  setLift(80);   //Start running lift
  pros::delay(1000);   //Wait for ball to score

  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 3 (Back Left Corner)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(38,71.8,-90,2);   //Back away from goal
  DriveCoordShort(42,95,6.7,3.5);   //Line up with ball
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(45,120,6.3,3);   //Pick up ball
  DriveCoordShort(31,119,-32.2,2);  //Drive forward to pick up ball
  setIntake(0);   //Stop running intake
  DriveCoordShort(26,126,-37,1.25); //Drive into goal

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
  pros::delay(500);   //Wait a bit

  //-----Align-----//
  //While the left back and left front distance sensors are not equal...
  while((leftTrackFront.get()<leftTrackBack.get()-0.5 || leftTrackFront.get()>leftTrackBack.get()+0.5) & !(frontTrack.get() < 200)){
    double pow=(leftTrackBack.get()-leftTrackFront.get());    //Create a local variable that calculates the difference in sensor values

    if(leftTrackBack.get()>leftTrackFront.get())    //if the back value is greater than the front value...
      pow+=20;    //Add 20 to the local variable "pow"
    if(leftTrackBack.get()<leftTrackFront.get())    //if the back value is less than the front value...
      pow-=20;    //Subtract 20 from the local variable "pow"

    setDrive(pow,pow,-pow,-pow);    //Set the drive to the local variable "pow"
    pros::delay(10);    //Delay to save power
  }

  //Reset state
  drive->setState({-1_in+leftTrackFront.get()*0.0393701_in+8.5_in,142*1_in-frontTrack.get()*0.0393701_in+5_in,0*1_deg});

  //---Put all motors on brake type hold to get accurate values---//
  left_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  left_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  right_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  right_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);

  setDrive(0,0,0,0);    //Stop the drive
  pros::delay(1000);    //Wait a bit

//----------Goal 4 (Back wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(48,101,90,3); //Back away from goal
  setIntake(127);   //Start running intake forward
  setLift(127);   //Start running lift
  DriveCoordShort(69,100,90,1);   //Line up with ball
  DriveCoordShort(70,120,0,1.5); //Drive forward to pick up ball
  setIntake(0);   //Stop running intake
  DriveCoordShort(70,127,0,0.75);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);   //Stop running intake
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 5 (Back Right Corner)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(71,116,0,1); //Back away from goal
  DriveCoordShort(87,114,67,2); //Drive in front of ball
  setIntake(127);   //Start running intake forward
  setLift(127);   //Start running lift
  DriveCoordShort(121,121,45,2);    //Pick up ball
  setIntake(0);   //Stop running intake
  DriveCoordShort(127,128,46,2);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);   //Stop running intake
  pros::delay(750);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Reset alignment----------//
  //-----Prepare-----//
  DriveCoordShort(109,125,95,2.5);   //Back from goal

  //-----Align-----//
  //While the left back and left front distance sensors are not equal...
  while(leftTrackFront.get()<leftTrackBack.get()-0.5 || leftTrackFront.get()>leftTrackBack.get()+0.5){
    double pow=(leftTrackBack.get()-leftTrackFront.get());//Create a local variable that calculates the difference in sensor values

    if(leftTrackBack.get()>leftTrackFront.get())    //if the back value is greater than the front value...
      pow+=20;    //Add 20 to the local variable "pow"
    if(leftTrackBack.get()<leftTrackFront.get())    //if the back value is less than the front value...
      pow-=20;//Subtract 20 from the local variable "pow"

    setDrive(pow,pow,-pow,-pow);    //Set the drive to the local variable "pow"
    pros::delay(10);   //Delay to save power
  }

  //---Put all motors on brake type hold to get accurate values---//
  left_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  left_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  right_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
  right_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);

  setDrive(0,0,0,0);    //Stop the drive

  //Reset state
  drive->setState({142*1_in-frontTrack.get()*0.0393701_in+5_in,142*1_in-leftTrackFront.get()*0.0393701_in+8.5_in,90*1_deg});

//----------Goal 6 (Right wall)----------//
  //-----Transition to Goal-----//
  setIntake(127);   //Start running intake forward
  setLift(127);   //Start running lift
  DriveCoordShort(122,106,-545,5);   //Line up with next ball
  DriveCoordShort(122.7,82,-543,2);   //Drive forward to pick up ball
  setIntake(0);   //Stop running intake
  DriveCoordShort(117.8,84.9,-543,2);   //Strafe some to line up with goal better
  DriveCoordShort(118,84,-634,2.5);   //Line up with goal
  DriveCoordShort(126,84.5,-635,1.5);   //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 7 (Center)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(120,74,-541,1.5);   //Back up from goal
  DriveCoordShort(120,74,-450,1);   //Pick up ball
  setIntake(127);   //Start running intake forward
  setLift(127);   //Start running lift

  DriveCoordShort(82,69,-455,1); //Drive into goal
  pros::delay(400);   //Wait for ball to pick up
  setIntake(-127);   //Run intake in reverse to push out balls easier
  DriveCoordShort(92,70,-453,1); //Back away from goal

  DriveCoordShort(82,69,-455,1); //Drive into goal
  DriveCoordShort(92,70,-453,1); //Back away from goal

  DriveCoordShort(82,69,-455,1); //Drive into goal
  DriveCoordShort(92,70,-453,1); //Back away from goal

  DriveCoordShort(82,69,-455,1); //Drive into goal
  DriveCoordShort(92,70,-453,1); //Back away from goal

  DriveCoordShort(82.6,62.8,-408,1.5); //Score ball

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 8 (Front wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(100,59,-480,1.5); //Back from goal
  setIntake(127);   //Start running intake
  setLift(127);   //Start running lift
  DriveCoordShort(75,47,-475,1.5); //Pick up ball
  pros::delay(550);   //Wait for ball to score
  setIntake(0);
  DriveCoordShort(73,22,-540,2.5); //Drive in front of goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 9 (Front Right Corner)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(72,28,-543,1.5);    //Back away from goal
  DriveCoordShort(90,36,-605,1.5);    //Turn to face ball
  setIntake(127);   //Start running intake to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(126.5,19,-586,2.5);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

DriveCoordShort(132,24,-587,2);   //Back away from goal
}
