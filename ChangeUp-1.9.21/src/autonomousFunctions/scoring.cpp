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

// ---------------- CYCLE SCORE ---------------- //
// Cycle a goal in autononous.                   //
// Best used in Tournament autonomous.           //
// Cycles a goal based on ball count.            //
// Does only filters final ball.                 //
void cycleScore(int cycleBall,double cycleTime){
  setLift(127);  // Lift Balls to Deliver
  setIntake(127);  // Pick up Balls from Goal
  setDelivery(127); // Shoot Balls into Goal
  int targetBallCount=ballCount+cycleBall;  // Set the amount of balls to cycle
  int targetTime=pros::millis()+cycleTime*1000; // Set the amount of time given to cycle the goal
  while((ballCount<targetBallCount) & (pros::millis()<targetTime-500)){pros::delay(10);}  //
  setIntake(0);
  while(!ballIn() & (pros::millis()<targetTime-500)){pros::delay(10);}
  setLift(0);
  pros::delay(250);
  setDelivery(0);
  setIntake(-127);
  if(filter)
    pros::Task filterBall(cycleScoreFilter);
}
