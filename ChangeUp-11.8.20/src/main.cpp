#include "main.h"
using namespace okapi;

#include "main.h"

/*
  A callback function for LLEMU's center button.

 When this callback is fired, it will toggle line 2 of the LCD text between
  "I was pressed!" and nothing.
  This is a nice testing function for when the screen seems locked up.
 */
void on_center_button() {
    	static bool pressed = false;
    	pressed = !pressed;

    	if (pressed) {
    		  pros::lcd::set_text(2, "I was pressed!");
    	} else {
    		  pros::lcd::clear_line(2);
    	}
}


/*
  Runs initialization code. This occurs as soon as the program is started.

  All other competition modes are blocked by initialize; it is recommended
 to keep execution time for this mode under a few seconds.
 */
void initialize() {
    AutoSelect();
    //Send a wait command before building the chassis or turning on the screen
    // if you don't do this, encoder values won't be correct.
    // waitForADIInit(200);
    // pros::lcd::initialize();  //initialize brain screen so we can see info later

      //run a task to refresh the screen when using the legacy display
      // pros::Task screen_task(legacyDisplay_task_fn);
      pros::Task ballUpdate(ballCountTask);
      pros::Task filterUpdate(filterCountTask);
      bottomColor.set_led_pwm(100);
      middleColor.set_led_pwm(100);
      topColor.set_led_pwm(100);
}
/*
  Runs while the robot is in the disabled state of Field Management System or
  the VEX Competition Switch, following either autonomous or opcontrol. When
  the robot is enabled, this task will exit.
 */
void disabled() {
}

/*
  Runs after initialize(), and before autonomous when connected to the Field
  Management System or the VEX Competition Switch. This is intended for
  competition-specific initialization routines, such as an autonomous selector
  on the LCD.

  This task will exit when the robot is enabled and autonomous or opcontrol
  starts.
 */
 void competition_initialize() {
  encCallibrate=0;
  while(encCallibrate<200){
    encCallibrate+=1;
    pros::delay(1);
  }

}

/*
AUTONOMOUS CONTROL
Description: Possesses all goals in the home row

Tasks:
  1. Score and possess the goal in the top right corner of the Field
  2. Score and possess the goal in the middle right edge of the Field
  3. Score and possess the goal in the bottom right corner of the Field

Expected Point Outcome: 1 Win Point, 12 total points, 9 descored points, 18 point swing
*/


void autonomous() {

//a_HMC_HLC();
// drive->setState({0_in,0_in,-135_deg});
//   SetDriveCoordinatePID(52, 15, -180);

 // a_HMP_HL1_HR1();
// a_SKILLS_2();
  //
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
      a_SKILLS_SPINOFF_SEQUEL();
    break;
    default:
      a_SKILLS_BROKEN_ARM_DISTANCE();
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

//Continually update the screen to show OdomDebug information.
while(true){
  // FilterBall("red",300,5);
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
