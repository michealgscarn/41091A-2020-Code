#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
   ____  _         _             _
  / ___|| |  ___  | |__    __ _ | |
 | |  _ | | / _ \ | '_ \  / _` || |
 | |_| || || (_) || |_) || (_| || |
  \____||_| \___/ |_.__/  \__,_||_|

Created on 8/14/2020 by Logan and Taylor
Last Updated on 3/26/2021 by Logan

Initializes all devices used in the program
These devices include
• Motors
• Controller
• Optical Sensors
• Distance Sensors
• Limit Switches
• Line Followers
• Quad Encoders
• Odometry Chassis

-----------------------------------------------------------------------------*/

// ---------------- MOTORS ---------------- //
// 12 - Left front Motor                    //
// 13 - Left back Motor                     //
// 1  - Right front Motor                   //
// 10 - Right back Motor                    //
// 11 - Left Intake Motor                   //
// 16 - Right Intake Motor                  //
// 14 - Lift Motor                          //
// 6  - Delivery Motor                      //
pros::Motor left_fr_mtr(17, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_bc_mtr(14, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_fr_mtr(6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_bc_mtr(10, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_int_mtr(21, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_int_mtr(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lift_mtr(4, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor del_mtr(2, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
int autonomousPreSet = 0;


// ---------------- CONTROLLER ---------------- //
// Controller                                   //
pros::Controller controller(pros::E_CONTROLLER_MASTER);


// ---------------- OPTICAL ---------------- //
// 8  - Bottom Color                         //
// 18 - Middle Color                         //
// 7  - Top Color                            //
pros::Optical bottomColor(9);
pros::Optical middleColor(19);
pros::Optical topColor(7);


// ---------------- DISTANCE ---------------- //
// 15 - Front Reset Distance                  //
// 2  - Back Reset Distance                   //
// 17 - Heading Distance                      //
pros::Distance leftTrackFront(15);
pros::Distance leftTrackBack(3);
pros::Distance frontTrackLeft(20);
pros::Distance frontTrackRight(1);


// ---------------- LIMIT SWITCH ---------------- //
// Filter checker                                 //
pros::ADIDigitalIn bottomLimit ({19,'A'});
pros::ADIDigitalIn topLimit ('B');
pros::ADIDigitalIn primaryLimit ({19,'D'});


// ---------------- LINE FOLLOWER ---------------- //
// 21 - Bottom Ball detecting                      //
// 'A' - Top Ball detecting                     //
pros::ADIAnalogIn topFollower ('A');
pros::ADIAnalogIn leftResetFollower ({18,'C'});
pros::ADIAnalogIn rightResetFollower ({18,'B'});
pros::ADIAnalogIn bottomFollower ({18,'H'});


// ---------------- ENCODERS ---------------- //
// 9 & 'A''B' - Left Encoder                  //
// 9 & 'C''D' - Right Encoder                 //
// 9 & 'E''F' - Middle Encoder                //
ADIEncoder l({8,'A', 'B'}, false); // Left Encoder
ADIEncoder r({8,'C', 'D'}, false); // Right Encoder
ADIEncoder m({8,'E', 'F'}, true); // Middle Encoder


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
  .withMotors(14, 15, 8, 3) // Motors - 11 is front left / 12 is front right / 8 is back right / 3 is back left
  .withSensors(l, r, m)  // Tracking wheels
  .withGains(  // PID Gains
    {0.00095, 0.00001, 0.00000}, // Forward PID Gais
    {0.0032, 0.000025, 0.00000}, // Angle PID Gains
    {0.0003, 0.0000, 0.00000}) // Turn PID Gains
  .withDimensions(AbstractMotor::gearset::green, {{2.75_in,8.656577566605674_in, 5.338156430029729_in, 2.75_in}, quadEncoderTPR})
  .withOdometry(StateMode::CARTESIAN) // Coordinate System
  .buildOdometry(); // Build the chassis with Odometry

//Cast xdrive model to OdomChassisController
std::shared_ptr<okapi::XDriveModel> driveTrain = std::dynamic_pointer_cast<XDriveModel>(drive->getModel());

int startTime;  // Time capture of Autonomous to track time in auto
int encCallibrate=0; // Callibration timeout
