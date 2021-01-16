#include "main.h"
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


$$\      $$\           $$\ $$\        $$$$$$\  $$\ $$\
$$ | $\  $$ |          $$ |$$ |      $$  __$$\ $$ |\__|
$$ |$$$\ $$ | $$$$$$\  $$ |$$ |      $$ /  $$ |$$ |$$\  $$$$$$\  $$$$$$$\
$$ $$ $$\$$ | \____$$\ $$ |$$ |      $$$$$$$$ |$$ |$$ |$$  __$$\ $$  __$$\
$$$$  _$$$$ | $$$$$$$ |$$ |$$ |      $$  __$$ |$$ |$$ |$$ /  $$ |$$ |  $$ |
$$$  / \$$$ |$$  __$$ |$$ |$$ |      $$ |  $$ |$$ |$$ |$$ |  $$ |$$ |  $$ |
$$  /   \$$ |\$$$$$$$ |$$ |$$ |      $$ |  $$ |$$ |$$ |\$$$$$$$ |$$ |  $$ |
\__/     \__| \_______|\__|\__|      \__|  \__|\__|\__| \____$$ |\__|  \__|
                                                       $$\   $$ |
                                                       \$$$$$$  |
                                                        \______/

  Created on 1/5/2020 by Logan and Taylor
  Last Updated on 1/15/2021 by Logan

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

bool filtered;

// $$$$$$$$$$$$$$$$$$$ FILTER WHILE ALIGNING $$$$$$$$$$$$$$$$$$$ //
// Filters balls in the robot while the robot is aligning.       //
// Won't allow the wall align to exit if the ball is not cycled. //

void filterWhileAlign(){
  // Filter Ball
  setIntake(127);
  setLift(60);
  setDelivery(-127);
  // Filter until ball filtering sensor says otherwise
  while(!ballFiltering()){pros::delay(10);}
  while(ballFiltering()){pros::delay(10);}
  filtered=true;
}

double millToIn(double mill){
  return mill*0.0393701;
}

// $$$$$$$$$$$$$$$$$ WALL ALIGN $$$$$$$$$$$$$$$$$ //
// Aligns with wall and resets odometry position. //
// Turns until side distance sensors are the same.//
// Reset robot position.                          //

void wallAlign(double facingAngle){ // Get the robot's angle, X and Y offsets
  double xVal = 0;
  double yVal = 0;
  double xSen = millToIn(leftTrackFront.get())+8.5;
  double ySen = millToIn(frontTrack.get())+5;
  double xOff = 0;
  double yOff = 0;
  double pow = 0;

  if(drive->getState().theta.convert(degree)<-87 || drive->getState().theta.convert(degree)>-93){
    xSen = millToIn(frontTrack.get())+8.5;
    ySen = millToIn(leftTrackFront.get())+5;
    yOff = 1;
    xOff = 1;
    xVal = xSen-xOff;
    yVal = ySen-xOff;
  }

  if(drive->getState().theta.convert(degree)>-3 || drive->getState().theta.convert(degree)<3){
    xSen = leftTrackFront.get()*0.0393701+8.5;
    ySen = frontTrack.get()*0.0393701+5;
    yOff = 143;
    xOff = 1;
    xVal = xSen-xOff;
    yVal = xOff-ySen;
  }

  if(drive->getState().theta.convert(degree)>87 || drive->getState().theta.convert(degree)<93){
     xSen = frontTrack.get()*0.0393701+5;
     ySen = leftTrackFront.get()*0.0393701+8.5;
     yOff = 143;
     xOff = 143;
     xVal = xOff-xSen;
     yVal = xOff-ySen;
  }

    if(fabs(drive->getState().theta.convert(degree))>177 || fabs(drive->getState().theta.convert(degree))<183){
       xSen = leftTrackFront.get()*0.0393701+8.5;
       ySen = frontTrack.get()*0.0393701+5;
       yOff = 143;
       xOff = 143;
       xVal = xOff-xSen;
       yVal = xOff-ySen;
    }

if(drive->getState().x.convert(inch)>72)
  drive->setState({(142-xSen)*1_in,drive->getState().x});
else
  drive->setState({(xSen-1)*1_in,drive->getState().x});

  if(drive->getState().y.convert(inch)>72)
    drive->setState({(142-xSen)*1_in,drive->getState().y});
  else
    drive->setState({(xSen-1)*1_in,drive->getState().y});

  while(leftTrackFront.get()<leftTrackBack.get()-0.5 || leftTrackFront.get()>leftTrackBack.get()+0.5){
    pow=(leftTrackBack.get()-leftTrackFront.get());

    if(leftTrackBack.get()>leftTrackFront.get())
      pow+=20;
    if(leftTrackBack.get()<leftTrackFront.get())
      pow-=20;
    setDrive(pow,pow,-pow,-pow);
    pros::delay(10);
  }
  drive->setState({xVal*1_in,yVal*1_in,facingAngle*1_deg});
}
