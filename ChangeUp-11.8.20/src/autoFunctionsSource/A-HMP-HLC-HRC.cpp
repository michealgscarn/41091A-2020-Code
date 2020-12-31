#include "main.h"
using namespace okapi;

void a_HMP_HL1_HR1(){
startTime=pros::millis();

drive->setState({57_in,11.5_in,106_deg});   //Set the state for odometry

//----------Goal 1 (Home Row Middle)----------//
  setDelivery(127);   //Start running delivery
  setLift(127);   //Start running lift
  pros::delay(500);   //Wait for ball to score
  setDelivery(0);   //Start running delivery
  setLift(0);   //Start running lift

//----------Goal 2 (Home Row Left)----------//
  //-----Preparation-----//
  DriveCoord(30, 30, 224, 3);     //Strafe spin to line up with goal
  setIntake(-127);    //Deploy intake
  pros::delay(600);   //Wait for intakes to deploy
  setIntake(127);   //Start running intake to pick up ball
  setDelivery(127);   //Run delivery to score
  setLift(127);    //Raise lift

  //-----Score in Goal-----//
  DriveCoord(17, 17, 230, 4.5);    //Drive to pick up ball and get in goal
  setIntake(0);   //Stop running intake
   pros::delay(1000);    //Wait for ball to deliver
   setLift(0);    //Stop lift

//----------Goal 3 (Home Row Right)----------//
  //-----Preparation-----//
  setIntake(-127);   //Start running intake to pick up ball
  DriveCoord(90, 50, 128, 9);
  setIntake(127);   //Start running intake to pick up ball
  DriveCoord(125, 18, 128, 10.5);    //Move into goal

  //-----Score in Goal-----//
  cycleScoreSlow(3,14.5);   //Cycle last goal
  setIntake(-127);   //Stop intake
  drive->moveDistance(-10_in);    //Back away from goal

}
