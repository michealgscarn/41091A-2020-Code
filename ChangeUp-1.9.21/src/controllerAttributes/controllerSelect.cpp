// #define _GLIBCXX_USE_CXX11_ABI 0
#include "main.h"
#include <iostream>
#include <sstream>
#include<string>
#include <array>
using namespace std;
using namespace okapi;
//
/*----------------------------------------------------------------------------

 ------\                       --\                         --\ --\
--  __--\                      -- |                        -- |-- |
-- /  \__| ------\  -------\ ------\    ------\   ------\  -- |-- | ------\   ------\
-- |      --  __--\ --  __--\\_--  _|  --  __--\ --  __--\ -- |-- |--  __--\ --  __--\
-- |      -- /  -- |-- |  -- | -- |    -- |  \__|-- /  -- |-- |-- |-------- |-- |  \__|
-- |  --\ -- |  -- |-- |  -- | -- |--\ -- |      -- |  -- |-- |-- |--   ____|-- |
\------  |\------  |-- |  -- | \----  |-- |      \------  |-- |-- |\-------\ -- |
 \______/  \______/ \__|  \__|  \____/ \__|       \______/ \__|\__| \_______|\__|

----------------------------------------------------------------------------*/

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

std::string autoSel="Skills";

std::string lineM[]={"Home","","Skills"}; //Total line memory
std::string page="Home"; // Current Page
void centerText(std::string str){
  int midText=str.length()/2;
  int startPoint=9-midText;
  controller.set_text(lineC,0,"                   ");
  pros::delay(200);
  controller.set_text(lineC,startPoint,str);
}
std::string odomDetails;
std::string trackLeft;
std::string trackRight;
std::string trackMiddle;

// int arrayLen(std::string arr[5]){
//   int result;
//   std::string str = sizeof(arr)/sizeof(arr[0]);
//   sscanf(str, "%i", &result);
//   // stringsteam result(sizeof(arr)/sizeof(arr[0]))
//   return result;
// }

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
  centerText(autoSel);
  lineC=0;
}

// ------------------------ MAIN ------------------------ //
// All other functions branch off from the main function. //

void contDisplay(){
  initilizeController(); // Initialize the controller screen
  pros::Task blinkingText(blinkTimer); // Start blinking the screen
  while(!controller.get_digital(DIGITAL_Y)){ // While the button Y is not pressed
    odomDetails="X: ";
    odomDetails.append(to_string(drive->getState().x.convert(inch)));
    odomDetails.append(" Y: ");
    odomDetails.append(to_string(drive->getState().y.convert(inch)));
    odomDetails.append(" A: ");
    odomDetails.append(to_string(drive->getState().theta.convert(degree)));
    trackLeft="L: ";
    trackLeft.append(to_string(l.get()));
    trackRight="R: ";
    trackRight.append(to_string(r.get()));
    trackMiddle="M: ";
    trackMiddle.append(to_string(m.get()));

    // Print pages
    setUpPage("Home",       "Select", "Autonomous",         "Odometry",   "Debug",      "Set Up");             //->
    setUpPage("Autonomous", "Select", "Red",                "Blue",       "Skills");                           //-->
    setUpPage("Red",        "Select", "HR1-HMC-HL1-MM1",    "HMC-HLC-MM1","HMP-HLC-MM1","HMC-HRC","MMF-HLC");  //--->
    setUpPage("Blue",       "Select", "HR1-HMC-HL1-MM1",    "HMC-HLC-MM1","HMP-HLC-MM1","HMC-HRC","MMF-HLC");  //--->
    setUpPage("Skills",     "Info",   "Skills");                                                               //-->
    setUpPage("Odometry",   "Info",   odomDetails, trackLeft, trackRight, trackMiddle);                        //-->
    setUpPage("Debug",      "Info",   "Temp: Safe",         "l");                                              //-->
    pros::delay(1);
  }
  controller.clear();
  lineC=1;
  centerText("Start");
  while(controller.get_digital(DIGITAL_Y)){pros::delay(1);}

}
