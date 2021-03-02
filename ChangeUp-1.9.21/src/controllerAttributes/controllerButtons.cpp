#include "main.h"
#include <iostream>
#include<string>
using namespace std;
using namespace okapi;

/*-----------------------------------------------------------------------------
  ____          _    _
 | __ )  _   _ | |_ | |_  ___   _ __   ___
 |  _ \ | | | || __|| __|/ _ \ | '_ \ / __|
 | |_) || |_| || |_ | |_| (_) || | | |\__ \
 |____/  \__,_| \__| \__|\___/ |_| |_||___/

 Created on 1/10/2021 by Logan
 Last update on 2/9/2021 by Logan

-----------------------------------------------------------------------------*/

// ----------------------- RIGHT ARROW ----------------------- //
// Moves one option to the right for each page.                //
// Limited to only moving right on any place but the last.     //
void rightButton(){
    posC+=1; //Move one option to the right
    while(controller.get_digital(DIGITAL_RIGHT)){pros::delay(10);}; //Wait until button not pressed
}


// ---------------------- LEFT ARROW ---------------------- //
// Moves one option to the left for each page.              //
// Limited to only moving left on any place but the first.  //
void leftButton(){
    posC-=1; //Move one option to the left
    while(controller.get_digital(DIGITAL_LEFT)){pros::delay(10);}; //Wait until button not pressed
}


// ---------------- A BUTTON ---------------- //
// Selected Option will be the next page.     //
// Enter down a line after pressed.           //
void aButton(std::string selC[]){
    for(int i=0;i<sizeof(selC->c_str());i++){ //Write the next page
      if(posC==i+1){
        page = selC[i]; //Update the current page ID
        lineM[i+1]=selC[i];
        if(lineC==2){
          lineC=-1;
          page="Home";
          autoSel=selC[i];
          controller.set_text(1,0,"                         ");
        }
      }
    }
    lineC++; //Update line count
    posC=1; //Reset option position
    posP=0; //Update Page after
    while(controller.get_digital(DIGITAL_A)){pros::delay(10);}; //Wait until button not pressed
}


// ---------------- B BUTTON ---------------- //
// Go up a line when pressed.                 //
void bButton(){
  controller.set_text(1,0,"                   ");
    posP=0;
    page=lineM[lineC-1];
    lineC--; //Go back one line
    while(controller.get_digital(DIGITAL_B)){pros::delay(10);}; //Wait until button not pressed
}


// ----------------------- Y BUTTON ----------------------- //
// This function is Reserved to any action for the time.    //
// Commands run in driver Control.                          //
void yButton(){
  if(controller.get_digital(DIGITAL_Y)){
  }
}


// ----------------------- X BUTTON ----------------------- //
// This function is Reserved to any action for the time.    //
// Commands run in driver Control.                          //
void xButton(){
  if(controller.get_digital(DIGITAL_X)){
    quickAlign(24,1);
  }
}

// ---------------- EXTRA BUTTONS ---------------- //
// Collection of all extra Buttons.                //
void extraDriver(){
  yButton();
  xButton();
}

// ------------------- SELECTION BUTTONS ------------------- //
// Use the buttons in a way to select the current option.    //
// Uses the right arrow, left arrow, a button, and b button. //

void selectButtons(std::string selC[]){ //Enter the current options and the new options
  if((controller.get_digital(DIGITAL_RIGHT)) & (posC != 4)) //If the Right Button was pressed and not on the last option
    rightButton();
  else if((controller.get_digital(DIGITAL_LEFT)) & (posC != 1)) // If the Left Button was pressed and not on the first option
    leftButton();
  else if(controller.get_digital(DIGITAL_A)) //If the A Button was pressed
    aButton(selC);
  else if(controller.get_digital(DIGITAL_B) & (lineC!=0))
    bButton();
}

void selectPage(std::string pageQ,std::string selC[]){ //Enter the Page in Question, current selection, and future selection
  if(page==pageQ){ //If the page in question is the actual page
    updatePage(selC);
    selectButtons(selC); //Run the Buttons
  }
}


// --------------------- INFO BUTTONS --------------------- //
// Use the buttons in a way to scroll through information.  //
// Uses the right arrow, left arrow, and a button.          //

void infoButtons(std::string selC[]){ //Enter the current options and the new options
  if((controller.get_digital(DIGITAL_RIGHT)) & (posC != sizeof(selC->c_str())-1)) //If the Right Button was pressed and not on the last option
    rightButton();
  else if((controller.get_digital(DIGITAL_LEFT)) & (posC != 1)) //If the Left Button was pressed and not on the first option
    leftButton();
  else if(controller.get_digital(DIGITAL_B) & (lineC!=0))
    bButton();
}

void infoPage(std::string pageQ,std::string selC[]){ //Enter the Page in Question, current selection, and future selection
  if(page==pageQ){ //If the page in question is the actual page
    updatePage(selC);
    infoButtons(selC); //Run the Buttons
  }
}
