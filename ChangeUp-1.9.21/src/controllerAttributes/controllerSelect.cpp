// #define _GLIBCXX_USE_CXX11_ABI 0
#include "main.h"
#include <iostream>
#include <sstream>
#include<string>
#include <array>
using namespace std;
using namespace okapi;
//
/*-----------------------------------------------------------------------------
   ____               _                _  _                   __  __         _
  / ___| ___   _ __  | |_  _ __  ___  | || |  ___  _ __      |  \/  |  __ _ (_) _ __
 | |    / _ \ | '_ \ | __|| '__|/ _ \ | || | / _ \| '__|     | |\/| | / _` || || '_ \
 | |___| (_) || | | || |_ | |  | (_) || || ||  __/| |        | |  | || (_| || || | | |
  \____|\___/ |_| |_| \__||_|   \___/ |_||_| \___||_|        |_|  |_| \__,_||_||_| |_|

  Created on 1/10/2021 by Logan
  Last updated on 3/28/2021 by Logan

-----------------------------------------------------------------------------*/

// ---------------- posC ---------------- //
// Current position in the selection.     //
// Starts at first place.                 //
// Resets on each page.                   //
int posC=1; //Current position of each selection


// ---------------- posP ---------------- //
// Previous position in the selection.    //
// Updates the page when posC changes.    //
// Resets on each page.                   //
int posP=0; //Previous position of each selection


// ---------------------- lineC ---------------------- //
// Current line of order.                              //
// Breaks to next line after something is selected.    //
// Goes up a line when B button is pressed.            //
int lineC=0; //Current line of order


// ------------------------------------ lineP ------------------------------------ //
// Previous line in order.                                                         //
// Takes current line position to temporarily change lineC.                        //
// Changes lineC back to lineP after temporary change made to return to original.  //
int lineP=0; //Line Backup                                                         //


// ---------------- BLINK ---------------- //
// Blink the current option on screen.     //
// Blinks the option every second.         //
// Follows the option through lines.       //
bool Blink=false;
void blinkTimer(){
  while(true){
    pros::delay(1000);
    Blink=true;
    pros::delay(200);
    Blink=false;
  }
}


// ---------------- AUTONOMOUS SELECTED ---------------- //
// Current Autonous to run.                              //
// Runs the autonomous program set.                      //
// Preset to Skills.                                     //
std::string autoSel=""; // Current Selected Autonomous
std::string lineM[]={"Home","",""}; //Total line memory
std::string page="Home"; // Current Page


// ---------------- CENTER TEXT ---------------- //
// Center text in middle of screen
void centerText(std::string str){
  controller.set_text(lineC,0,"                   "); // Reset the screen
  int midText=str.length()/2; // Find middle of text
  int startPoint=9-midText; // Find place to put text
  pros::delay(50);  // Wait for screen to update
  controller.set_text(lineC,startPoint,str);  // Print text to screen
}

std::string odomDetails;
std::string trackLeft;
std::string trackRight;
std::string trackMiddle;
void updateOdometryCont(){
  while(true){
    odomDetails="X: "+to_string((int)round(drive->getState().x.convert(inch)))+" Y: "+to_string((int)round(drive->getState().y.convert(inch)))+" A: "+to_string((int)round(drive->getState().theta.convert(degree)));
    trackLeft="L: "+to_string(l.get());
    trackRight="R: "+to_string(r.get());
    trackMiddle="M: "+to_string(m.get());
    pros::delay(10);
  }
}


std::string motorTemp;
void updateDebugCont(){
  while(true){
    if(left_fr_mtr.get_temperature()>=55||right_fr_mtr.get_temperature()>=55||
    left_bc_mtr.get_temperature()>=55||right_bc_mtr.get_temperature()>=55||
    lift_mtr.get_temperature()>=55||del_mtr.get_temperature()>=55||
    left_int_mtr.get_temperature()>=55||right_int_mtr.get_temperature()>=55)
      motorTemp="Overheated";
    else if(left_fr_mtr.get_temperature()>=45||right_fr_mtr.get_temperature()>=45||
    left_bc_mtr.get_temperature()>=45||right_bc_mtr.get_temperature()>=45||
    lift_mtr.get_temperature()>=45||del_mtr.get_temperature()>=45||
    left_int_mtr.get_temperature()>=45||right_int_mtr.get_temperature()>=45)
      motorTemp="Unsafe";
    else
      motorTemp="Safe";
    pros::delay(10);
  }
}


