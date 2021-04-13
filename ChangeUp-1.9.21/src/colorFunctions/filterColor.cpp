#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
  _____  _  _  _
 |  ___|(_)| || |_  ___  _ __
 | |_   | || || __|/ _ \| '__|
 |  _|  | || || |_|  __/| |
 |_|    |_||_| \__|\___||_|

Created on 11/10/2020 by Taylor and Logan
Last updated on 2/19/2021 by Logan

-----------------------------------------------------------------------------*/

// ------------------- FILTER BALL ------------------- //
// Cycles a goal and filter balls.                     //
// Filter a ball if it is the specified color.         //
// Exit the loop nothing is happening for 1 second.    //
// Exit the loop if all balls have been cycled/filterd.//
void FilterBall(std::string alliance, int deltaBallCount){
  setLift(65);
  setIntake(65);
  setDelivery(127); //Deliver ball

  std::string ballState="none";
  int targetBallCount=ballCount+deltaBallCount;
  int targetRotM=0;
  int noBallTimeout=pros::millis()+1000;
  int ballCheckTime = 0;
  while((ballCount<targetBallCount) & ((noBallTimeout>pros::millis()))){
    if((ballState=="detected")&(CheckColor("bottom")==alliance || CheckColor("middle")==alliance)){
      setIntake(0);
      setLift(-80);
      setDelivery(-127);    //...Run the delivery in reverse until ...
      pros::delay(100);   //... The limit switch is pressed an6d ...
      setLift(65);
      noBallTimeout=pros::millis()+1000;
      while(!ballFiltering() & ((noBallTimeout>pros::millis()))){pros::delay(10);} //Wait for filter switch to gather a ball
      while(ballFiltering() & ((noBallTimeout>pros::millis()))){pros::delay(10);}
      noBallTimeout=pros::millis()+1000;
      pros::delay(00);   //Wait for ball to filter out
      ballState="none"; //Set ball status to none
      setIntake(65);
      setDelivery(127); //Deliver ball
    }
    if(ballState=="detected")//Check to see if ball has been detected
      ballState="held";//...Mark the ball as held
    if(!ballIn())//If there are no balls in the robot
      ballState="none";//... update the robot to no balls
    if(ballIn()&(ballState=="none")){//If a ball comes in for the first time
      ballState="detected";//...Mark the ball as detected
      noBallTimeout=pros::millis()+1000;
      pros::delay(100);
    }
    pros::delay(10);//Wait for sensors to update
  }
}
