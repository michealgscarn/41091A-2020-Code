

#include "main.h"
using namespace okapi;

void a_HRF(){
//----------Preparation----------//
  //Capture the start time so we can score at the last moment
  startTime=pros::millis();

  drive->setMaxVelocity(175);   //Slow the robot down for more accuracy and precision
  drive->setState({97.5_in,11.5_in,135_deg});   //Set the state for odometry

//----------Goal 1 (Corner Goal)----------//
  //-----Move to Goal-----//
  strafeDrive(-24,1,5);    //Strafe left to align with goal
  setIntake(-127);    //Deploy intake
  pros::delay(600);   //Wait for intake to deploy

  drive->setMaxVelocity(250);   //Set max velocity for better turns
  drive->turnToPoint({127.9_in,17.7_in});    //Turn to face corner goal
  setIntake(127);   //Start running intake to pick up ball

  //-----Score in Goal-----//
  setDrive(40,40,40,40);    //Drive into the goal
  pros::delay(500);   //Wait for it to get in there

  while (left_bc_mtr.get_actual_velocity() != 0) { //check if the back motor has stopped
    pros::delay(1);
  }

  setDrive(-10,-10,-10,-10);    //Back away from goal slowly
  pros::delay(300);   //Wait a bit for it to back up enough
  setDrive(0,0,0,0);    //Stop moving

  cycleScore(3, 14);    //Cycle and score balls

// int cycleBall=3;
// int timeToCycle=10;
//
// int ballCount=0;
// bool limitpressed=false;
// setLift(80);
// setDelivery(127);
// setIntake(127);
// while((ballCount<cycleBall)&(pros::millis()-startTime<(timeToCycle*1000)){
//   if((bottomLimit.get_value()==1)&(!limitpressed)){
//     ballCount++;
//     limitpressed=true;
//   }
//   else if((bottomLimit.get_value()==0)){
//     limitpressed=false;
//   }
//   pros::delay(1);
// }
// setIntake(0);
// setLift(0);
// pros::delay(500);
// setDelivery(0);

  setIntake(-127);    //Run intake in reverse to leave balls in there
  drive->setMaxVelocity(175);   //Slow down for precise driving
  drive->moveDistance(-30_in);    //Back away from goal

}
