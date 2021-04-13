#include "main.h"
using namespace okapi;
/*-----------------------------------------------------------------------------
  ____   _              _
 |  _ \ (_) ___  _ __  | |  __ _  _   _
 | | | || |/ __|| '_ \ | | / _` || | | |
 | |_| || |\__ \| |_) || || (_| || |_| |
 |____/ |_||___/| .__/ |_| \__,_| \__, |
                |_|               |___/

Created on 10/20/2020 by Logan and Taylor
Last Updated on 2/26/2021 by Logan

Print information on the Brain Screen

-----------------------------------------------------------------------------*/
bool pressed=false;

// -------------------------- BRAIN DISPLAY POSITION -------------------------- //
// Display on the Brain screen the current encoder values and Odometry position. //
// Print the encoder values on lines 2-4.                                        //
// Print the Odometry position on lines 5-7.                                     //
void brainDisplayPos(){
  pros::lcd::initialize();  //initialize Brain screen so we can see info later
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


// -------------------------- BRAIN DISPLAY POSITION -------------------------- //
// Display on the Brain screen the current encoder values and Odometry position. //
// Print the encoder values on lines 2-4.                                        //
// Print the Odometry position on lines 5-7.                                     //
void brainDisplayGrid(){
  pros::lcd::initialize();  //initialize Brain screen so we can see info later
  while(true){ // Loop infinitly
    OdomDebug display(lv_scr_act(), LV_COLOR_NAVY);
    display.setData({drive->getState().x, drive->getState().y, drive->getState().theta}, {l.get(), r.get(), m.get()}); // QUnits used for state (x,y,theta)
    pros::delay(20); // Wait for the screen to update
  }
}


// ---------------------- BRAIN DISPLAY BALL ---------------------- //
// Display on the Brain screen the current ball attributes.          //
// Print the ball count on line 2.                                   //
// Print the filter count on line 3.                                 //
// Print the color of ball from the bottom optical sensor on line 4. //
void brainDisplayBall(){
  pros::lcd::initialize();  //initialize Brain screen so we can see info later
  while(true){ // Loop infinitly
  	pros::lcd::print(0,"41091A Revelation"); // Print Title on line 1
    pros::lcd::print(1,"Ball In?:     %i",ballIn());
    pros::lcd::print(2,"Ball Out?:    %i",ballOut());
    pros::lcd::print(3,"Ball Count:   %i",ballCount); // Print the ball count on line 2
    pros::lcd::print(4,"Filter Count: %i",filterCount); // Print the filter count on line 3
    pros::lcd::print(5,"Color:        %s",CheckColor("bottom")); // Print the color ball on the bottom optical
    pros::delay(10); // Wait for the screen to updateballIn
  }
}


// ---------------------- BRAIN DISPLAY BALL ---------------------- //
// Display on the Brain screen the current ball attributes.          //
// Print the left front drive temperature on line 2.                 //
// Print the right front drive temperature on line 3.                //
// Print the right back drive temperature on line 4.                 //
// Print the left back drive temperature on line 5.                  //
void brainDisplayTemp(){
  pros::lcd::initialize();  //initialize Brain screen so we can see info later
  while(true){ // Loop infinitly
    pros::lcd::print(0,"41091A Revelation"); // Print Title on line 1
    pros::lcd::print(1,"lf:       %f",left_fr_mtr.get_temperature()); // Print the left front drive temperature on line 2
    pros::lcd::print(2,"rf:       %f",right_fr_mtr.get_temperature()); // Print the right front drive temperature on line 3
    pros::lcd::print(3,"rb:       %f",right_bc_mtr.get_temperature()); // Print the right back drive temperature on line 4
    pros::lcd::print(4,"lb:       %f",left_bc_mtr.get_temperature()); // Print the left back drive temperature on line 5
    pros::lcd::print(5,"del:      %f",del_mtr.get_temperature()); // Print the left back drive temperature on line 5
    pros::delay(20); // Wait for the screen to update
  }
}


// ------------------------- BRAIN DISPLAY ALIGN ------------------------- //
// Display the information needed to debug alignment functions.             //
// Print the distance between the front distance sensor and wall on line 2. //
// Print the distance between the back distance sensor and wall on line 3.  //
// Print the Theta on line 4.                                               //
// Print the X value on line 5.                                             //
// Print the Y value on line 6.                                             //
// Print the Bottom line follower brightness value on line 7.               //
void brainDisplayAlign(){
  pros::lcd::initialize();  //initialize Brain screen so we can see info later
  while(true){ // Loop infinitly
    pros::lcd::print(0,"41091A Revelation"); // Print Title on line 1
    pros::lcd::print(1,"Front Distance:%f",frontTrackLeft.get()*0.0393701+5.125); // Print the distance between the front distance sensor and wall on line 2.
    pros::lcd::print(2,"Back Distance: %f",frontTrackRight.get()*0.0393701+5.375); // Print the distance between the back distance sensor and wall on line 3.
    pros::lcd::print(3,"Theta:         %f",drive->getState().theta.convert(degree)); // Print the Theta on line 4.
    pros::lcd::print(4,"X:             %f",drive->getState().x.convert(inch)); // Print the X value on line 5.
    pros::lcd::print(5,"Y:             %f",drive->getState().y.convert(inch)); // Print the Y value on line 6.
    pros::lcd::print(6,"Bottom Value:  %d",(leftResetFollower.get_value()+leftResetFollower.get_value())/2); // Print the Bottom line follower brightness value on line 7.
    pros::delay(20); // Wait for the screen to update
  }
}
