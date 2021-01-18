#include "main.h"
using namespace okapi;
/*---------------------------------------------------------
   ____  _         _             _
  / ___|| |  ___  | |__    __ _ | |
 | |  _ | | / _ \ | '_ \  / _` || |
 | |_| || || (_) || |_) || (_| || |
  \____||_| \___/ |_.__/  \__,_||_|

 Created on 10/14/2020 by Logan and Taylor
 Last Updated on 1/15/2021 by Logan

---------------------------------------------------------*/

// ---------------- MOTORS ---------------- //
// 12 - Left front Motor                    //
// 13 - Left back Motor                     //
// 1  - Right front Motor                   //
// 10 - Right back Motor                    //
// 11 - Left Intake Motor                   //
// 16 - Right Intake Motor                  //
// 14 - Lift Motor                          //
// 6  - Delivery Motor                      //

pros::Motor left_fr_mtr(12, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_bc_mtr(13, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_fr_mtr(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_bc_mtr(10, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_int_mtr(11, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_int_mtr(16, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lift_mtr(14, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor del_mtr(6, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);
int autonomousPreSet = 0;


// ---------------- CONTROLLER ---------------- //
// Controller                                   //

pros::Controller controller(pros::E_CONTROLLER_MASTER);


// ---------------- ENCODERS ---------------- //
// 9 & 'A''B' - Left Encoder                  //
// 9 & 'C''D' - Right Encoder                 //
// 9 & 'E''F' - Middle Encoder                //
// Callibration timeout                       //
// Sensor initialize time                     //

ADIEncoder l({9,'A', 'B'}, false); // Left Encoder
ADIEncoder r({9,'C', 'D'}, false); // Right Encoder
ADIEncoder m({9,'E', 'F'}, true); // Middle Encoder
int encCallibrate; // Callibration timeout
// Sensor initialize time
void  waitForADIInit(int time){
    int timer = 0;
    while(timer < time){
      timer += 1;
      pros::delay(1);
    }
}


// ---------------- OPTICAL ---------------- //
// 8  - Bottom Color                         //
// 18 - Middle Color                         //
// 7  - Top Color                            //

pros::Optical bottomColor(8);
pros::Optical middleColor(18);
pros::Optical topColor(7);


// ---------------- OPTICAL ---------------- //
// 8  - Bottom Color                         //
// 18 - Middle Color                         //
// 7  - Top Color                            //

pros::Distance leftTrackFront(15);
pros::Distance leftTrackBack(2);
pros::Distance ballDetectBottom(17);
pros::Distance frontTrack(17);


// ---------------- LIMIT SWITCH ---------------- //
// Filter checker                                 //

pros::ADIDigitalIn bottomLimit ({19,'A'});
pros::ADIDigitalIn primaryLimit ({19,'D'});


// ---------------- LINE FOLLOWER ---------------- //
// 19 - Bottom Ball detecting                      //
// 'A' - Top Ball detecting                     //

// pros::ADIAnalogIn bottomFollower ({19,'H'});

pros::ADIAnalogIn topFollower ('A');
pros::ADIAnalogIn leftResetFollower ({19,'C'});
pros::ADIAnalogIn rightResetFollower ({19,'B'});
pros::ADIAnalogIn bottomFollower ({19,'H'});


// ---------------- CHASSIS BUILDER ---------------- //
// Motors   : 11, 12, 8, 3                           //
// Sensors  : l, r, m                                //
// Forward PID Gains  : 0.00095, 0.00001, 0.0        //
// Angle PID Gains    : 0.0032, 0.000025, 0.0        //
// Turn PID Gains : 0.0003, 0.0, 0.0                 //
// Wheel Diameter : 2.75 in                          //
// Side Wheel Distance Apart : 8.4903 in             //
// Back Wheel Distance from Center  : 5.3456         //

std::shared_ptr<OdomChassisController> drive = ChassisControllerBuilder()
  .withMotors(11, 12, 8, 3) // Motors - 11 is front left / 12 is front right / 8 is back right / 3 is back left
  .withSensors(l, r, m)  // Tracking wheels
  .withGains(  // PID Gains
    {0.00095, 0.00001, 0.00000}, // Forward PID Gais
    {0.0032, 0.000025, 0.00000}, // Angle PID Gains
    {0.0003, 0.0000, 0.00000}) // Turn PID Gains
  .withDimensions(AbstractMotor::gearset::green, {{2.75_in, 8.490274191388693_in, 5.345580847873998_in, 2.75_in}, quadEncoderTPR})
  .withOdometry(StateMode::CARTESIAN) // Coordinate System
  .buildOdometry(); // Build the chassis with Odometry

//Cast xdrive model to OdomChassisController
std::shared_ptr<okapi::XDriveModel> driveTrain = std::dynamic_pointer_cast<XDriveModel>(drive->getModel());
