#include "main.h"
#include <iostream>
#include<string>
using namespace std;
using namespace okapi;

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$\    $$\                    $$\           $$\       $$\
$$ |   $$ |                   \__|          $$ |      $$ |
$$ |   $$ |$$$$$$\   $$$$$$\  $$\  $$$$$$\  $$$$$$$\  $$ | $$$$$$\   $$$$$$$\
\$$\  $$  |\____$$\ $$  __$$\ $$ | \____$$\ $$  __$$\ $$ |$$  __$$\ $$  _____|
 \$$\$$  / $$$$$$$ |$$ |  \__|$$ | $$$$$$$ |$$ |  $$ |$$ |$$$$$$$$ |\$$$$$$\
  \$$$  / $$  __$$ |$$ |      $$ |$$  __$$ |$$ |  $$ |$$ |$$   ____| \____$$\
   \$  /  \$$$$$$$ |$$ |      $$ |\$$$$$$$ |$$$$$$$  |$$ |\$$$$$$$\ $$$$$$$  |
    \_/    \_______|\__|      \__| \_______|\_______/ \__| \_______|\_______/

posC
----
Current position in the selection
Starts at first place
Resets on each page

posP
----
Previous position in the selection
Updates the page when posC changes
Resets on each page

lineC
-----
Current line of order
Breaks to next line after something is selected
Goes up a line when B button is pressed

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

int posC=1; //Current position of each selection
int posP=0; //Previous position of each selection
int lineC=0; //Current line of order
int lineP=0; //Line Backup
std::string autoSel="Skills";
std::string lineM[]={"Home","","Skills"}; //Total line memory
std::string page="Home"; //Current Page

std::string odomDetails;
std::string trackLeft;
std::string trackRight;
std::string trackMiddle;


/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

$$$$$$$\              $$\     $$\
$$  __$$\             $$ |    $$ |
$$ |  $$ |$$\   $$\ $$$$$$\ $$$$$$\    $$$$$$\  $$$$$$$\   $$$$$$$\
$$$$$$$\ |$$ |  $$ |\_$$  _|\_$$  _|  $$  __$$\ $$  __$$\ $$  _____|
$$  __$$\ $$ |  $$ |  $$ |    $$ |    $$ /  $$ |$$ |  $$ |\$$$$$$\
$$ |  $$ |$$ |  $$ |  $$ |$$\ $$ |$$\ $$ |  $$ |$$ |  $$ | \____$$\
$$$$$$$  |\$$$$$$  |  \$$$$  |\$$$$  |\$$$$$$  |$$ |  $$ |$$$$$$$  |
\_______/  \______/    \____/  \____/  \______/ \__|  \__|\_______/

RIGHT ARROW
-----------
Moves one option to the right for each page
Limited to only moving right on any place but the last

LEFT ARROW
----------
Moves one option to the left for each page
Limited to only moving left on any place but the first

A BUTTON
--------
Selected Option will be the next page
Enter down a line after pressed

B BUTTON
--------
Go up a line when pressed

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void rightButton(){
    posC+=1; //Move one option to the right
    while(controller.get_digital(DIGITAL_RIGHT)){}; //Wait until button not pressed
}
void leftButton(){
    posC-=1; //Move one option to the left
    while(controller.get_digital(DIGITAL_LEFT)){}; //Wait until button not pressed
}

void aButton(std::string selC[]){
    for(int i=0;i<sizeof(selC->c_str());i++){ //Write the next page
      if(posC==i+1){
        page = selC[i]; //Update the current page ID
        lineM[i+1]=selC[i];
        if(lineC==2){
          controller.set_text(1,0,"                   ");
          lineC=-1;
          page="Home";
          autoSel=selC[i];
        }
      }
    }
    lineC++; //Update line count
    posC=1; //Reset option position
    posP=0; //Update Page after
    while(controller.get_digital(DIGITAL_A)){}; //Wait until button not pressed
}

void bButton(){
  controller.set_text(lineC,0,"                   ");

    posP=0;
    lineC--; //Go back one line
    page=lineM[lineC];
    while(controller.get_digital(DIGITAL_B)){}; //Wait until button not pressed
}

void selectButtons(std::string selC[]){ //Enter the current options and the new options
  if((controller.get_digital(DIGITAL_RIGHT)) & (posC != sizeof(selC->c_str())-1)){ //If the Right Button was pressed and not on the last option
    rightButton();
  }
  else if((controller.get_digital(DIGITAL_LEFT)) & (posC != 1)){ //If the Left Button was pressed and not on the first option
    leftButton();
  }
  else if(controller.get_digital(DIGITAL_A)){ //If the A Button was pressed
    aButton(selC);
  }
  else if(controller.get_digital(DIGITAL_B) & (lineC!=0)){
    bButton();
  }
}

