#include "main.h"
using namespace okapi;

  //Convert Degrees to Radians
  double degToRad2(double degrees){
    return (degrees*3.1415926579/180);
  }

  //Scale Drive Based on Highest Speed
  void DriveMax(double xSpeed, double ySpeed, double turnSpeed){
    //Set the raw speed of drive motors
    double leftFrontSpeed =   xSpeed  + ySpeed + turnSpeed;
    double leftBackSpeed  =   -xSpeed + ySpeed + turnSpeed;
    double rightFrontSpeed=   -xSpeed + ySpeed - turnSpeed;
    double rightBackSpeed =   xSpeed  + ySpeed - turnSpeed;

    //Adjust speeds so that nothing is set over its max value
    double max = std::max({fabs(leftFrontSpeed),fabs(leftBackSpeed),fabs(rightFrontSpeed),fabs(rightBackSpeed)});
    if(max>100){
      leftFrontSpeed  = 100 * leftFrontSpeed / max;
      leftBackSpeed   = 100 * leftBackSpeed / max;
      rightFrontSpeed = 100 * rightFrontSpeed / max;
      rightBackSpeed  = 100 * rightBackSpeed / max;
    }
    setDrive(leftFrontSpeed,leftBackSpeed,rightFrontSpeed,rightBackSpeed);
  }

  //Set the speed of the robot in a direction
  void DriveFieldCentric(double xSpeed, double ySpeed, double turnSpeed){
    //Update the angle, y and x axis to drive field centric
    double theta = -degToRad2(drive->getState().theta.convert(degree));
    double newYSpeed  = ySpeed * cosf(theta) - xSpeed * sinf(theta);
    double newXSpeed  = ySpeed * sinf(theta) + xSpeed * cosf(theta);
    //Make sure the drive speeds are not above max
    DriveMax(newXSpeed, newYSpeed, turnSpeed);
  }

  //Drive the robot in the direction of a point
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
    (drive->getState().x.convert(inch) < xCoord -0.75|| drive->getState().x.convert(inch) > xCoord + 0.75)
    || (drive->getState().theta.convert(degree)<angle -1|| drive->getState().theta.convert(degree)>angle + 2))
    & (pros::millis()-startTime<(timeToDrive-0.5)*1000)){

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

  //Drive the robot in the direction of a point
  void DriveCoordShort(double xCoord, double yCoord, double angle, double timeToDrive){
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
  //Drive the robot in the direction of a point
  void DriveCoordShortSkills(double xCoord, double yCoord, double angle, double timeToDrive){
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
    (drive->getState().x.convert(inch) < xCoord -0.75|| drive->getState().x.convert(inch) > xCoord + 0.75)
    || (drive->getState().theta.convert(degree)<angle -1|| drive->getState().theta.convert(degree)>angle + 2))
    & (pros::millis()-startTime<(timeToDrive-0.5)*1000)){


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
