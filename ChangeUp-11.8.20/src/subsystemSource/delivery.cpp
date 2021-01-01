#include "main.h"
 using namespace okapi;
//HELPER FUNCTIONS
void setDelivery(int power){
  del_mtr.set_voltage_limit(12000);
  del_mtr = power;
}

 //DELIVERY CONTROL FUNCTIONS
 void setDeliveryMotor(){
   //Set delivery speed based on button presses
   int power = 127 * (controller.get_digital(DIGITAL_R1) - controller.get_digital(DIGITAL_L2)- controller.get_digital(DIGITAL_R2));
   setDelivery(power);
 }
