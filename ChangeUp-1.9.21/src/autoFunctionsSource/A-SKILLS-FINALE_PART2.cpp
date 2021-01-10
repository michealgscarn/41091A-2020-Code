#include "main.h"
using namespace okapi;

void a_SKILLS_FINALE_PART2(){
//----------Prepare the Program----------//
startTime=pros::millis();   //Set up the timer
drive->setState({21.5_in,16_in,-90_deg});   //Set the state for odometry

//----------Goal 1 (Home Row Left Corner)----------//
  //-----Preparation-----//
  drive->turnToAngle(-120_deg);   //Turn to face goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setLift(127);   //Start running lift
  pros::delay(500);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 2 (Left Wall)----------//
  //-----Transition to Goal-----//
  DriveCoord(47.5, 50.5, 0, 4.25);   //Move to line up with next ball while spinning to face it
  setIntake(-127);    //Deploy intake
  pros::delay(500);   //Wait for it to deploy
  setIntake(127);   //Run intake forward to pick up a ball
  setLift(127);   //Start running lift
  drive->driveToPoint({47_in,71_in});   //Drive to pick up ball
  drive->driveToPoint({21_in,drive->getState().y});   //Get in position to score

  //-----Score in Goal-----//
  setIntake(0);    //Stop intake
  setDelivery(-40);   //Start running delivery slowly in reverse
  setLift(-40);   //Start running lift slowly in reverse
  pros::delay(400);   //Wait for ball to slowly move down

  setDelivery(127);   //Start running delivery
  setLift(80);   //Start running lift
  pros::delay(1000);   //Wait for ball to score

  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 3 (Back left corner goal)----------//
  //-----Transition to Goal-----//
  drive->driveToPoint({34_in,drive->getState().y},true);    //Back away from the goal
  setIntake(127);   //Run intake to pick up ball
  DriveCoord(34,98,-2,13.9);    //Move to line up with next ball while spinning to face it
  DriveCoord(33,120,-2,15.75);   //Drive forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoord(20, 119, -47, 17);    //Move to line up with goal while spinning to face it
  setIntake(0);   //Stop running intakes
  DriveCoord(17.5, 125.5, -45, 18.25);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 4 (Back wall)----------//
  //-----Transition to Goal-----//
  DriveCoord(51.5, 96, 88, 21.95);   //Drive to pick up ball
  setIntake(127);   //Run intake to pick up a ball
  setLift(127);   //Start running lift
  DriveCoord(70.5, 96, 88, 23.1);   //Drive forward to pick up ball
  pros::delay(500);   //Wait for ball to be picked up
  setIntake(-127);    //Start running intake in reverse
  DriveCoord(73, 122, 0, 26.1);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(750);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 5 (Back right corner)----------//
  //-----Transition to Goal-----//
  DriveCoord(71, 110, 0, 28.25);    //Back away from goal while turning to face next ball
  setIntake(127);   //Start running intake
  DriveCoord(87, 110, 67, 29.5);    //Align with ball
  setLift(127);     //Start running lift
  DriveCoord(126, 124.5, 43, 32);    //Drive into gaol

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);    //Start running intake in reverse
  pros::delay(750);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 6 (Right wall)----------//
  //------Transition to Goal-----//
  DriveCoord(119, 115, 45, 34.75);    //Back away from goal
  DriveCoord(119, 92, -176, 37.25);   //Move to line up with ball
  setIntake(127);   //Start running intake to pick up a ball
  setLift(127);   //Start running lift
  DriveCoord(116, 66, -177, 38.5);   //Drive forward to pick up ball
  DriveCoord(114, 72, -177, 39.5);   //Strafe left to avoid knocking a ball out from the goal y = 68.25
  setIntake(0);   //Stop running the intake
  drive->turnToAngle(-267_deg);
  DriveCoord(124, 72, -266, 41.75);   //Move to line up with the goal

  //------Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(1000);   //Wait for ball to score
  setIntake(-127);    //Start running intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 7 (Center)----------//
  //-----Transition to Goal-----//
  DriveCoord(115, 71, drive->getState().theta.convert(degree), 44.25);    //Back away from goal to avoid hitting blue ball
  drive->turnToAngle(-456_deg);    //Turn to line up with ball
  setIntake(127);   //Run intake to pick up a ball
  setLift(127);   //Start running lift
  DriveCoord(94, 70, -456, 46.75);   //Move forward to pick up ball

    //-----Descore-----//
    setIntake(0);
    DriveCoord(82, 70, -456, 47.5);    //Drive into goal
    DriveCoord(93, 70, -454, 48.25);     //Back away to let ball fall
    DriveCoord(82, 70, -456, 49);    //Drive into goal
    DriveCoord(93, 70, -454, 49.75);       //Back away to let ball fall
    DriveCoord(82, 70, -456, 50.5);    //Drive into goal
    DriveCoord(93, 70, -454, 49.75);       //Back away to let ball fall
    DriveCoord(80, 60.5, -399, 51.75);     //Strafe to line up to score

  //------Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(750);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 8 (Bottom right corner)----------//
  //-----Transition to Goal-----//
  DriveCoord(81.5, 25, -263, 54.5);   //Back away from center
  setIntake(127);   //Start running intake to pick up ball
  setLift(127);   //Start running lift
  DriveCoord(112, 25, -263, 56.5);   //Line up with ball
  DriveCoord(128, 13, -214, 58.5);   //Pick up ball and line up with goal
  setIntake(0);   //Start running lift
  setLift(0);   //Stop running lift to prevent unwanted balls from coming out

  //------Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(1000);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery

// drive->moveDistance(-10_in);    //Back away from goal

  DriveCoord(113,33.5,-265,62);
  setLift(127);   //Start running lift
  setIntake(127);   //Start running intake to pick up ball

  DriveCoord(124, 34, -264, 64);

  DriveCoord(75,22,-149,67);
  setIntake(0);   //Start running lift
  setLift(0);   //Stop running lift to prevent unwanted balls from coming out

  //------Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(1000);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery
}
