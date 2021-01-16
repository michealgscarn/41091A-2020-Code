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

 Created on 10/14/2020 by Logan and Taylor
 Last Updated on 1/15/2021 by Logan

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
