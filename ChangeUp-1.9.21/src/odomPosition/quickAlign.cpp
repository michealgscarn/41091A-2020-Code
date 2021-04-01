#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
  ____               _  _
 |  _ \  ___   __ _ | |(_)  __ _  _ __
 | |_) |/ _ \ / _` || || | / _` || '_ \
 |  _ <|  __/| (_| || || || (_| || | | |
 |_| \_\\___| \__,_||_||_| \__, ||_| |_|
                           |___/
Created on 1/1/2021 by Logan and Taylor
Last Updated 1/28/2021 by Logan

Quickly reset the Robot's position using the left wall from the Robot
Uses the Front and Back Reset Distance Sensors to calculate the Robots real
• Theta
• X position

-----------------------------------------------------------------------------*/

// --------------- thetaVal --------------- //
// Recorded new Theta(angle) value.         //
double thetaVal;


// --------------- XYVal --------------- //
// Recorded new distance from wall.      //
// Can be used for either X or Y.        //
double XYVal;


// ------------------- baseA ------------------- //
// Base of triangle used for Theta.              //
// Set as the distance between distance sensors. //
double baseA=12.25;

// -------------------------- heightA -------------------------- //
// Height of triangle used for Theta.                            //
// Set as the difference between front and back distance sensors.//
double heightA;

// ---------------------- sf ---------------------- //
// Distance between front distance sensor and wall. //
double sf=0;


// --------------------- sb --------------------- //
// Distance between back distance snsor and wall. //
double sb=0;


// ---------------------- sf ---------------------- //
// Distance between front distance sensor and wall. //
double sfF=0;


// --------------------- sb --------------------- //
// Distance between back distance snsor and wall. //
double sbF=0;


// ---------------------- sf ---------------------- //
// Distance between front distance sensor and wall. //
double sfL=0;


// --------------------- sb --------------------- //
// Distance between back distance snsor and wall. //
double sbL=0;


// --------------- RADIANS TO DEGREES --------------- //
// Converts radians to degrees.                       //
double radToDeg(double radians){
  return radians*180.0/3.14159265;
}


// --------------- DEGREES TO RADIANS --------------- //
// Converts degrees to radians.                       //
double degToRad(double degrees){
  return degrees*3.14159265/180.0;
}


// --------------- THETA CALCULATION --------------- //
// Calculates Theta from given base and height.      //
//             Diagram                               //
//                                                   //
//              base(known)                          //
//           ____________ Theta(unknown)             //
//          |           /                            //
//          |          /                             //
//          |        /                               //
//   height |      /                                 //
//  (known) |    /                                   //
//          |  /                                     //
//          |/                                       //
//                                                   //
// tan(Theta) = height/base                          //
// Theta = inverse tan(height/base)  Isolate Theta   //
double getThetaVal(double bVal, double hVal){
  return (atan(hVal/bVal));
}


// --------------- X/Y CALCULATION --------------- //
// Calculates X/Y from given hypotenuse and angle. //
//             Diagram                             //
//           _____________                         //
//          |            /                         //
//          |          /                           //
//          |        /                             //
//   height |      / Hypotenuse (known)            //
// (unknown)|    /                                 //
//          |  /                                   //
//          |/                                     //
//      Theta(known)                               //
// cos(Theta) = height/hypotenuse                  //
// cos(Theta)*hypotenuse = height Isolate height   //
double getXYVal(double cVal, double BVal){
  return cVal*cos(BVal);
}


// --------------- RESET VALUES --------------- //
//  Create an array of the new position generated//
//  Gather data from distance sensors
std::array<double,3> resetVals(int wall) {

  // ----- GET VALUES ----- //
  sfL = leftTrackFront.get()*0.0393701+5.125; // Get distance front value
  sbL = leftTrackBack.get()*0.0393701+5.375; // Get distance back value
  sfF = frontTrackLeft.get()*0.0393701+7.25; // Get distance front value
  sbF = frontTrackRight.get()*0.0393701+7.25; // Get distance back value

  // ---------- THETA VALUE ---------- //
  // ----- TRIANGLE FROM TRAPEZOID ----- //
  double baseL=12.25;
  double baseF=8.9375;

  double heightL = sfL-sbL; // Height of the triangle / Difference between larger and smaller distance values
  double heightF = sfF-sbF; // Height of the triangle / Difference between larger and smaller distance values

  // ----- SOLVE TRIANGLE ANGLE / GET THETA ----- //
  thetaVal = (getThetaVal(baseL,heightL));

  // ---------- X/Y VALUE ---------- //
  // ----- TRIANGE FOR X/Y VALUE ----- //
  double hypoL = (sfL+sbL)/2;
  double hypoF = (sfF+sbF)/2;

  double angL = fabs(thetaVal); // Angle of Triangle / 90 minus
  double angF = fabs(thetaVal); // Angle of Triangle / 90 minus

  // ----- SOLVE BASE LENGTH / GET X/Y ----- //
  double newL=getXYVal(hypoL,angL);
  double newF=getXYVal(hypoF,angF);

  // ----- COMPRESS INFORMATION ----- //
  std::array<double,3> newPos = {newL,newF,thetaVal};  // Import new XY and Theta values into an array

  // ----- CONVERT TO WALL ----- //
  newPos[2]+=(wall-1)*1.5708; // Add 90 degrees to each following wall the robot is next to
  if(wall==2 || wall==3)  // If the wall is either North or East
    newPos[0] = 143-newPos[0]+0.95; // Reset XY accordinly
  else  // If the walls are 1 or 4
    newPos[0] = newPos[0]+0.95; // Reset XY accordinly

  if(wall==1 || wall==2)  // If the wall is either North or East
    newPos[1] = 143-newPos[1]+0.95; // Reset XY accordinly
  else  // If the walls are 1 or 4
    newPos[1] = newPos[1]+0.95; // Reset XY accordinly

  newL=newPos[0];
  newF=newPos[1];

  if(wall==1 || wall==3){  // If the wall is either North or East
    newPos[0] = newL; // Reset XY accordinly
    newPos[1] = newF; // Reset XY accordinly
  }
  else{  // If the walls are 2 or 4
    newPos[0] = newF; // Reset X accordinly
    newPos[1] = newL; // Reset Y accordinly
  }

  return newPos;
}

void quickAlign(double currXY, int wall) {
  std::array<double,3> tempNew = resetVals(wall); // Check to see if the new suffices
  // int resetTimeout = pros::millis() + 1000;
  // pros::Task TurnToAllign(turnToAllign);
  while(!(tempNew[0] > currXY-500) & (tempNew[0] < currXY+500)){  // Loop until there is a real reset value
    tempNew = resetVals(wall);  // Get new values for reset
    pros::delay(10);
  }
  drive->setState({ tempNew[0]*1_in , tempNew[1]*1_in , radToDeg(tempNew[2])*1_deg});
}
