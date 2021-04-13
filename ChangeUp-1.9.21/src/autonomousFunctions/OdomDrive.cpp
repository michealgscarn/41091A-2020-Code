#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
     _           _              ____         _
    / \   _   _ | |_  ___      |  _ \  _ __ (_)__   __ ___
   / _ \ | | | || __|/ _ \     | | | || '__|| |\ \ / // _ \
  / ___ \| |_| || |_| (_) |    | |_| || |   | | \ V /|  __/
 /_/   \_\\__,_| \__|\___/     |____/ |_|   |_|  \_/  \___|

Created on 8/14/2020 by Taylor and Logn
Last updated on 1/22/2021 by Logan

-----------------------------------------------------------------------------*/

// --------------- MAX SPEED --------------- //
// Set the maximum speed given to the motors //
// Higher the speed, quicker the bot moves.  //
// 200 - Normal Speed / Preset.              //
// 600 - Highest Speed before inconsistent.  //
double maxSpeed = 200;

//Convert Degrees to Radians
double degToRad2(double degrees){
  return (degrees*3.1415926579/180);
}

// ----------------------- DRIVE MAX SPEED ----------------------- //
// Scale the robot's speed down if its above max.                  //
// Converts the given X, Y, and Theta values into Drive commands.  //
// Check to see if the motors exceed the maximum speed.            //
// Scale the Drive speed down if it does.                          //
// Set the Drivetrain.                                             //
void DriveMax(double xSpeed, double ySpeed, double turnSpeed){
  // Set the raw speed of drive motors.
  double leftFrontSpeed =   xSpeed  + ySpeed + turnSpeed;
  double leftBackSpeed  =   -xSpeed + ySpeed + turnSpeed;
  double rightFrontSpeed=   -xSpeed + ySpeed - turnSpeed;
  double rightBackSpeed =   xSpeed  + ySpeed - turnSpeed;

  // Find the Maximum value between the drive speeds.
  double max = std::max({fabs(leftFrontSpeed),fabs(leftBackSpeed),fabs(rightFrontSpeed),fabs(rightBackSpeed)});

  if(max>maxSpeed){ // If the maximum speed of the Drivetrain exceeds Max Speeds.
    // Scale the Drive speed down.
    leftFrontSpeed  = maxSpeed * leftFrontSpeed / max;
    leftBackSpeed   = maxSpeed * leftBackSpeed / max;
    rightFrontSpeed = maxSpeed * rightFrontSpeed / max;
    rightBackSpeed  = maxSpeed * rightBackSpeed / max;
  }
  setDrive(leftFrontSpeed,leftBackSpeed,rightFrontSpeed,rightBackSpeed); // Run the Motors.
}

// -------------------- FIELD CENTRIC DRIVE -------------------- //
// Converts Robot Oriented movements to Field Oriented movements.//
// Uses the given X, Y, and Turn Power for the Drivetrain.       //
void DriveFieldCentric(double xSpeed, double ySpeed, double turnSpeed){
  //Update the angle, y and x axis to drive field centric
  double theta = -degToRad2(drive->getState().theta.convert(degree));
  double newYSpeed  = ySpeed * cosf(theta) - xSpeed * sinf(theta);
  double newXSpeed  = ySpeed * sinf(theta) + xSpeed * cosf(theta);
  //Make sure the drive speeds are not above max
  DriveMax(newXSpeed, newYSpeed, turnSpeed);
}

