#include "main.h"
using namespace okapi;

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


 $$$$$$\  $$\           $$\                 $$\        $$$$$$\            $$\
$$  __$$\ $$ |          $$ |                $$ |      $$  __$$\           $$ |
$$ /  \__|$$ | $$$$$$\  $$$$$$$\   $$$$$$\  $$ |      $$ /  \__| $$$$$$\  $$ | $$$$$$\   $$$$$$\
$$ |$$$$\ $$ |$$  __$$\ $$  __$$\  \____$$\ $$ |      $$ |      $$  __$$\ $$ |$$  __$$\ $$  __$$\
$$ |\_$$ |$$ |$$ /  $$ |$$ |  $$ | $$$$$$$ |$$ |      $$ |      $$ /  $$ |$$ |$$ /  $$ |$$ |  \__|
$$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |$$  __$$ |$$ |      $$ |  $$\ $$ |  $$ |$$ |$$ |  $$ |$$ |
\$$$$$$  |$$ |\$$$$$$  |$$$$$$$  |\$$$$$$$ |$$ |      \$$$$$$  |\$$$$$$  |$$ |\$$$$$$  |$$ |
 \______/ \__| \______/ \_______/  \_______|\__|       \______/  \______/ \__| \______/ \__|

Created on 11/11/2020 by Taylor and Logan
Last updated on 1/7/2021 by Logan

BALL COUNT
----------
Total number of balls that have gone through the robot.

FILTER COUNT
------------
Total number of balls that have been filtered

BALL IN
-------
Checks if a ball is in the robot
Returns if the line follower is dark enough that a ball is in

BALL FILTERING
--------------
Check if a ball is being filtered.
If the filter band is pulled down, a ball is being filtered.

COUNT BALL
----------
Count the number of balls in the number of balls in the robot.
Adds one to the ball count if a ball is in.

COUNT FILTER
------------
Count the number of balls filtered in the robot.
Adds one to the filter count if a ball is filtered.

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

// $$$$$$$$$$$$$$$$$$$$$$ BALL COUNT $$$$$$$$$$$$$$$$$$$$$$ //
// Total number of balls that have gone through the robot.  //
int ballCount;


// $$$$$$$$$$$$$$$$$ FILTER COUNT $$$$$$$$$$$$$$$$$ //
// Total number of balls that have been filtered.   //
int filterCount;


// $$$$$$$$$$$$$$$$$$$$$$$$$$ BALL IN $$$$$$$$$$$$$$$$$$$$$$$$$$ //
// Checks if a ball is in the robot                              //
// Returns if the line follower is dark enough that a ball is in.//

bool ballIn(){
  return (bottomFollower.get_value()<2600 & bottomFollower.get_value()>0);
}


// $$$$$$$$$$$$$$$$$$$$$$$$$$ BALL IN $$$$$$$$$$$$$$$$$$$$$$$$$$ //
// Check if a ball is being filtered.
// If the filter band is pulled down, a ball is being filtered.
bool ballFiltering(){
  return !bottomLimit.get_value();
}


// $$$$$$$$$$$$$$$$$$$$$$$$$ COUNT BALL $$$$$$$$$$$$$$$$$$$$$$$$$ //
// Count the number of balls in the number of balls in the robot. //
// Adds one to the ball count if a ball is in.                    //

void ballCountTask(){
  bool ballStillIn=false; // Set the ball still 
  while(true){
    if(ballIn()&!ballStillIn&!ballFiltering()){
      ballCount++;
      ballStillIn=true;
      pros::delay(100);
    }
    else if(!ballIn())
      ballStillIn=false;
    pros::delay(10); // Wait for motors to update
  }
}


// $$$$$$$$$$$$$$$$$$ COUNT FILTER $$$$$$$$$$$$$$$$$$ //
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
