#include "main.h"
using namespace okapi;
/*--------------------------------------------------------------------------------------------------

 ------\  --\                           --\              ------\            --\
--  __--\ -- |                          -- |            --  __--\           -- |
-- /  \__|-------\   ------\   -------\ -- |  --\       -- /  \__| ------\  -- | ------\   ------\
-- |      --  __--\ --  __--\ --  _____|-- | --  |      -- |      --  __--\ -- |--  __--\ --  __--\
-- |      -- |  -- |-------- |-- /      ------  /       -- |      -- /  -- |-- |-- /  -- |-- |  \__|
-- |  --\ -- |  -- |--   ____|-- |      --  _--<        -- |  --\ -- |  -- |-- |-- |  -- |-- |
\------  |-- |  -- |\-------\ \-------\ -- | \--\       \------  |\------  |-- |\------  |-- |
 \______/ \__|  \__| \_______| \_______|\__|  \__|       \______/  \______/ \__| \______/ \__|

Created on 11/11/2020 by Taylor and Logan
Last updated on 1/7/2021 by Logan

CHECK COLOR
-----------
Checks the color of a place in the robot.
Uses the specified location to check a color.
Returns the value of color param.

COLOR PARAM
-----------
Check the color of a given senor.
Checks the optical in relation to color ranges.
Returns the color.

--------------------------------------------------------------------------------------------------*/

// ---------------- CHECK COLOR ---------------- //
// Checks the color of a place in the robot.     //
// Uses the specified location to check a color. //
// Returns the value of color param.             //

std::string CheckColor(std::string location){

// ----- Bottom sensor ----- //
  if(location == "bottom"){
    return colorParam((bottomColor.get_hue()));
  }

// ----- Middle Sensor ----- //
  if(location == "middle"){
    return colorParam(middleColor.get_hue());
  }

// ----- Top Sensor ----- //
  if(location == "top"){
    return colorParam(topColor.get_hue());
  }
  return "Invalid Location";   //Return empty if the values above are not met
}


// ----------------- COLOR PARAM ----------------- //
// Check the color of a given senor.               //
// Checks the optical in relation to color ranges. //
// Returns the color.                              //

std::string colorParam(double colorValue){
  // ----- Blue ----- //
  if(colorValue >= 210 & colorValue <= 280){    //If the input value is within the blue values...
    return "blue";    //Return blue
  }

  // ----- Red ----- //
  if((colorValue >= 0 & colorValue <= 20)||(colorValue >=300 & colorValue <= 360)){   //If the input value is within the red values...
    return "red";   //Return red
  }

  // ----- Empty ----- //
  return "empty";   //Return empty if the values above are not met
}