// ---------------- UPDATEPAGE ---------------- //
// Update the current line every 0.1 seconds    //
void updateTimer(){
  while(true){
    pros::delay(200);
    while(controller.get_digital(DIGITAL_A)||controller.get_digital(DIGITAL_B)){pros::delay(1);}
    posP=posC-1;
  }
}

// ---------------- UPDATEPAGE ---------------- //
// Update the current line with new values.     //
void updatePage(std::string selC[]){ //Enter current options
  if(posC != posP){
    posP=posC;
    for(int i=0;i<posC;i++){ //Loop each option
      if(posC==i+1) //If the current option is found
        centerText(selC[i]);
    }
    if(lineC!=2){
      lineP=lineC;
      lineC=2;
      centerText(autoSel);
      lineC=lineP;
    }
  }
}


// ---------------- SET UP PAGE ---------------- //
// Set up arrays based off inputed information.  //
void setUpPageType(std::string pageQ, std::string pageType, std::string selC[]){
  if(pageType=="Select")
    selectPage(pageQ,selC);
  else if(pageType=="Info")
    infoPage(pageQ,selC);
}

//Five Options
void setUpPage(std::string pageQ, std::string pageType, std::string a, std::string b, std::string c, std::string d, std::string e){
  std::string selC[]={a,b,c,d,e}; //Create Array for options in page
  setUpPageType(pageQ, pageType, selC);
}
//Four Options
void setUpPage(std::string pageQ, std::string pageType, std::string a, std::string b, std::string c, std::string d){
  std::string selC[]={a,b,c,d}; //Create Array for options in page
  setUpPageType(pageQ, pageType, selC);
}
//Three Options
void setUpPage(std::string pageQ, std::string pageType, std::string a, std::string b, std::string c){
  std::string selC[]={a,b,c}; //Create Array for options in page
  setUpPageType(pageQ, pageType, selC);
}
//Two Options
void setUpPage(std::string pageQ, std::string pageType, std::string a, std::string b){
  std::string selC[]={a,b}; //Create Array for options in page
  setUpPageType(pageQ, pageType, selC);
}
//One Option
void setUpPage(std::string pageQ, std::string pageType, std::string a){
  std::string selC[]={a}; //Create Array for options in page
  setUpPageType(pageQ, pageType, selC);
}

// ---------------- INITIALIZE ---------------- //
// Clear the screen and print starting text.    //

void initilizeController(){
  controller.clear();
  lineC=2;
  // centerText("Quick");
  lineC=0;
}


// ------------------------ MAIN ------------------------ //
// All other functions branch off from the main function. //
void controllerDisplaySel(){
  initilizeController(); // Initialize the controller screen
  pros::Task updateLine(updateTimer); // Update the screen after a short interval
  pros::Task updateOdometry(updateOdometryCont); // Update Odometry Values
  pros::Task updateDebug(updateDebugCont); // Update Debug Values
  while(!controller.get_digital(DIGITAL_Y)){ // While the button Y is not pressed
    // Print pages
    setUpPage("Home",       "Select", "Autonomous",     "Odometry",       "Debug",      "Set Up");  //->
    setUpPage("Autonomous", "Select", "Left",           "Right",           "Skills");               //-->
    setUpPage("Left",      "Select", "a_HLC_MM1_MRC",  "a_HLC_MM1_HRC",    "a_HLC_HMC_MM2", "a_HLC_MM2");                               //--->
    setUpPage("Right",       "Select", "a_HRC_HMC_MM2",  "a_HRC_HMC_HLC",  "a_HRC_MM2");                 //--->
    setUpPage("Skills",     "Select", "Skills");                                                    //-->
    setUpPage("Odometry",   "Info",   odomDetails,       trackLeft,   trackRight,   trackMiddle);   //-->
    setUpPage("Debug",      "Info",   "Temp: "+motorTemp,      "l");                                //-->
    pros::delay(1);
  }
  controller.clear();
}
