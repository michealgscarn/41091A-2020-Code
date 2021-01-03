#include "main.h"
using namespace okapi;

  void DriveMax(double xSpeed, double ySpeed, double turnSpeed);
  void DriveFieldCentric(double xSpeed, double ySpeed, double turnSpeed);
  void DriveCoord(double xCoord, double yCoord, double angle, double timeToDrive);
  void DriveCoordShort(double xCoord, double yCoord, double angle, double timeToDrive);
  void DriveCoordShortNoPID(double xCoord, double yCoord, double angle, double timeToDrive);
