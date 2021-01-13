#include "main.h"
using namespace okapi;

/*      H
        |\
        | \
        |  \ c
       b|   \
        |    \
        |_____\
        C  h  B
*/

double thetaVal;
double XYVal;
double baseA;
double heightA;

double radToDeg(double radians){
  return radians*180.0/3.14159265;
}

double getThetaVal(double bVal, double hVal){
  return radToDeg(atan(hVal/bVal));
}

double getXYVal(double cVal, double BVal){
  return cVal*sin(BVal);
}

void quickAlign(std::string XorY){
  // ----- GET VALUES ----- //
  double sf = leftTrackFront.get()*0.0393701+5.125; // Get distance front value
  double sb = leftTrackBack.get()*0.0393701+5.375; // Get distance back value

  // -------------------- THETA VALUE -------------------- //
  // ----- TRIANGLE FROM TRAPEZOID ----- //
  baseA = 12.25; // Distance between sensors
  heightA = sf-sb; // Height of the triangle / Difference between larger and smaller distance values

  // ----- SOLVE TRIANGLE ANGLE / GET THETA ----- //
  thetaVal = getThetaVal(baseA,heightA);

  // -------------------- X/Y VALUE -------------------- //
  // ----- TRIANGE FOR X/Y VALUE ----- //
  double hypoXY = fabs(heightA)/2+sf; // Hypotenuse of Triangle / Average of distance values
  if(sf>sb)
    hypoXY = fabs(heightA)/2+sb; // Hypotenuse of Triangle / Average of distance values
  double angXY = fabs(thetaVal); // Angle of Triangle / 90 minus

  // ----- SOLVE BASE LENGTH / GET X/Y ----- //
  // XYVal = getXYVal(hypoXY, angXY)-1;
  XYVal=getXYVal(hypoXY,angXY);
  if(XorY=="X")
    drive->setState({fabs(std::round(XYVal))*1_in,drive->getState().y,thetaVal*1_deg});
  else if(XorY=="Y")
    drive->setState({drive->getState().x,fabs(XYVal)*1_in,thetaVal*1_deg});
}

void quickAlign(){
  // ----- GET VALUES ----- //
  double sf = leftTrackFront.get()*0.0393701+5.125; // Get distance front value
  double sb = leftTrackBack.get()*0.0393701+5.375; // Get distance back value

  // -------------------- THETA VALUE -------------------- //
  // ----- TRIANGLE FROM TRAPEZOID ----- //
  baseA = 12.25; // Distance between sensors
  heightA = sf-sb; // Height of the triangle / Difference between larger and smaller distance values

  // ----- SOLVE TRIANGLE ANGLE / GET THETA ----- //
  thetaVal = getThetaVal(baseA,heightA);

  // -------------------- X/Y VALUE -------------------- //
  // ----- TRIANGE FOR X/Y VALUE ----- //
  double hypoXY = (sf+sb)/2; // Hypotenuse of Triangle / Average of distance values
  double angXY = thetaVal; // Angle of Triangle / 90 minus

  // ----- SOLVE BASE LENGTH / GET X/Y ----- //
  // XYVal = getXYVal(hypoXY, angXY)-1;
  XYVal=getXYVal(hypoXY,angXY);
}
