#include "main.h"
using namespace okapi;
double resetY=0;
void lineReset(){
  while((leftResetFollower.get_value()+leftResetFollower.get_value())/2>2300){pros::delay(20);}
  drive->setState({drive->getState().x,resetY*1_in});
}
