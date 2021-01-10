#include "main.h"
using namespace okapi;

void a_MMF_HL1(){
drive->setState({36_in,16.5_in,0_deg});
startTime=pros::millis();   //Set up the timer

//----------Goal 1 (Center)----------//
  //-----Transition to Goal-----//
  setIntake(-127);    //Deploy intake
  pros::delay(400);   //Wait for intake to deploy
  DriveCoordShort(36,48,0,3);   //Drive to line up with ball
pros::delay(400);
  setLift(127);   //Start running lift
  setIntake(127);   //Start running intake to pick up ball
  DriveCoordShort(36,63.5,0,2);   //Drive forward to pick up ball

  //-----Score in Goal-----//
  DriveCoordShort(59,61,0,1.25);    //Strafe to score ball
  setIntake(0);   //Stop running the intake
  DriveCoordShort(52,50,1,1);   //Back away from auton line
  DriveCoordShort(61,61,40,1.5);    //Prepare to score from top of center

  setDelivery(-50);   //Run delivery in reverse
  setLift(-50);   //Run lift in reverse
  pros::delay(200);   //Wait for balls to lower
  setDelivery(127);   //Start running delivery
  setLift(70);   //Start running delivery

  pros::delay(1600);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 2 (Corner Goal)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(53,56,45,1);    //Line up with goal
  setIntake(127);   //Start running intake
  DriveCoordShort(28,27,-136,2.5);    //Drive forward to pick up ball
  DriveCoordShort(17,17.5,-136,2);    //Drive into goal

  //-----Score in Goal-----//
  cycleScoreSlow(3, 14.5);    //Cycle 3 balls slowly and exit when the time is 14.5 seconds into autonomous

setIntake(-127);    //Run intake in reverse to leave balls in goal
DriveCoordShort(27,26,-136,15);    //Back away from goal
}
