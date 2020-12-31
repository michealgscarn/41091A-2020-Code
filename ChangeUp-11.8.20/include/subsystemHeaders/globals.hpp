#include "main.h"
 using namespace okapi;
//MOTORS
extern pros::Motor left_fr_mtr;
extern pros::Motor left_bc_mtr;
extern pros::Motor right_fr_mtr;
extern pros::Motor right_bc_mtr;
extern pros::Motor left_int_mtr;
extern pros::Motor right_int_mtr;
extern pros::Motor lift_mtr;
extern pros::Motor del_mtr;

//CONTROLLER
extern pros::Controller controller;

extern pros::Imu Gyron;

//-----Encoders-----//
extern ADIEncoder l; // left encoder in ADI ports A & B
extern ADIEncoder r;  // right encoder in ADI ports C & D (reversed)
extern ADIEncoder m;

//-----Color Sensors-----//
extern pros::Optical bottomColor;    //Bottom color Sensor
extern pros::Optical middleColor;    //Middle color Sensor
extern pros::Optical topColor;   //Top color sensor

extern pros::Distance bottomIndex;

extern pros::ADIDigitalIn bottomLimit;

extern void waitForADIInit(int time);

extern std::shared_ptr<OdomChassisController> drive;
extern std::shared_ptr<AsyncMotionProfileController> profileController;
extern std::shared_ptr<okapi::XDriveModel> driveTrain;

extern int encCallibrate;
extern int autonomousPreSet;
