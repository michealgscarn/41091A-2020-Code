#include "main.h"
using namespace okapi;

void a_SKILLS_BROKEN_ARM(){
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
  DriveCoordShort(49.7, 47.4, 6, 3);   //Move to line up with next ball while spinning to face it
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
  DriveCoordShort(38,98,-363,3);    //Back away from goal 2
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(36.8,120,-363,3);   //Line up with next ball
  DriveCoordShort(23,118.6,-408,2);  //Drive forward to pick up ball
  setIntake(0);   //Stop running intake
  DriveCoordShort(18,125,-408,1.25); //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);   //Stop intake
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 4 (Back wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(18,125,-408,1.25); //Drive into goal
  DriveCoordShort(55,98.5,-640,3); //Back away from goal
  setIntake(127);   //Start running intake forward
  setLift(127);   //Start running lift
  DriveCoordShort(76,102,-641,1);   //Line up with ball
  DriveCoordShort(73.5,122,-734,1.5); //Drive forward to pick up ball
  setIntake(0);   //Stop running intake
  DriveCoordShort(72,129,-734,0.75);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);   //Stop running intake
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 5 (Back Right Corner)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(72,116,-734,1); //Back away from goal
  DriveCoordShort(90,117,-662,2); //Drive in front of ball
  setIntake(127);   //Start running intake forward
  setLift(127);   //Start running lift
  DriveCoordShort(120.9,132.7,-681,2);    //Pick up ball
  setIntake(0);   //Stop running intake
  DriveCoordShort(124.3,144.6,-689,2);    //Drive into goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);   //Stop running intake
  pros::delay(500);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 6 (Right wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(112,124,-678.8,2.5);   //Back from goal
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
