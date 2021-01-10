#include "main.h"
using namespace okapi;
/*
          Right 2 goal Cycle
        Cycle Home row middle
        Cycle Home row right corner

*/
void a_HMC_HRC(){
//----------Preparation----------//
  //Capture the start time so we can score at the last moment
  startTime=pros::millis();   //Run a time task
  drive->setMaxVelocity(200);   //Set a certain velocity to improve precision and accuracy
  drive->setState({86.25_in,13_in,180_deg});    //Set the state of the robot for odometry

//----------Goal 1----------//
  //-----Move to Goal-----//
  drive->moveDistance(-12_in);    //Back up to get ready to strafe
  setIntake(-127);    //Reverse intakes to deploy
  // strafeDrive(16,1,5);    //Strafe right to line up with goal
  setIntake(40);    //Slowly run intake forward
  setDrive(60,60,60,60);    //Move into goal
  pros::delay(500);   //Wait a bit

  //-----Score in Goal-----//
  while (left_bc_mtr.get_actual_velocity() != 0) { //check if the back motor has stopped
    pros::delay(1);
  }
  drive->moveDistance(-3_in);

  cycleScore(2,6);    //Cycle the goal
  setIntake(-127);    //Set intake in reverse to leave the balls behind
  drive->setMaxVelocity(200);
  drive->moveDistance(-20_in);    //Back away from goal

//----------Goal 2----------//
  //-----Transition to Goal-----//
  drive->driveToPoint({108_in,36_in});    //Drive to line up with the next goal
  setDelivery(-127);    //Filter
  setLift(127);   //Filter
  drive->setMaxVelocity(220);   //Change speed for better performance
  drive->turnToPoint({126_in,13_in});    //Turn to face the goal

  setDrive(65,65,65,65);    //Drive into the goal
  pros::delay(500);   //Wait a bit
  setLift(0);   //Stop the lift
  setIntake(127);   //Run the intake forward

  //-----Score in Goal-----//
  while (left_bc_mtr.get_actual_velocity() != 0) { //check if the back motor has stopped
    pros::delay(1);
  }

  setDrive(-10,-10,-10,-10);    //Back up
  pros::delay(300);   //Wait a bit
  setDrive(0,0,0,0);    //Stop moving
  cycleScore(3,14);   //Cycle the goal
  setIntake(-127);    //Run the intake in reverse
  drive->moveDistance(-20_in);    //Back away from goal

  setDrive(127,127,-127,-127);    //Spin around
}


/* ****** Testing Turning using Odom *********
drive->setState({62_in,72_in,0_deg});   //12 inches inward, 41.5 inches down, 45 degrees toward (0,0)
drive -> moveDistance(10_in);
drive -> turnToPoint({0_in,0_in});
pros::delay(500);
drive -> turnToPoint({0_in,144_in});
pros::delay(500);
drive -> turnToPoint({144_in,144_in});
pros::delay(500);
drive -> turnToPoint({144_in,0_in});
pros::delay(500);
drive -> turnToAngle(0_deg);
pros::delay(500);
*********** Testing Turning using Odom ************
*/
