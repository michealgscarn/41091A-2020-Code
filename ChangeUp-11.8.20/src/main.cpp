#include "main.h"
using namespace okapi;
#include "main.h"

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

$$\      $$\           $$\
$$$\    $$$ |          \__|
$$$$\  $$$$ | $$$$$$\  $$\ $$$$$$$\
$$\$$\$$ $$ | \____$$\ $$ |$$  __$$\
$$ \$$$  $$ | $$$$$$$ |$$ |$$ |  $$ |
$$ |\$  /$$ |$$  __$$ |$$ |$$ |  $$ |
$$ | \_/ $$ |\$$$$$$$ |$$ |$$ |  $$ |
\__|     \__| \_______|\__|\__|  \__|

INITIALIZE
----------
Sets up all sensors, motors and tasks.
Starts all tasks.
Initializes autonomous selector.
Turns optical sensor lights to max.

DISABLED
--------
Period of program when robot is disabled.

COMPETITION INITIALIZE
----------------------
Initialize sensors and others at the start of a comp.
Don't start autonous until the encoders are callibrated.

AUTONOMOUS
----------
The robot drives on its own.
Starts autnomous from a chosen autonomous.

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

// $$$$$$$$$$$$$$$$ INITIALIZE $$$$$$$$$$$$$$$$ //
// Sets up all sensors, motors and tasks.       //
// Starts all tasks.                            //
// Initializes autonomous selector.             //
// Turns optical sensor lights to max.          //

void initialize() {
  pros::lcd::initialize();  //initialize Brain screen so we can see info later
  // pros::Task controllerDisplay(contDisplay); //Start Controller display to see info

  AutoSelect(); //Start Brain autonomous selector to select before autonomous period

  // pros::Task screen_task(legacyDisplay_task_fn); //Display information to the Brain
  pros::Task ballUpdate(ballCountTask); //Update ball count since the start of the program
  pros::Task filterUpdate(filterCountTask); //Update filter count since the start of the program

  bottomColor.set_led_pwm(100);
  middleColor.set_led_pwm(100);
  topColor.set_led_pwm(100);
}

// $$$$$$$$$$$$$$$$ DISABLED $$$$$$$$$$$$$$$$ //
// Period of program when robot is disabled.  //

void disabled() {
}

 // $$$$$$$$$$$$$$$$ COMPETITION INITIALIZE $$$$$$$$$$$$$$$$ //
 // Initialize sensors and others at the start of a comp.    //
 // Don't start autonous until the encoders are callibrated. //

 void competition_initialize() {
  encCallibrate=0;
  while(encCallibrate<200){
    encCallibrate+=1;
    pros::delay(1);
  }

}

// $$$$$$$$$$$$$$$$ AUTONOMOUS $$$$$$$$$$$$$$$$ //
// The robot drives on its own.                 //
// Starts autnomous from a chosen autonomous.   //

void autonomous() {
  switch (auton_sel) {
    case 1:
      a_HMP_HL1_HR1();
   break;
    case 2:
      a_HMC_HLC();
    break;
    case 3:
      A_HMP_HLC_MM1();
    break;
    case 4:
      a_HRF();
    break;
    case 5:
      a_HMC_HRC();
    break;
    case 6:
    // ----------- SKILLS ----------- //
    // 1 minute autonomous program    //
    // 11 Red balls                   //
    // 7 Blue balls                   //
    // 9 Goals                        //
      a_SKILLS_SPINOFF_SEQUEL();
    // ------------------------------ //
    break;
    default:
    // ----------- DEFAULT ----------- //
    a_SKILLS_BROKEN_ARM_DISTANCE_FILTER();
    // ------------------------------- //
    break;
  }

  // DriveCoordShort(10,0,0,2);
  // pros::delay(500);
  // DriveCoordShort(10,10,0,2);
  // pros::delay(500);
  // DriveCoordShort(10,10,360,2);



//56.3,16.5


  /* SKILLS AUTONOMOUS            */
  /* 1 minute autonomous Program  */
  /* 6 Goals 7 balls              */
     //a_SKILLS();
  /*------------------------------*/

  /* RIGHT TWO GOAL AUTONOMOUS    */
  /* 15 second autonomous Program */
  /* 2 Goals 4 balls              */
  /* Middle -> Right Corner  */
    //a_HMC_HRC();
  /*------------------------------*/

  /* RIGHT ONE Goal AUTONOMOUS    */
  /* 15 second autonomous Program */
  /* 1 Goal 3 balls               */
  /* Right Corner                 */
   //a_HRF();
  /*------------------------------*/

  /* LEFT 2 GOALS AUTONOMOUS      */
  /* 15 second autonomous Program */
  /* 2 Goals 4 balls              */
  /* Middle -> Left corner        */
    //a_HMC_HLC();
  /*------------------------------*/

  /* LEFT 2 GOALS AUTONOMOUS      */
  /* 15 second autonomous Program */
  /* 2 Goals 4 balls              */
  /* Left Corner -> Center        */
     //a_HLF_MM1();
  /*------------------------------*/

  /* LEFT 3 GOALS AUTONOMOUS      */
  /* 15 second autonomous Program */
  /* 3 Goals 4 balls              */
  /* Middle -> Left Corner->Center*/
  //REENABLE??????????????????   a_HMP_HLC_MM1();
  /*------------------------------*/

}

/*
  Runs the operator control code. This function will be started in its own task
  with the default priority and stack size whenever the robot is enabled via
  the Field Management System or the VEX Competition Switch in the operator
  control mode.

 If no competition control is connected, this function will run immediately
  following initialize().

  If the robot is disabled or communications is lost, the
  operator control task will be stopped. Re-enabling the robot will restart the
  task, not resume it from where it left off.
 */

void opcontrol() {
  //drive->setState({57.5_in,9.5_in,107.7_deg});  //Set position of the Robot.  Turn on while testing
  // pros::delay(2000);
//fieldCentricDrive();
//holoVelocity(100,"fwd",30,2);
//Set up the display colors on the brain screen using LVGL
// drive->setState({21.5_in,16_in,-90_deg});   //Set the state for odometry

//OdomDebug display(lv_scr_act(), LV_COLOR_ORANGE);

//prepare the limit switch for use in functions.
bool pressed=false;
// drive->setState({13.5_in,17_in,-114_deg});   //Set the state for odometry
// drive->setState({19_in,15_in,-90_deg});   //Set the state for odometry
// pros::delay(2000);
// DriveCoordShortNoPID(10,10,0,2);
// DriveCoordShort(10,15,0,3);
//Continually update the screen to show OdomDebug information.
while(true){
  // FilterBall("blue",5);
    //Display the field as a grid
    //Show the robot on the field
    OdomDebug display(lv_scr_act(), LV_COLOR_NAVY);
   display.setData({drive->getState().x, drive->getState().y, drive->getState().theta}, {l.get(), r.get(), m.get()}); // QUnits used for state (x,y,theta)

    //get the subsystems on the robot
    setDeliveryMotor();
    setIntakeMotors();
    setLiftMotor();
    setDriveMotors(1);
    // setDriveMotorsFieldCentric();

    //initialize the speed of the robot
    double driveSpeed=1;

      if(controller.get_digital(DIGITAL_Y)){
        DriveCoord(15, 15, 360, 15);
        DriveCoord(0, 0,0, 30);
        // setDrive(127,127,-127,-127);
        // pros::delay(30000);
      }

      pros::delay(20); //delay so processor is not overwhelmed
   }
}
