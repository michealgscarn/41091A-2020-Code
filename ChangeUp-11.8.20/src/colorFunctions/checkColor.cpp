#include "main.h"
using namespace okapi;
/*
*
* Check Color Function
*
* This function will return a string value if there is a red or blue ball sensed on a given color sensor
*
* Created on 11/11/2020
* Created by Taylor and Logan Daugherty
*
* Last Updated 11/11/2020
* Last Updated by Taylor Daugherty
*
*/
std::string CheckColor(std::string location){

//----------Bottom sensor----------//
  if(location == "bottom"){
    return colorParam((bottomColor.get_hue()));
  }

//----------Middle Sensor----------//
  if(location == "middle"){
    return colorParam(middleColor.get_hue());
  }

//----------Top Sensor----------//
  if(location == "top"){
    return colorParam(topColor.get_hue());
  }
  return "Invalid Location";   //Return empty if the values above are not met
}

std::string colorParam(double colorValue){
  //-----Blue-----//
  if(colorValue >= 210 & colorValue <= 280){    //If the input value is within the blue values...
    return "blue";    //Return blue
  }

  //-----Red-----//
  if((colorValue >= 0 & colorValue <= 20)||(colorValue >=300 & colorValue <= 360)){   //If the input value is within the red values...
    return "red";   //Return red
  }

  return "empty";   //Return empty if the values above are not met
}
