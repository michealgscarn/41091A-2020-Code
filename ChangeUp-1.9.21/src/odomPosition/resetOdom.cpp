#include "main.h"
using namespace okapi;
/*--------------------------------------------------------------------------
  _      _                ____                   _
 | |    (_) _ __    ___  |  _ \  ___  ___   ___ | |_
 | |    | || '_ \  / _ \ | |_) |/ _ \/ __| / _ \| __|
 | |___ | || | | ||  __/ |  _ <|  __/\__ \|  __/| |_
 |_____||_||_| |_| \___| |_| \_\\___||___/ \___| \__|

  Created on 1/5/2020 by Logan and Taylor
  Last Updated on 1/15/2021 by Logan

Reset the robot's position after crossing a line.


--------------------------------------------------------------------------*/

double resetY=0; // Set the Y position that will reset once the robot crosses the line.
void lineReset(){
  while((leftResetFollower.get_value()+leftResetFollower.get_value())/2>2300){pros::delay(10);}
  drive->setState({drive->getState().x,resetY*1_in,drive->getState().theta});
}