void infoButtons(std::string selC[]){ //Enter the current options and the new options
  if((controller.get_digital(DIGITAL_RIGHT)) & (posC != sizeof(selC->c_str())-1)){ //If the Right Button was pressed and not on the last option
    rightButton();
  }
  else if((controller.get_digital(DIGITAL_LEFT)) & (posC != 1)){ //If the Left Button was pressed and not on the first option
    leftButton();
  }
  else if(controller.get_digital(DIGITAL_B) & (lineC!=0)){
    bButton();
  }
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

 /$$   /$$                 /$$             /$$
| $$  | $$                | $$            | $$
| $$  | $$  /$$$$$$   /$$$$$$$  /$$$$$$  /$$$$$$    /$$$$$$
| $$  | $$ /$$__  $$ /$$__  $$ |____  $$|_  $$_/   /$$__  $$
| $$  | $$| $$  \ $$| $$  | $$  /$$$$$$$  | $$    | $$$$$$$$
| $$  | $$| $$  | $$| $$  | $$ /$$__  $$  | $$ /$$| $$_____/
|  $$$$$$/| $$$$$$$/|  $$$$$$$|  $$$$$$$  |  $$$$/|  $$$$$$$
 \______/ | $$____/  \_______/ \_______/   \___/   \_______/
          | $$
          | $$
          |__/

UPDATEPAGE
----------
Update the current line with new values

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void centerText(std::string str){
  int midText=str.length()/2;
  int startPoint=9-midText;
  controller.set_text(lineC,0,"                   ");
  pros::delay(200);
  controller.set_text(lineC,startPoint,str);
}

bool Blink=false;

void blinkTimer(){
  while(true){
    pros::delay(1000);
    Blink=true;
    pros::delay(200);
    Blink=false;
  }
}

void updatePage(std::string selC[]){ //Enter current options
  if(posC != posP || Blink){
    posP=posC;;
    for(int i=0;i<sizeof(selC->c_str());i++){ //Loop each option
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


/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

$$$$$$$\
$$  __$$\
$$ |  $$ |$$$$$$\   $$$$$$\   $$$$$$\
$$$$$$$  |\____$$\ $$  __$$\ $$  __$$\
$$  ____/ $$$$$$$ |$$ /  $$ |$$$$$$$$ |
$$ |     $$  __$$ |$$ |  $$ |$$   ____|
$$ |     \$$$$$$$ |\$$$$$$$ |\$$$$$$$\
\__|      \_______| \____$$ | \_______|
                   $$\   $$ |
                   \$$$$$$  |
                    \______/

Set up the page based off of the page in question, selection for that page, and following page after

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void selectPage(std::string pageQ,std::string selC[]){ //Enter the Page in Question, current selection, and future selection
  if(page==pageQ){ //If the page in question is the actual page
    updatePage(selC);
    selectButtons(selC); //Run the Buttons
  }
}

void infoPage(std::string pageQ,std::string selC[]){ //Enter the Page in Question, current selection, and future selection
  if(page==pageQ){ //If the page in question is the actual page
    updatePage(selC);
    infoButtons(selC); //Run the Buttons
  }
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

 $$$$$$\             $$\           $$\   $$\
$$  __$$\            $$ |          $$ |  $$ |
$$ /  \__| $$$$$$\ $$$$$$\         $$ |  $$ | $$$$$$\
\$$$$$$\  $$  __$$\\_$$  _|        $$ |  $$ |$$  __$$\
 \____$$\ $$$$$$$$ | $$ |          $$ |  $$ |$$ /  $$ |
$$\   $$ |$$   ____| $$ |$$\       $$ |  $$ |$$ |  $$ |
\$$$$$$  |\$$$$$$$\  \$$$$  |      \$$$$$$  |$$$$$$$  |
 \______/  \_______|  \____/        \______/ $$  ____/
                                             $$ |
                                             $$ |
                                             \__|

Set up arrays based off inputed information

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

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

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

$$$$$$\           $$\   $$\     $$\           $$\ $$\
\_$$  _|          \__|  $$ |    \__|          $$ |\__|
  $$ |  $$$$$$$\  $$\ $$$$$$\   $$\  $$$$$$\  $$ |$$\ $$$$$$$$\  $$$$$$\
  $$ |  $$  __$$\ $$ |\_$$  _|  $$ | \____$$\ $$ |$$ |\____$$  |$$  __$$\
  $$ |  $$ |  $$ |$$ |  $$ |    $$ | $$$$$$$ |$$ |$$ |  $$$$ _/ $$$$$$$$ |
  $$ |  $$ |  $$ |$$ |  $$ |$$\ $$ |$$  __$$ |$$ |$$ | $$  _/   $$   ____|
$$$$$$\ $$ |  $$ |$$ |  \$$$$  |$$ |\$$$$$$$ |$$ |$$ |$$$$$$$$\ \$$$$$$$\
\______|\__|  \__|\__|   \____/ \__| \_______|\__|\__|\________| \_______|

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void initilizeController(){
  controller.clear();
  lineC=2;
  centerText(autoSel);
  lineC=0;
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

 /$$      /$$           /$$
| $$$    /$$$          |__/
| $$$$  /$$$$  /$$$$$$  /$$ /$$$$$$$
| $$ $$/$$ $$ |____  $$| $$| $$__  $$
| $$  $$$| $$  /$$$$$$$| $$| $$  \ $$
| $$\  $ | $$ /$$__  $$| $$| $$  | $$
| $$ \/  | $$|  $$$$$$$| $$| $$  | $$
|__/     |__/ \_______/|__/|__/  |__/

All other functions branch off from the main function

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void contDisplay(){ //480 x 272
  initilizeController();
  pros::Task blinkingText(blinkTimer);
  while(!controller.get_digital(DIGITAL_Y)){
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

    setUpPage("Home",       "Select", "Autonomous",         "Odometry",   "Debug",    "Set Up");                   //->
    setUpPage("Autonomous", "Select", "Red",                "Blue",       "Skills");                  //-->
    setUpPage("Red",        "Select", "Red 1",              "Red 2",      "Red 3",    "Red 3");        //--->
    setUpPage("Blue",       "Select", "Blue 1",             "Blue 2",     "Blue 3",   "Blue 3");       //--->
    setUpPage("Skills",     "Info",   "Skills");                                                      //-->
    setUpPage("Odometry",   "Info",   odomDetails, trackLeft, trackRight, trackMiddle);  //-->
    setUpPage("Debug",      "Info",   "Temp: Safe",         "l");                                                       //-->
    pros::delay(1);
  }
  controller.clear();
  lineC=1;
  centerText("Start");
  while(controller.get_digital(DIGITAL_Y)){pros::delay(1);}

}