// -------------------- DRIVE TO COORDINATE -------------------- //
// Drives the Robot to a coordinate.                             //
// Timout applies to the start of the program.                   //
// 1. Initialize a timeout if the Drivetrain can't settle.       //
// 2. Set up PID attributes for X, Y, and Theta Endpoints.       //
// 3. Enter a closed loop.                                       //
// 4. Apply the PID values to field centric driving.             //
// 5. Exit loop once robot has reached a 2 in / 3 in range.      //
// 6. Stop the Drivetrain.                                       //
void DriveCoord(double xCoord, double yCoord, double angle, double timeToDrive){
  //Capture Starting time
  double lastTime=pros::millis();

  //Define PID attributes across the X axis
  double xP = 6;
  double xI = 0.001;
  double xD = 0;
  double xError = xCoord;
  double xErrorSum = 0;
  double xErrorLast = xError;
  double xSpeed;

  //Define PID attributes across the Y axis
  double yP = 7.5;
  double yI = 0.001;
  double yD = 0;
  double yError = yCoord;
  double yErrorSum = 0;
  double yErrorLast = yError;
  double ySpeed;

  //Define PID attributes for Turning
  double aP = 2;
  double aI = 0;
  double aD = 0;
  double aError = angle;
  double aErrorSum = 0;
  double aErrorLast = aError;
  double aSpeed;

  //Check if the position for x, y and angle have been met
  while(((drive->getState().y.convert(inch) < yCoord-0.75 || drive->getState().y.convert(inch)  >yCoord + 0.75) ||
         (drive->getState().x.convert(inch) < xCoord -0.75|| drive->getState().x.convert(inch) > xCoord + 0.75) ||
         (drive->getState().theta.convert(degree)<angle -1|| drive->getState().theta.convert(degree)>angle + 2)) &
         (pros::millis()-startTime<(timeToDrive-0.5)*1000)){

  //Update the Last Error to adapt to change
  xErrorLast=xError;
  yErrorLast=yError;
  aErrorLast=aError;

  //Set the distance from the target as ERROR
  xError=xCoord-drive->getState().x.convert(inch);
  yError=yCoord-drive->getState().y.convert(inch);
  aError=angle-drive->getState().theta.convert(degree);

  //Add to the cumilative Errors over time
  xErrorSum+=xError/**(pros::millis()-lastTime)*/;
  yErrorSum+=yError/**(pros::millis()-lastTime)*/;
  aErrorSum+=aError/**(pros::millis()-lastTime)*/;

  //Set the speeds based on these attributes
  xSpeed=(xP*xError)+(xI*xErrorSum)+(xD*(xError-xErrorLast));
  ySpeed=(yP*yError)+(yI*yErrorSum)+(yD*(yError-yErrorLast));
  aSpeed=(aP*aError)+(aI*aErrorSum)+(aD*(aError-aErrorLast));

  //Set the speed in driving field centric
  DriveFieldCentric(xSpeed,ySpeed,aSpeed);
  //Wait for motors to update
  pros::delay(10);
  }
  DriveFieldCentric(0,0,0);
}

// -------------------- DRIVE TO COORDINATE SHORT -------------------- //
//Drive the robot in the direction of a point.                         //
void DriveCoordShort(double xCoord, double yCoord, double angle, double timeToDrive){
  //Capture Starting time
  double lastTime=pros::millis();

  //Define PID attributes across the X axis
  double xP = 6.75;
  double xI = 0.001;
  double xD = 0;
  double xError = xCoord;
  double xErrorSum = 0;
  double xErrorLast = xError;
  double xSpeed;

  //Define PID attributes across the Y axis
  double yP = 8.25;
  double yI = 0.001;
  double yD = 0;
  double yError = yCoord;
  double yErrorSum = 0;
  double yErrorLast = yError;
  double ySpeed;

  //Define PID attributes for Turning
  double aP = 2.5;
  double aI = 0;
  double aD = 0;
  double aError = angle;
  double aErrorSum = 0;
  double aErrorLast = aError;
  double aSpeed;

  //Check if the position for x, y and angle have been met
  while(((drive->getState().y.convert(inch) < yCoord-0.75 || drive->getState().y.convert(inch)  >yCoord + 0.75) ||
  (drive->getState().x.convert(inch) < xCoord -0.75|| drive->getState().x.convert(inch) > xCoord + 0.75)
  || (drive->getState().theta.convert(degree)<angle -1|| drive->getState().theta.convert(degree)>angle + 2))
  & (pros::millis()-lastTime<(timeToDrive)*1000)){


  //Update the Last Error to adapt to change
  xErrorLast=xError;
  yErrorLast=yError;
  aErrorLast=aError;

  //Set the distance from the target as ERROR
  xError=xCoord-drive->getState().x.convert(inch);
  yError=yCoord-drive->getState().y.convert(inch);
  aError=angle-drive->getState().theta.convert(degree);

  //Add to the cumilative Errors over time
  xErrorSum+=xError/**(pros::millis()-lastTime)*/;
  yErrorSum+=yError/**(pros::millis()-lastTime)*/;
  aErrorSum+=aError/**(pros::millis()-lastTime)*/;

  //Set the speeds based on these attributes
  xSpeed=(xP*xError)+(xI*xErrorSum)+(xD*(xError-xErrorLast));
  ySpeed=(yP*yError)+(yI*yErrorSum)+(yD*(yError-yErrorLast));
  aSpeed=(aP*aError)+(aI*aErrorSum)+(aD*(aError-aErrorLast));

  //Set the speed in driving field centric
  DriveFieldCentric(xSpeed,ySpeed,aSpeed);
  //Wait for motors to update
  pros::delay(10);
  }
  DriveFieldCentric(0,0,0);
}


