#include "main.h"
 using namespace okapi;
 /*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

 $$$$$$$\            $$\ $$\
 $$  __$$\           $$ |\__|
 $$ |  $$ | $$$$$$\  $$ |$$\ $$\    $$\  $$$$$$\   $$$$$$\  $$\   $$\
 $$ |  $$ |$$  __$$\ $$ |$$ |\$$\  $$  |$$  __$$\ $$  __$$\ $$ |  $$ |
 $$ |  $$ |$$$$$$$$ |$$ |$$ | \$$\$$  / $$$$$$$$ |$$ |  \__|$$ |  $$ |
 $$ |  $$ |$$   ____|$$ |$$ |  \$$$  /  $$   ____|$$ |      $$ |  $$ |
 $$$$$$$  |\$$$$$$$\ $$ |$$ |   \$  /   \$$$$$$$\ $$ |      \$$$$$$$ |
 \_______/  \_______|\__|\__|    \_/     \_______|\__|       \____$$ |
                                                            $$\   $$ |
                                                            \$$$$$$  |
                                                             \______/

Created By Logan and Taylor
Last Updated By Logan

DELIVERY VELOCITY
----------
Set the velocity of the Delivery motors.

CONTROLLER DELIVERY
---------------
Set the velocity of the Delivery based on Controller input

 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

 // $$$$$$$$$$$$$$$$ DELIVERY VELOCITY $$$$$$$$$$$$$$$$ //
 // Set the speed of the Delivery motors.               //

void setDelivery(int power){
  del_mtr.set_voltage_limit(12000);
  del_mtr = power;
}

// $$$$$$$$$$$$$$$$ CONTROLLER DELIVERY $$$$$$$$$$$$$$$$ //
// Set the velocity of the Delivery using the Controller.//

 void setDeliveryMotor(){
   // Set Delivery speed based on button presses
   int power = 127 * (controller.get_digital(DIGITAL_R1) - controller.get_digital(DIGITAL_L2)- controller.get_digital(DIGITAL_R2));
   setDelivery(power);// Apply the velocity to the Delivery
 }
