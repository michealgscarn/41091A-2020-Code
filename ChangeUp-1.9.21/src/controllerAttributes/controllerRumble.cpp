#include "main.h"
#include <iostream>
#include<string>
using namespace std;
using namespace okapi;
/*---------------------------------------------------------

-------\                          --\       --\
--  __--\                         -- |      -- |
-- |  -- |--\   --\ ------\----\  -------\  -- | ------\
-------  |-- |  -- |--  _--  _--\ --  __--\ -- |--  __--\
--  __--< -- |  -- |-- / -- / -- |-- |  -- |-- |-------- |
-- |  -- |-- |  -- |-- | -- | -- |-- |  -- |-- |--   ____|
-- |  -- |\------  |-- | -- | -- |-------  |-- |\-------\
\__|  \__| \______/ \__| \__| \__|\_______/ \__| \_______|

Created on 1/8/2021 by Logan and Taylor
Last updated on 1/8/2021 by Logan

TEMPERATURE RUMBER
------------------


---------------------------------------------------------*/
void tempRumble(){
  //rumble the controller if anty drive motors get hot
  if(left_fr_mtr.get_temperature()>=55||right_fr_mtr.get_temperature()>=55||
  left_bc_mtr.get_temperature()>=55||right_bc_mtr.get_temperature()>=55||
  lift_mtr.get_temperature()>=55||del_mtr.get_temperature()>=55||
  left_int_mtr.get_temperature()>=55||right_int_mtr.get_temperature()>=55)
    {
      controller.rumble("-");
    }
}
