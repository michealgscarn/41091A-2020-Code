#include "main.h"
using namespace okapi;

void deploy(){
  pros::delay(100);
  setIntake(-127);
  setLift(-127);
  setDelivery(20);
  while(ballIn()){pros::delay(10);}
  setLift(80);
  pros::delay(600);
  setLift(0);
  setIntake(80);
}
