#include "main.h"
using namespace okapi;

/*

--\   --\ --\       ------\                      --\      --\ --\      --\   --\
-- |  -- |-- |     --  __--\                     ---\    --- |---\    --- |---- |
-- |  -- |-- |     -- /  \__|                    ----\  ---- |----\  ---- |\_-- |
-------- |-- |     -- |            ------\       --\--\-- -- |--\--\-- -- |  -- |
--  __-- |-- |     -- |            \______|      -- \---  -- |-- \---  -- |  -- |
-- |  -- |-- |     -- |  --\                     -- |\-  /-- |-- |\-  /-- |  -- |
-- |  -- |--------\\------  |                    -- | \_/ -- |-- | \_/ -- |------\
\__|  \__|\________|\______/                     \__|     \__|\__|     \__|\______|
Home Row  Left Goal  Center                       Middle Row   Middle Goal  1 Ball
g

        Runs Left Side Autonomous

        3 Points Our alliance | 2 Points against Opposing Alliance

        1. Cycle the Middle Goal in home row

        2. Cycle the Left Corner Goal in home row
*/

void a_HLC_MM1(){
startTime=pros::millis();

drive->setMaxVelocity(175);   //Slow the robot down for more accuracy and precision
drive->setState({46_in,12_in,-135_deg});   //Set the state for odometry
// strafeDrive(24,-1,5);    //Strafe left to align with goal
setIntake(-127);
pros::delay(600);
drive->setMaxVelocity(250);   //Slow the robot back down for accuracy and precision
drive->turnToPoint({0_in,0_in});    //Turn to face corner goal
setIntake(127);   //Start running intake to pick up ball
setDrive(40,40,40,40);    //Drive into the goal
pros::delay(500);   //Wait for it to get in there

while (left_bc_mtr.get_actual_velocity() != 0) { //check if the back motor has stopped
  pros::delay(1);
}
setDrive(-10,-10,-10,-10);    //Back away from goal slowly
pros::delay(300);   //Wait a bit for it to back up enough
setDrive(0,0,0,0);    //Stop moving
cycleScore(2,8);    //Cycle with 3 balls
setIntake(127);    //Run intake backwards to not decsore any balls
drive->setMaxVelocity(175); //Set to normal drive speed
drive->driveToPoint({48_in,48_in},true); //Drive to line up with left corner goal
setIntake(-127);
pros::delay(750);
setIntake(0);
drive->setMaxVelocity(250);
drive->turnToPoint({72_in,72_in});
drive->setMaxVelocity(175);
setDrive(60,60,60,60);
pros::delay(1000);
setDrive(-20,-20,-20,-20);
pros::delay(500);
setDrive(0,0,0,0);
setLift(127);
while(pros::millis()-startTime<13*1000){pros::delay(10);}
setDelivery(127);
setLift(127);
pros::delay(1000);
setDrive(-127,-127,-127,-127);
pros::delay(500);
}
