#include "main.h"
using namespace okapi;

int ballCount;
int filterCount;

bool ballIn(){
  if(bottomIndex.get()<130 & bottomIndex.get()>20)
    return true;
  return false;
}
bool ballFiltering(){
  return !bottomLimit.get_value();
}

void ballCountTask(){
  bool ballStillIn=false;
  while(true){
    if(ballIn()&!ballStillIn&!ballFiltering()){
      ballCount++;
      ballStillIn=true;
      pros::delay(200);
    }
    else if(!ballIn())
      ballStillIn=false;
    pros::delay(10);
  }
}

void filterCountTask(){
  filterCount=-1;
    while(true){
      if(ballFiltering()){
        while(ballFiltering()){pros::delay(10);}
        filterCount++;
      }
    pros::delay(10);
    }
}
