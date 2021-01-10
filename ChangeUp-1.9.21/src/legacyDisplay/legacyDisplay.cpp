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

// $$$$$$$$$$$$$$$$$$$$$$$$$$ LEGACY DISPLAY POSITION $$$$$$$$$$$$$$$$$$$$$$$$$$ //
// Display on the Brain screen the current encoder values and Odometry position. //
// Print the encoder values on lines 2-4.                                        //
// Print the Odometry position on lines 5-7.                                     //

void legacyDisplayPos(){
  while(true){ // Loop infinitly
  	pros::lcd::print(0,"41091A Revelation"); // Print Title on line 1
    pros::lcd::print(1,"Middle:       %f",m.get()); // Print middle encoder value on line 2
    pros::lcd::print(2,"Left:         %f",l.get()); // Print left encoder value on line 3
    pros::lcd::print(3,"Right:        %f",r.get()); // Print right encoder value on line 4
    pros::lcd::print(4, "XPosition(in):  %f", drive->getState().x.convert(inch)); // Print X position on line 5
    pros::lcd::print(5, "YPosition (in): %f", drive->getState().y.convert(inch)); // Print Y position on line 6
    pros::lcd::print(6, "Angle: %f", drive->getState().theta); // Print theta on line 7
    pros::delay(200); // Wait for the screen to update
  }
}

// $$$$$$$$$$$$$$$$$$$$$$ LEGACY DISPLAY BALL $$$$$$$$$$$$$$$$$$$$$$ //
// Display on the Brain screen the current ball attributes.          //
// Print the ball count on line 2.                                   //
// Print the filter count on line 3.                                 //
// Print the color of ball from the bottom optical sensor on line 4. //

void legacyDisplayBall(){
  while(true){ // Loop infinitly
  	pros::lcd::print(0,"41091A Revelation"); // Print Title on line 1
    pros::lcd::print(1,"Ball Count:   %i",ballCount); // Print the ball count on line 2
    pros::lcd::print(2,"Filter Count: %i",filterCount); // Print the filter count on line 3
    pros::lcd::print(3,"Color:        %s",CheckColor("bottom")); // Print the color ball on the bottom optical
    pros::delay(200); // Wait for the screen to update
  }
}


// $$$$$$$$$$$$$$$$$$$$$$ LEGACY DISPLAY BALL $$$$$$$$$$$$$$$$$$$$$$ //
// Display on the Brain screen the current ball attributes.          //
// Print the ball count on line 2.                                   //
// Print the filter count on line 3.                                 //
// Print the color of ball from the bottom optical sensor on line 4. //

void legacyDisplayTemp(){
  while(true){ // Loop infinitly
    pros::lcd::print(0,"41091A Revelation"); // Print Title on line 1
    pros::lcd::print(1,"lf:       %f",left_fr_mtr.get_temperature()); // Print the left front drive temperature on line 2
    pros::lcd::print(2,"rf:       %f",right_fr_mtr.get_temperature()); // Print the right front drive temperature on line 3
    pros::lcd::print(3,"rb:       %f",right_bc_mtr.get_temperature()); // Print the right back drive temperature on line 4
    pros::lcd::print(4,"lb:       %f",left_bc_mtr.get_temperature()); // Print the left back drive temperature on line 5
    pros::delay(200); // Wait for the screen to update
  }
}
