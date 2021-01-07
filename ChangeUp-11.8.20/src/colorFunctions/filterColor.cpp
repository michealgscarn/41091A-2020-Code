#include "main.h"
using namespace okapi;
/*
*
* Filter Color Function
*
* This function will filter balls based on a given alliance
*
* Created on 11/15/2020
* Created by Taylor and Logan Daugherty
*
* Last Updated 11/17/2020
* Last Updated by Logan Daugherty
*
*/

void FilterBall(std::string alliance, int deltaBallCount){
  setLift(65);
  setIntake(70);
  setDelivery(127); //Deliver ball

  std::string ballState="none";
  int targetBallCount=ballCount+deltaBallCount;
  int targetRotM=0;
  int noBallTimeout=pros::millis()+3000;
  while((ballCount<targetBallCount) & ((noBallTimeout>pros::millis()))){
    if((ballState=="detected")&(CheckColor("bottom")==alliance || CheckColor("middle")==alliance)&bottomFollower.get_value()>2800){
      setIntake(0);
      setDelivery(-127);    //...Run the delivery in reverse until ...
      pros::delay(10);   //... The limit switch is pressed and ...
      noBallTimeout=pros::millis()+1000;
      while(!ballFiltering() & ((noBallTimeout>pros::millis()))){pros::delay(10);} //Wait for filter switch to gather a ball
      while(ballFiltering() & ((noBallTimeout>pros::millis()))){pros::delay(10);}
      noBallTimeout=pros::millis()+3000;
      pros::delay(00);   //Wait for ball to filter out
      ballState="none"; //Set ball status to none
      setIntake(127);
      setDelivery(127); //Deliver ball
    }
    // if(ballState=="detected")//Check to see if ball has been detected
    //   ballState="held";//...Mark the ball as held
    if(bottomFollower.get_value()>2800){//If there are no balls in the robot
      ballState="none";//... update the robot to no balls
    }
    if(ballIn()&(ballState=="none")){//If a ball comes in for the first time
      ballState="detected";//...Mark the ball as detected
      noBallTimeout=pros::millis()+3000;
      pros::delay(100);
    }
    pros::delay(10);//Wait for sensors to update
  }
}

void FilterBallCorner(std::string alliance, int deltaBallCount){
  // pros::delay(1000);//
  setLift(65);
  setIntake(75);
  setDelivery(127); //Deliver ball

  std::string ballState="none";
  int targetBallCount=ballCount+deltaBallCount;
  int targetRotM=0;
  while(ballCount<targetBallCount){
    if((ballState=="detected")&CheckColor("bottom")==alliance&bottomFollower.get_value()>2800){
      setDelivery(-127);    //...Run the delivery in reverse until ...
      setIntake(0);
      pros::delay(10);   //... The limit switch is pressed and ...
      while(!ballFiltering()){pros::delay(10);} //Wait for filter switch to gather a ball
      while(ballFiltering()){pros::delay(10);}
      pros::delay(00);   //Wait for ball to filter out
      ballState="none"; //Set ball status to none
      setDelivery(127); //Deliver ball
      setIntake(75);
    }
    // if(ballState=="detected")//Check to see if ball has been detected
    //   ballState="held";//...Mark the ball as held
    if(bottomFollower.get_value()>2800)//If there are no balls in the robot
      ballState="none";//... update the robot to no balls
    if(ballIn()&(ballState=="none")){//If a ball comes in for the first time
      ballState="detected";//...Mark the ball as detected
      pros::delay(100);
    }
    pros::delay(10);//Wait for sensors to update
  }
}



void FilterBall(std::string alliance, int deltaBallCount, int deltaFilterCount){
  pros::delay(1000);//
  setLift(65);
  setIntake(127);
  std::string ballState="none";
  int targetBallCount=ballCount+deltaBallCount;
  int targetFilterCount=filterCount+deltaFilterCount;
  int targetRotM=0;
  while(ballCount<targetBallCount & filterCount<targetFilterCount){
      if(ballState=="detected"){
        targetRotM=lift_mtr.get_position()+113;
        while(lift_mtr.get_position()<targetRotM){pros::delay(10);}
      }
      if((ballState=="detected")&CheckColor("bottom")==alliance){
        setDelivery(-127);    //...Run the delivery in reverse until ...
        pros::delay(10);   //... The limit switch is pressed and ...
        while(ballFiltering()){pros::delay(10);} //Wait for filter switch to gather a ball
        while(!ballFiltering()){pros::delay(10);}
        pros::delay(300);   //Wait for ball to filter out
        ballState="none"; //Set ball status to none
      }
      else //If the correct color ball
        setDelivery(127); //Deliver ball
      if(ballState=="detected")//Check to see if ball has been detected
        ballState="held";//...Mark the ball as held
      if(!ballIn())//If there are no balls in the robot
        ballState="none";//... update the robot to no balls
      if(ballIn()&(ballState=="none"))//If a ball comes in for the first time
        ballState="detected";//...Mark the ball as detected
      pros::delay(10);//Wait for sensors to update
  }
}
