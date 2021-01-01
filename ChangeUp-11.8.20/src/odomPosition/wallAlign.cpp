#include "main.h"

void wallAlign(double facingAngle,double minusY,double minusX){
double xSen = leftTrackFront.get()*0.0393701+8.5;
double ySen = frontTrack.get()*0.0393701+5;
if(drive->getState().theta.convert(degree)==90){
  xSen=frontTrack.get()*0.0393701+5;
  ySen=leftTrackFront.get()*0.0393701+8.5;
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
    double pow=(leftTrackBack.get()-leftTrackFront.get())*0.2;
    if(leftTrackBack.get()>leftTrackFront.get())
      pow+=20;
    if(leftTrackBack.get()<leftTrackFront.get())
      pow-=20;
    setDrive(pow,pow,-pow,-pow);
    pros::delay(10);
  }
  drive->setState({minusX*1_in+leftTrackFront.get()*0.0393701_in+8.5_in,minusY*1_in+frontTrack.get()*0.0393701_in+5_in,facingAngle*1_deg});

}
