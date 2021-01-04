#include "main.h"
using namespace okapi;

//MOTORS - fr=front, bc=back, int=intake, del=delivery
pros::Motor left_fr_mtr(12, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_bc_mtr(13, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_fr_mtr(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_bc_mtr(10, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor left_int_mtr(11, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor right_int_mtr(16, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor lift_mtr(14, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor del_mtr(6, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_DEGREES);

int autonomousPreSet = 0;

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);


//
// //Tracking Encoders
// ADIEncoder l{'C', 'D'}; // left encoder
// ADIEncoder r{'E', 'F'};  // right encoder
// ADIEncoder m{'G', 'H',true}; //middle encoder
//

//-----Encoders-----//
ADIEncoder l({9,'A', 'B'}, false); // left encoder
ADIEncoder r({9,'C', 'D'}, false);  // right encoder
ADIEncoder m({9,'E', 'F'}, true); //middle encoder

//-----Color Sensors-----//
pros::Optical bottomColor(8);    //Bottom color Sensor
pros::Optical middleColor(18);    //Middle color Sensor
pros::Optical topColor(7);   //Top color sensor

//------Distance Sensors-----//
pros::Distance leftTrackFront(15);
pros::Distance leftTrackBack(20);
pros::Distance frontTrack(17);

//------3-Wire Ball Sensors-----//
pros::ADIDigitalIn bottomLimit ({19,'A'});    //limit switch at filter
pros::ADIAnalogIn bottomFollower ({19,'H'});    //lLine follower at bottom of lift
pros::ADIAnalogIn topFollower ('A');    //lLine follower at top of lift


//timer to ensure ADI Encoders have time  to initialize before building chassis
void  waitForADIInit(int time){
    int timer = 0;
    while(timer < time){
      timer += 1;
      pros::delay(1);
    }
}

//encoder callibration initialization
int encCallibrate;

//Use ChassisControllerBuilder to set up the Odom Chassis
std::shared_ptr<OdomChassisController> drive = ChassisControllerBuilder()
    .withMotors(11, 12, 8, 3) // Drive Motors  8 is front left, 11 is front right, 20 is back right, 10 is back left
    .withSensors(l, r, m)  // Tracking wheels
    .withGains(  //PID Gains
      {0.00095, 0.00001, 0.00000}, // distance controller gains
      {0.0032, 0.000025, 0.00000}, // angle turn controller gains
      {0.0003, 0.0000, 0.00000}) // turn controller gains
    //.withClosedLoopControllerTimeUtil(100,10,50_ms) //enable if there are settling problems
    //2.75 in l&r tracking diameter, 12.09 in apart.  6.67 back tracking whell from robot center, 2.75 in diameter.
    .withDimensions(AbstractMotor::gearset::green, {{2.75_in, 8.490274191388693_in, 5.345580847873998_in, 2.75_in}, quadEncoderTPR})
    // .withDimensions(AbstractMotor::gearset::green, {{2.75_in, 12.00787_in, 6.0625_in, 2.75_in}, quadEncoderTPR})
    .withOdometry(StateMode::CARTESIAN) // Build the OdomChassisController with cartesian coordinates
    .buildOdometry(); //Build the chassis with odometry

//Cast xdrive model to OdomChassisController
std::shared_ptr<okapi::XDriveModel> driveTrain = std::dynamic_pointer_cast<XDriveModel>(drive->getModel());



/* uncomment below to log to the pros terminal window
    .withLogger(  //Brain Printout info aka "Logger"
      std::make_shared<Logger>(
          TimeUtilFactory::createDefault().getTimer(), // Set up a timer
          "/ser/sout", // Output to PROS terminal
          Logger::LogLevel::debug // Show errors and warnings
        )
      )
*/

// *******************************************************************************************************************
// *******************************************************************************************************************
