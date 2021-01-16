#include "main.h"
using namespace okapi;

/*
 * A_HMP_HLC_MM1
 *
 * This program will score in 3 goals
 *    - Home Row Wall
 *    - Home Row Left Corner
 *    - Center
 *
 * Set this program up with a C-Channel on the middle ring of the homerow wall goal
 * The robot should be angled
 *
 */

void A_HMC_HLC_MM1(){
//----------Set Up----------//
  startTime=pros::millis();
  drive->setState({83.75_in,13.75_in,110_deg});   //Set the state for odometry

//   //----------Goal 1 (Home Row Wall)----------//
//     setDelivery(127);   //Start running delivery
//     setLift(127);   //Start running lift
//     pros::delay(500);   //Wait for ball to score
//     setLift(0);   //Start running lift
//
// //----------Goal 1 (Home Row Left Corner)----------//
//   //-----Transition to Goal-----//
//   DriveCoord(29,29,233,3);   //Strafe to line up with goal
//   setIntake(-127);    //Deploy intake
//   pros::delay(400);   //Wait for intake to deploy
//   setIntake(127);    //Start running the intake
//   DriveCoord(18,18,236,4.75);   //Move forward into the goal
//
//   //-----Score in Goal-----//
//   cycleScore(3, 12.5);     //Cycle 2 balls
//   setIntake(-127);    //Start running intake in reverse to keep ball in goal
//
// //----------Goal 3 (Center Goal)----------//
//   //-----Transition to Goal-----//
//   DriveCoord(53,46,370,12.25);    //Back away from the goal
//   DriveCoord(58,57,367,14);     //Line up with ball
//
//   //-----Score in Goal-----//
//   DriveCoord(70,57,370,14.75);    //Strafe ball into the goal
//
//   DriveCoord(30,30,370,15);    //Strafe away from ball

}
