#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
  ____                     _
 / ___|   ___  ___   _ __ (_) _ __    __ _
 \___ \  / __|/ _ \ | '__|| || '_ \  / _` |
  ___) || (__| (_) || |   | || | | || (_| |
 |____/  \___|\___/ |_|   |_||_| |_| \__, |
                                     |___/
Created on 8/14/2020 by Taylor and Logn
Last updated on 1/17/2021 by Logan

-----------------------------------------------------------------------------*/

bool isCycleScoreSetup=false; // Communication between Setup command and Autonomous

void cycleScoreSetup(){
  isCycleScoreSetup=false;  // Tell the Autonomous that the ball is not set up
  int setUpTime=2;  // Define how many seconds until the setup times out
  int targetTime=pros::millis()+setUpTime*1000; // Set the amount of time given to cycle the goal
  while(ballIn() & (pros::millis()<targetTime-500)){
    setLift(-80); // Spin the Lift in Reverse
    setDelivery(-80); // Spin the Delivery in Reverse
    pros::delay(1);
  } // Loop until a ball is in the bottom of the robot
  setLift(0); // Stop the Lift
  setDelivery(0); // Stop the Delivery
  isCycleScoreSetup=true; // Tell the Autonomous the ball is set up
}


bool filter=true;

void cycleScoreFilter(){
  setLift(-127);
  while(ballIn()){pros::delay(10);}
  setLift(127);
  setDelivery(-127);
  while(!ballFiltering()){pros::delay(10);}
  while(ballFiltering()){pros::delay(10);}
  setLift(0);
  setDelivery(0);
}

// ---------------- CYCLE SCORE NO INTAKE---------------- //
// Cycle a goal in autononous.                   //
// Best used in Tournament autonomous.           //
// Cycles a goal based on ball count.            //
// Does only filters final ball.                 //
void cycleScoreNoIntake(int cycleBall,double cycleTime, int startBallCount){
  if(startBallCount==1)
    setLift(127);  // Lift Balls to Deliver
  if(startBallCount==2)
    setLift(75);  // Lift Balls to Deliver
  setDelivery(127); // Shoot Balls into Goal
  int targetBallCount=ballCount+cycleBall;  // Set the amount of balls to cycle
  int targetTime=pros::millis()+cycleTime*1000; // Set the amount of time given to cycle the goal
  while((ballCount<targetBallCount) & (pros::millis()<targetTime-500)){
    setDelivery(127); // Shoot Balls into Goal
    pros::delay(10);
  }  //
  setIntake(0);
  while(!ballIn() & (pros::millis()<targetTime-500)){pros::delay(10);}
  setLift(0);
  pros::delay(200);
  setDelivery(0);
  if(filter){
    pros::Task filterBall(cycleScoreFilter);
  }
}


// ---------------- CYCLE SCORE ---------------- //
// Cycle a goal in autononous.                   //
// Best used in Tournament autonomous.           //
// Cycles a goal based on ball count.            //
// Does only filters final ball.                 //
void cycleScore(int cycleBall,double cycleTime, int startBallCount){
  setIntake(127);  // Pick up Balls from Goal
  cycleScoreNoIntake(cycleBall,cycleTime,startBallCount);
  setIntake(-127);
}
