#include "main.h"
using namespace okapi;
/*
          Left 2 goal Cycle
        Cycle Home row middle
        Cycle Home row left corner
 */
void a_HMC_HLC(){

// strafeWithAngle(50, 40, 1, 45, 20);}

//----------Preparation----------//
  //Capture the start time so we can score at the last moment
  startTime=pros::millis();

  drive->setMaxVelocity(200);   //Set a certain velocity to improve precision and accuracy
  drive->setState({55.5_in,13_in,180_deg});   //Set the state for odometry

//----------Goal 1 (Home Row Wall)----------//
  //-----Move to Goal-----//
  DriveCoordShort(55.5,25,180,1);
  // drive->moveDistance(-12_in);    //Back up to align for strafing
  setIntake(-127);    //Run intakes backwards to deploy
  DriveCoordShort(69.5,25,180,1);
  // strafeDrive(-14,-1,5);    //Strafe left to align with goal
  setIntake(40);   //Stop running intake

  //-----Score in Goal-----//
  setDrive(60,60,60,60);    //Drive forward to get into goal
  pros::delay(500);   //Wait for it to get in there
  while (left_bc_mtr.get_actual_velocity() != 0) { //check if the back motor has stopped
    pros::delay(1);
  }
  drive->moveDistance(-3_in);
  // pros::delay(250);
  cycleScore(2,6);    //Cycle in goal for 2 balls

//----------Goal 2 (Home Row Left Corner)----------//
  //-----Move to Goal-----//
  setIntake(-127);    //Start running intakes backwards to not descore the ball
  drive->setMaxVelocity(200);   //Set max velocity for more accuracy and precision
  drive->moveDistance(-20_in);    //Back away from goal
  drive->driveToPoint({36_in,36_in});   //Drive to line up with corner goal

  setDelivery(-127);    //Filter ball out
  setLift(127);   //Filter ball out

  drive->setMaxVelocity(220);   //Change speed for better performance
  drive->turnToPoint({0_in,0_in});    //Turn to face corner goal
  pros::delay(700);   //Wait for it to get in there

  setIntake(60);   //Start running intake to pick up ball
   setLift(0);   //Stop running the lift

  DriveCoordShort(18,16.5,drive->getState().theta.convert(degree),1.75);

  // //-----Score in Goal-----//
  // setDrive(65,65,65,65);    //Drive into the goal
  // pros::delay(500);   //Wait for it to get in there
  // setLift(0);   //Stop running the lift
  // setIntake(60);   //Start running intake to pick up ball
  //
  // while (left_bc_mtr.get_actual_velocity() != 0) { //check if the back motor has stopped
  //   pros::delay(1);
  // }
  // setDrive(-10,-10,-10,-10);    //Back away from goal slowly
  // pros::delay(300);   //Wait a bit for it to back up enough
  // setDrive(0,0,0,0);    //Stop moving
  cycleScore(3,14.5);    //Cycle with 3 balls

  setIntake(-127);    //Run intake backwards to not decsore any balls
  drive->moveDistance(-20_in);    //Back away from goal
  setDrive(127,127,-127,-127);    //Spin in circles for fun
}
