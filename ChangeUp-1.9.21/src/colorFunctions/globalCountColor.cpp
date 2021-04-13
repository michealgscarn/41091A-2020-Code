#include "main.h"
using namespace okapi;

/*-----------------------------------------------------------------------------
   ____  _         _             _        ____                      _
  / ___|| |  ___  | |__    __ _ | |      / ___| ___   _   _  _ __  | |_
 | |  _ | | / _ \ | '_ \  / _` || |     | |    / _ \ | | | || '_ \ | __|
 | |_| || || (_) || |_) || (_| || |     | |___| (_) || |_| || | | || |_
  \____||_| \___/ |_.__/  \__,_||_|      \____|\___/  \__,_||_| |_| \__|

Created on 11/9/2020 by Taylor and Logan
Last updated on 2/19/2021 by Logan

-----------------------------------------------------------------------------*/

// ---------------------- BALL COUNT ---------------------- //
// Total number of balls that have gone through the robot.  //
int ballCount=0;


// ----------------- FILTER COUNT ----------------- //
// Total number of balls that have been filtered.   //
int filterCount;


// -------------------------- BALL IN -------------------------- //
// Checks if a ball is in the robot                              //
// Returns if the line follower is dark enough that a ball is in.//
bool ballIn(){
  // return (ballDetectBottom.get()<30 & ballDetectBottom.get()>0);
  return !primaryLimit.get_value();
}


// -------------------------- BALL OUT -------------------------- //
// Checks if a ball is in the robot                              //
// Returns if the line follower is dark enough that a ball is in.//
bool ballOut(){
  return (topLimit.get_value());
}


// -------------------------- BALL IN -------------------------- //
// Check if a ball is being filtered.
// If the filter band is pulled down, a ball is being filtered.
bool ballFiltering(){
  return !bottomLimit.get_value();
}


// ------------------------- COUNT BALL ------------------------- //
// Count the number of balls in the number of balls in the robot. //
// Adds one to the ball count if a ball is in.                    //
void ballCountTask(){
  ballCount=0;
  while(true){
    if(ballIn()){
      while(ballIn()){pros::delay(10);}
      ballCount++;
      pros::delay(100);
    }
    pros::delay(1); // Wait for motors to update
  }
}

// ------------------------- ENTER SUBMISSION JEFF ------------------------- //
// Count the number of balls in the number of balls in the robot. //
// Adds one to the ball count if a ball is in.                    //
void ballExitCountTask(){
  ballCount=0;
  while(true){
    if(ballOut()){
      while(ballOut()){pros::delay(10);}
      ballCount--;
      pros::delay(100);
    }
    pros::delay(1); // Wait for motors to update
  }
}


// ------------------ COUNT FILTER ------------------ //
// Count the number of balls filtered in the robot.   //
// Adds one to the filter count if a ball is filtered.//
void filterCountTask(){
  filterCount=-1;
    while(true){
      if(ballFiltering()){
        while(ballFiltering()){pros::delay(10);}
        filterCount++;
      }
    pros::delay(10); // Wait for motors to update
    }
}
