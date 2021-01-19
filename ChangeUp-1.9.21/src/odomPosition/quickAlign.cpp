#include "main.h"
using namespace okapi;

/*--------------------------------------------------------
  ____               _  _
 |  _ \  ___   __ _ | |(_)  __ _  _ __
 | |_) |/ _ \ / _` || || | / _` || '_ \
 |  _ <|  __/| (_| || || || (_| || | | |
 |_| \_\\___| \__,_||_||_| \__, ||_| |_|
                           |___/

  Blah Blah Blah Blah Explanations, esessesfsdfafsadfdsf

--------------------------------------------------------*/

// -------------------- thetaVal -------------------- //
// Recorded new Theta(angle) value.                   //
double thetaVal;

// -------------------- XYVal -------------------- //
// Recorded new distance from wall.                //
// Can be used for either X or Y.                  //
double XYVal;

// -------------------- baseA -------------------- //
// Base of triangle used for Theta.                //
// Set as the distance between distance sensors.   //
double baseA;

// ---------------------------- heightA ---------------------------- //
// Height of triangle used for Theta.                                //
// Set as the difference between front and back distance sensors.    //
double heightA;

// ----------------------- sf ----------------------- //
// Distance between front distance sensor and wall.   //
double sf=0;

// --------------------- sb --------------------- //
// Distance between back distance snsor and wall. //
double sb=0;

// -------------------- RADIANS TO DEGREES -------------------- //
// Converts radians to degrees.                                 //
double radToDeg(double radians){
  return radians*180.0/3.14159265;
}

// -------------------- DEGREES TO RADIANS -------------------- //
// Converts degrees to radians.                                 //
double degToRad(double degrees){
  return degrees*3.14159265/180.0;
}

// -------------------- THETA CALCULATION -------------------- //
// Calculates Theta from given base and height.                //
//             Diagram                                         //
//                                                             //
//              base(known)                                    //
//           ____________ Theta(unknown)                       //
//          |           /                                      //
//          |          /                                       //
//          |        /                                         //
//   height |      /                                           //
//  (known) |    /                                             //
//          |  /                                               //
//          |/                                                 //
//                                                             //
// tan(Theta) = height/base                                    //
// Theta = inverse tan(height/base)  Isolate Theta from tangent//
double getThetaVal(double bVal, double hVal){
  return (atan(hVal/bVal));
}

// -------------------- X/Y CALCULATION -------------------- //
// Calculates X/Y from given hypotenuse and angle.           //
//             Diagram                                       //
//           _____________                                   //
//          |            /                                   //
//          |          /                                     //
//          |        /                                       //
//   height |      / Hypotenuse (known)                      //
// (unknown)|    /                                           //
//          |  /                                             //
//          |/                                               //
//      Theta(known)                                         //
// cos(Theta) = height/hypotenuse                            //
// cos(Theta)*hypotenuse = height      Isolate height        //
double getXYVal(double cVal, double BVal){
  return cVal*cos(BVal);
}

void quickAlign(std::string XorY){
  // ----- GET VALUES ----- //
  sf = leftTrackFront.get()*0.0393701+5.125; // Get distance front value
  sb = leftTrackBack.get()*0.0393701+5.375; // Get distance back value

  // -------------------- THETA VALUE -------------------- //
  // ----- TRIANGLE FROM TRAPEZOID ----- //
  baseA = 12.25; // Distance between sensors
  heightA = sf-sb; // Height of the triangle / Difference between larger and smaller distance values

  // ----- SOLVE TRIANGLE ANGLE / GET THETA ----- //
  thetaVal = getThetaVal(baseA,heightA);

  // -------------------- X/Y VALUE -------------------- //
  // ----- TRIANGE FOR X/Y VALUE ----- //
  double hypoXY = (sf+sb)/2;
  double angXY = fabs(thetaVal); // Angle of Triangle / 90 minus

  // ----- SOLVE BASE LENGTH / GET X/Y ----- //
  // XYVal = getXYVal(hypoXY, angXY)-1;
  XYVal=getXYVal(hypoXY,angXY);

  if(XorY=="X")
    drive->setState({fabs(XYVal)*1_in+0.95_in,drive->getState().y,radToDeg(thetaVal)*1_deg});
  else if(XorY=="Y")
    drive->setState({drive->getState().x,fabs(XYVal)*1_in+0.95_in,thetaVal*1_deg});
}


void quickAlignNorthEast(std::string XorY){
  // ----- GET VALUES ----- //
  sf = leftTrackFront.get()*0.0393701+5.125; // Get distance front value
  sb = leftTrackBack.get()*0.0393701+5.375; // Get distance back value

  // -------------------- THETA VALUE -------------------- //
  // ----- TRIANGLE FROM TRAPEZOID ----- //
  baseA = 12.25; // Distance between sensors
  heightA = sf-sb; // Height of the triangle / Difference between larger and smaller distance values

  // ----- SOLVE TRIANGLE ANGLE / GET THETA ----- //
  thetaVal = getThetaVal(baseA,heightA);

  // -------------------- X/Y VALUE -------------------- //
  // ----- TRIANGE FOR X/Y VALUE ----- //
  double hypoXY = (sf+sb)/2;
  double angXY = fabs(thetaVal); // Angle of Triangle / 90 minus

  // ----- SOLVE BASE LENGTH / GET X/Y ----- //
  // XYVal = getXYVal(hypoXY, angXY)-1;
  XYVal=getXYVal(hypoXY,angXY);

  if(XorY=="X")
    drive->setState({143_in-fabs(XYVal)*1_in+0.95_in,drive->getState().y,180_deg+radToDeg(thetaVal)*1_deg});
  else if(XorY=="Y")
    drive->setState({drive->getState().x,143_in-fabs(XYVal)*1_in+0.95_in,90_deg+radToDeg(thetaVal)*1_deg});
}
