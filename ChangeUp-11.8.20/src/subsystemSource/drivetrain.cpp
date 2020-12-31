#include "main.h"
using namespace okapi;

//HELPER FUNCTIONS
void setDrive(double leftFront, double leftBack, double rightFront, double rightBack){
  left_fr_mtr = leftFront;
  left_bc_mtr = leftBack;
  right_fr_mtr = rightFront;
  right_bc_mtr = rightBack;
}

//DRIVER CONTROL FUNCTIONS
void setDriveMotors( double driveSpeed ){
  //Set drive speed based on button presses
  int left_fr_pow = (controller.get_analog(ANALOG_LEFT_Y)+controller.get_analog(ANALOG_RIGHT_X)+controller.get_analog(ANALOG_LEFT_X))*driveSpeed;
  int left_bc_pow = (controller.get_analog(ANALOG_LEFT_Y)+controller.get_analog(ANALOG_RIGHT_X)-controller.get_analog(ANALOG_LEFT_X))*driveSpeed;
  int right_fr_pow = (controller.get_analog(ANALOG_LEFT_Y)-controller.get_analog(ANALOG_RIGHT_X)-controller.get_analog(ANALOG_LEFT_X))*driveSpeed;
  int right_bc_pow = (controller.get_analog(ANALOG_LEFT_Y)-controller.get_analog(ANALOG_RIGHT_X)+controller.get_analog(ANALOG_LEFT_X))*driveSpeed;

  //The controller drifts.  Setting below values eliminates drift/motors humming
  // below sets the controller to not respond unless the sticks have a value >= 10
  if (abs(left_fr_pow) < 10)
    left_fr_pow = 0;
  if (abs(left_bc_pow) < 10)
    left_bc_pow = 0;
  if (abs(right_fr_pow) < 10)
    right_fr_pow = 0;
  if (abs(right_bc_pow) < 10)
    right_bc_pow = 0;

  setDrive(left_fr_pow, left_bc_pow,right_fr_pow,right_bc_pow);
}

void setDriveMotorsFieldCentric(){
  DriveFieldCentric(controller.get_analog(ANALOG_LEFT_X),controller.get_analog(ANALOG_LEFT_Y),controller.get_analog(ANALOG_RIGHT_X));
}
