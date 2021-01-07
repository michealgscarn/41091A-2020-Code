#include "main.h"
using namespace okapi;
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//rumble the controller if anty drive motors get hot
if(left_fr_mtr.get_temperature()>=55||right_fr_mtr.get_temperature()>=55||
left_bc_mtr.get_temperature()>=55||right_bc_mtr.get_temperature()>=55||
lift_mtr.get_temperature()>=55||del_mtr.get_temperature()>=55||
left_int_mtr.get_temperature()>=55||right_int_mtr.get_temperature()>=55)
  {
    controller.rumble("-");
  }

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

LEGACY DISPLAY POSITION
-----------------------
Display on the Brain screen the current encoder values and Odometry position.
Print the encoder values on lines 2-4.
Print the Odometry position on lines 5-7.

LEGACY DISPLAY BALL
-------------------
Display on the Brain screen the current ball attributes.
Print the ball count on line 2.
Print the filter count on line 3.
Print the color of ball from the bottom optical sensor on line 4.

LEGACY DISPLAY TEMPERATURE
--------------------------
Display on the Brain screen the drive motor temperature values.
Print the temperature of the drive motors in celcius on lines 2-5.

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
bool pressed=false;

void legacyDisplayPos(){
  while(true){
  	pros::lcd::print(0,"41091A Revelation");
    pros::lcd::print(1,"Middle:       %f",m.get());
    pros::lcd::print(2,"Left:         %f",l.get());
    pros::lcd::print(3,"Right:        %f",r.get());
    pros::lcd::print(4, "XPosition(in):  %f", drive->getState().x.convert(inch));
    pros::lcd::print(5, "YPosition (in): %f", drive->getState().y.convert(inch));
    pros::lcd::print(6, "Angle: %f", drive->getState().theta);
    pros::delay(200);
  }
}

void legacyDisplayBall(){
  while(true){
  	pros::lcd::print(0,"41091A Revelation");
    pros::lcd::print(1,"Ball Count:   %i",ballCount);
    pros::lcd::print(2,"Filter Count: %i",filterCount);
    pros::lcd::print(3,"Color:        %s",CheckColor("bottom"));
    pros::delay(200);
  }
}

void legacyDisplayTemp(){
  while(true){
    pros::lcd::print(0,"41091A Revelation");
    pros::lcd::print(1,"lf:       %f",left_fr_mtr.get_temperature());
    pros::lcd::print(2,"rf:       %f",right_fr_mtr.get_temperature());
    pros::lcd::print(3,"rb:       %f",right_bc_mtr.get_temperature());
    pros::lcd::print(4,"lb:       %f",left_bc_mtr.get_temperature());
    pros::delay(200);
  }
}