// -------------------- DRIVE TO COORDINATE SHORT -------------------- //
// Drive the robot in the direction of a point.                        //
// Set P at such a high value, PID is nonexistant.                     //
// Drives to a point at the highest velocity possible.                 //
void DriveCoordShortNoPID(double xCoord, double yCoord, double angle, double timeToDrive){
  //Capture Starting time
  double lastTime=pros::millis();

  //Define PID attributes across the X axis
  double xP = 12;
  double xI = 0.001;
  double xD = 0;
  double xError = xCoord;
  double xErrorSum = 0;
  double xErrorLast = xError;
  double xSpeed;

  //Define PID attributes across the Y axis
  double yP = 16;
  double yI = 0.001;
  double yD = 0;
  double yError = yCoord;
  double yErrorSum = 0;
  double yErrorLast = yError;
  double ySpeed;

  //Define PID attributes for Turning
  double aP = 6;
  double aI = 0;
  double aD = 0;
  double aError = angle;
  double aErrorSum = 0;
  double aErrorLast = aError;
  double aSpeed;

  //Check if the position for x, y and angle have been met
  while(((drive->getState().y.convert(inch) < yCoord-1.5 || drive->getState().y.convert(inch)  >yCoord + 1.5) ||
  (drive->getState().x.convert(inch) < xCoord -1.5|| drive->getState().x.convert(inch) > xCoord + 1.5)
  || (drive->getState().theta.convert(degree)<angle -3|| drive->getState().theta.convert(degree)>angle + 3))
  & (pros::millis()-lastTime<(timeToDrive)*1000)){


  //Update the Last Error to adapt to change
  xErrorLast=xError;
  yErrorLast=yError;
  aErrorLast=aError;

  //Set the distance from the target as ERROR
  xError=xCoord-drive->getState().x.convert(inch);
  yError=yCoord-drive->getState().y.convert(inch);
  aError=angle-drive->getState().theta.convert(degree);

  //Add to the cumilative Errors over time
  xErrorSum+=xError/**(pros::millis()-lastTime)*/;
  yErrorSum+=yError/**(pros::millis()-lastTime)*/;
  aErrorSum+=aError/**(pros::millis()-lastTime)*/;

  //Set the speeds based on these attributes
  xSpeed=(xP*xError)+(xI*xErrorSum)+(xD*(xError-xErrorLast));
  ySpeed=(yP*yError)+(yI*yErrorSum)+(yD*(yError-yErrorLast));
  aSpeed=(aP*aError)+(aI*aErrorSum)+(aD*(aError-aErrorLast));

  //Set the speed in driving field centric
  DriveFieldCentric(xSpeed,ySpeed,aSpeed);
  //Wait for motors to update
  pros::delay(10);
  }
  DriveFieldCentric(0,0,0);
}
