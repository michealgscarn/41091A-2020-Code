#include "main.h"
using namespace okapi;


//initialize a value to use from the brain value for when an autonomous starts
// we use this to time actions in autonomous
int startTime;


//Use this function to drive up to the goal, and score quickly.
//Only use this when there is little time to score, which will not be often.
void driveAndScore(int timeBeforeScore,int timeToScore){
  setDrive(80,80,80,80);
  pros::delay(timeBeforeScore); //delay so we can get motor velocity number after motors start
  setIntake(-127);  //delivery done
  while (true) {
        if (left_bc_mtr.get_actual_velocity() == 0) { //check if the back motor has stopped
            setIntake(0);
            setDelivery(127);       //Start running delivery at 100% speed
            setLift(100);
            setDrive(0,0,0,0);
            pros::delay(timeToScore); //wait for delivery
            setIntake(0);  //delivery done
            setLift(0);
            setDelivery(0);       //Start running lift at 100% speed
            break;
            }
            pros::delay(1);
    }
}

//Use this function to score only.  This will not drive to the goal, only score
//use this only when you need to quickly score and are already at the goal
void scoreFormation(int cycleBall){
  int ballCount=0; //set the limit switch counter to 0 balls
  bool limitpressed; //initialize the boolean limitswitch value
  setLift(127); //spin the ball lift
  setDelivery(127); //spin the delivery
  setIntake(127); //spin the ball intake
  //run the delivery actions until the ball count is reached
  // this is great for when you want to cycle all but the opponent's balls
  while(ballCount<cycleBall){
    if((bottomLimit.get_value()==1)&(!limitpressed)){
      ballCount++;
      limitpressed=true;
    }
    else if((bottomLimit.get_value()==0)){
      limitpressed=false;
    }
    pros::delay(1);
  }
  //once the cycle is done, turn off all delivery items
  setIntake(0);
  setLift(0);
  pros::delay(500);
  setDelivery(0);
}



//Deliver the correct number of balls, and move on if a max time is reached.
// you will almost always use this function to score
void cycleScore(int cycleBall,double timeToCycle){
  int ballCount=0;  //set number of cycled balls to 0
  bool limitpressed=false; //initialize the limitswitch value to "not pressed"
  setLift(80); //spin the lift at 80 so it doesn't run faster than the delivery
  setDelivery(127); //spin the delivery
  setIntake(127); //spin the intake
  //deliver until either the ball count is reached or the time limit for that goal is reached
  while((ballCount<cycleBall)&(pros::millis()-startTime<(timeToCycle-0.5)*1000)){ //0.5 Sec less for delay later
    if((bottomLimit.get_value()==1)&(!limitpressed)){
      ballCount++;
      limitpressed=true;
    }
    else if((bottomLimit.get_value()==0)){
      limitpressed=false;
    }
    pros::delay(1);
  }
  //turn everything related to delivery off
  setIntake(0);
  setLift(0);
  pros::delay(500); //wait a moment to let any final balls score
  setDelivery(0);
}


void cycleScoreSlow(int cycleBall,double timeToCycle){
  int ballCount=0;  //set number of cycled balls to 0
  bool limitpressed=false; //initialize the limitswitch value to "not pressed"
  setLift(65); //spin the lift at 70 so it doesn't run faster than the delivery
  setDelivery(127); //spin the delivery
  setIntake(127); //spin the intake
  //deliver until either the ball count is reached or the time limit for that goal is reached
  while((ballCount<cycleBall)&(pros::millis()-startTime<(timeToCycle-0.5)*1000)){ //0.5 Sec less for delay later
    if((bottomLimit.get_value()==1)&(!limitpressed)){
      ballCount++;
      limitpressed=true;
    }
    else if((bottomLimit.get_value()==0)){
      limitpressed=false;
    }
    pros::delay(1);
  }
  //turn everything related to delivery off
  setIntake(0);
  setLift(0);
  pros::delay(500); //wait a moment to let any final balls score
  setDelivery(0);
}


void cycleScoreSlower(int cycleBall,double timeToCycle){
  int ballCount=0;  //set number of cycled balls to 0
  bool limitpressed=false; //initialize the limitswitch value to "not pressed"
  setLift(35); //spin the lift at 70 so it doesn't run faster than the delivery
  setDelivery(127); //spin the delivery
  setIntake(127); //spin the intake
  //deliver until either the ball count is reached or the time limit for that goal is reached
  while((ballCount<cycleBall)&(pros::millis()-startTime<(timeToCycle-0.5)*1000)){ //0.5 Sec less for delay later
    if((bottomLimit.get_value()==1)&(!limitpressed)){
      ballCount++;
      limitpressed=true;
    }
    else if((bottomLimit.get_value()==0)){
      limitpressed=false;
    }
    pros::delay(1);
  }
  //turn everything related to delivery off
  setIntake(0);
  setLift(0);
  pros::delay(750); //wait a moment to let any final balls score
  setDelivery(0);
}
/* below is in development as a method to speed up delivery.  Do not use for now.

//score # of balls quickly and in a certain timeframe
void cycleScoreShort(int cycleBall,double timeToCycle){
  int ballCount=0; //set counter to 0
  bool limitpressed; //initialize the limitswitch counter
  setLift(127); //spin lift
  setDelivery(127); //spin delivery
  setIntake(127); //spin intake
  //deliver # of balls in time
  while((ballCount<cycleBall)&(pros::millis()-startTime<timeToCycle*1000)){
    if((bottomLimit.get_value()==1)&(!limitpressed)){
      ballCount++;
      limitpressed=true;
    }
    else if((bottomLimit.get_value()==0)){
      limitpressed=false;
    }
    pros::delay(1);
  }
  //stop everything related to delivery
  setIntake(0);
  setLift(0);
  pros::delay(400);
  setDelivery(0);
}

*/
