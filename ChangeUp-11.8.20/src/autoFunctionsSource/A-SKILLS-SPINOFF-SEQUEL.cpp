#include "main.h"
using namespace okapi;

void a_SKILLS_SPINOFF_SEQUEL(){
//----------Prepare the Program----------//
startTime=pros::millis();   //Set up the timer
drive->setState({18.5_in,16_in,-90_deg});   //Set the state for odometry

//----------Goal 1 (Home Row Left Corner)----------//
  //-----Preparation-----//
  DriveCoordShort(18.5,16,-122,1);
  // drive->turnToAngle(-122_deg);   //Turn to face goal

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setLift(127);   //Start running lift
  pros::delay(500);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 2 (Left Wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(24, 48, 2.6, 2);   //Move to line up with next ball while spinning to face it
  setIntake(-127);    //Deploy intake
  pros::delay(700);   //Wait for it to deploy
  setIntake(127);   //Run intake forward to pick up a ball
  setLift(127);   //Start running lift
  DriveCoordShort(24,70,0,1);
  setIntake(0);    //Stop intake
  DriveCoordShort(28,70,-90,1);
  DriveCoordShort(22,70,-90,0.5);

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
  DriveCoordShort(26,70,-90,1);
  DriveCoordShort(34,99,-364,3.5);  //Get In front of Ball
  setIntake(127);
  setLift(127);
  DriveCoordShort(34,122,-360,1.25); //Pick up ball
  DriveCoordShort(14.5,123.7,-400,2.5); //Score ball

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 4 (Back wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(49,97.5,-270,2.75); //Back from goal
  setIntake(127);
  setLift(127);
  DriveCoordShort(69,97,-270,1); //Pick up ball
  DriveCoordShort(69,122,-360,2); //Score ball

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 5 (Back Right Corner)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(69,116,-362,1); //Drive from goal
  DriveCoordShort(88,115,-296,1.5); //Drive in front of ball
  setIntake(127);
  setLift(127);
  DriveCoordShort(124,128,-319,2); //Score balls

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setIntake(0);
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 6 (Right wall)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(118.9,97,-541,2.5); //Back from goal
  setIntake(127);
  setLift(127);
  DriveCoordShort(118,73,-540,1); //Pick up ball
  DriveCoordShort(113,74,-629,1); //Drive in front of goal
  setIntake(0);
  DriveCoordShort(123,75,-629,1.5); //Score ball

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  pros::delay(550);   //Wait for ball to score
  setIntake(-127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(0);   //Stop running lift

//----------Goal 7 (Center)----------//
  //-----Transition to Goal-----//
  DriveCoordShort(120,74,-541,1.5); //Back up from goal
  DriveCoordShort(120,74,-450,1); //Pick up ball
  setIntake(127);
  setLift(127);

  DriveCoordShort(82,69,-455,1); //Drive into goal
  pros::delay(400);
  setIntake(0);
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
