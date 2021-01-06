#include "main.h"
using namespace okapi;
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

$$$$$$$\  $$\                     $$\
$$  __$$\ \__|                    $$ |
$$ |  $$ |$$\  $$$$$$$\  $$$$$$\  $$ | $$$$$$\  $$\   $$\
$$ |  $$ |$$ |$$  _____|$$  __$$\ $$ | \____$$\ $$ |  $$ |
$$ |  $$ |$$ |\$$$$$$\  $$ /  $$ |$$ | $$$$$$$ |$$ |  $$ |
$$ |  $$ |$$ | \____$$\ $$ |  $$ |$$ |$$  __$$ |$$ |  $$ |
$$$$$$$  |$$ |$$$$$$$  |$$$$$$$  |$$ |\$$$$$$$ |\$$$$$$$ |
\_______/ \__|\_______/ $$  ____/ \__| \_______| \____$$ |
                        $$ |                    $$\   $$ |
                        $$ |                    \$$$$$$  |
                        \__|                     \______/



$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
bool pressed=false;

//screen refresh steps
void legacyDisplay_task_fn(void* param) {
      while(true){

  //Print inportant information to the screen regarding Encoder Values
  		pros::lcd::print(0, "41091A Revelation");

      pros::lcd::print(2, "XPosition(in):  %f", drive->getState().x.convert(inch));
      pros::lcd::print(3, "YPosition (in): %f", drive->getState().y.convert(inch));
      pros::lcd::print(4, "Angle: %f", drive->getState().theta);

      pros::lcd::print(6, "Motor Heat (fl,fr,bl,br) %f%f%f%f",
          left_fr_mtr.get_temperature(),
          right_fr_mtr.get_temperature(),
          left_bc_mtr.get_temperature(),
          right_bc_mtr.get_temperature());

      //enable below for more information about encoders
      //pros::lcd::print(5,"Middle:       %f",m.get());
      //pros::lcd::print(6,"Left:         %f",l.get());
      //pros::lcd::print(7,"Right:        %f",r.get());

      //***** MOTORS OVERHEATING? ***** enable below
      // pros::lcd::print(4,"lf:       %f",left_fr_mtr.get_temperature());
      // pros::lcd::print(5,"rf:       %f",right_fr_mtr.get_temperature());
      // pros::lcd::print(6,"rb:       %f",right_bc_mtr.get_temperature());
      // pros::lcd::print(7,"lb:       %f",left_bc_mtr.get_temperature());

      // Print Ball Color
      pros::lcd::print(5,"Top:       %i",ballCount);
      pros::lcd::print(6,"Middle:       %i",filterCount);
      pros::lcd::print(7,"Bottom:       %s",CheckColor("bottom"));


      pros::delay (200);

  	//	pros::lcd::register_btn1_cb(on_center_button);

    //rumble the controller if anty drive motors get hot
    if(left_fr_mtr.get_temperature()>=55||right_fr_mtr.get_temperature()>=55||
    left_bc_mtr.get_temperature()>=55||right_bc_mtr.get_temperature()>=55||
    lift_mtr.get_temperature()>=55||del_mtr.get_temperature()>=55||
    left_int_mtr.get_temperature()>=55||right_int_mtr.get_temperature()>=55)
      {
        controller.rumble("-");
  	  }

      pros::delay(20);
    }
 }
