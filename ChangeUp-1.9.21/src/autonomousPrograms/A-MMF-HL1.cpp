#include "main.h"
using namespace okapi;
/*-------------------------------------------------------------------------------------------------------

--\      --\ --\      --\ --------\  --\   --\ --\       ------\        --\   --\ --\      --\  ------\
---\    --- |---\    --- |--  _____| -- |  -- |-- |     --  __--\       -- |  -- |---\    --- |--  __--\
----\  ---- |----\  ---- |-- |       -- |  -- |-- |     -- /  \__|      -- |  -- |----\  ---- |-- /  \__|
--\--\-- -- |--\--\-- -- |-----\     -------- |-- |     -- |            -------- |--\--\-- -- |-- |
-- \---  -- |-- \---  -- |--  __|    --  __-- |-- |     -- |            --  __-- |-- \---  -- |-- |
-- |\-  /-- |-- |\-  /-- |-- |       -- |  -- |-- |     -- |  --\       -- |  -- |-- |\-  /-- |-- |  --\
-- | \_/ -- |-- | \_/ -- |-- |       -- |  -- |--------\\------  |      -- |  -- |-- | \_/ -- |\------  |
\__|     \__|\__|     \__|\__|------\\__|  \__|\________|\______/------\\__|  \__|\__|     \__| \______/
                              \______|                           \______|
Middle Row | Middle Goal | Fill  ||  Home Row | Left Goal | Cycle  ||  Home Row | Middle Goal | Cycle

Created on 1/13/21 by Logan
Last updated on 1/14/21 by Logan

PREPARE THE PROGRAM
-------------------
Set up the robot's Odometry positon.

GOAL 1
------
Pick up the ball on the autonomous line directly in front of the robot.
Strafe a ball into the center goal.
Score the preload and picked up ball into center goal.

GOAL 2
------
Line up with bottom left corner ball.
Pick up bottom left corner ball and score in goal.

GOAL 3
------
Line up with home middle goal.
Cycle goal and leave only the red ball.

-------------------------------------------------------------------------------------------------------*/

void a_MMF_HLC_HMC(){
drive->setState({34.5_in,16_in,0_deg}); // Set up State
startTime=pros::millis();   //Set up the timer
maxSpeed=800; // Set Maximum Speed
//---------- GOAL 1 (CENTER) ----------//
// ----- Unfold ----- //
setIntake(-127); // Unfold Intake
setDelivery(30); // Unfold Hood

// ----- Ball 1 ----- //
DriveCoordShort(36, 45, 0, 2); // Line up with ball
setIntake(127); // Start Intake
setLift(80); // Start Lift
setDelivery(0); // Stop Delivery
maxSpeed=200; // Set Maximum Speed
DriveCoordShort(36, 60, 0, 1); // Pick up Ball

// ----- Ball 2 ----- //
maxSpeed=800; // Set Maximum Speed
setIntake(-5); // Spin intake in reverse to funnel ball into goal
DriveCoordShort(61, 60, 0, 1); // Push Ball into Center goal
setLift(0);

// ----- Goal ----- //
DriveCoordShort(56, 53, 0, 1); // Back away from ball
DriveCoordShort(56, 53, 38, 1); // Line up with goal
setIntake(0); // Stop intake
maxSpeed=200; // Set Maximum Speed
DriveCoordShort(62, 62, 38, 1); // Drive into goal
setDelivery(-60); // Start delivery to shoot ball in
setLift(-40); // Start lift to lift ball into goal
pros::delay(400); // Wait for ball to deliver
setDelivery(127); // Start delivery to shoot ball in
setLift(60); // Start lift to lift ball into goal
pros::delay(800); // Wait for ball to deliver

// ----------- GOAL 2 (HOME LEFT) ---------- //
// ----- Ball 1 ----- //
maxSpeed=800; // Set Maximum Speed
DriveCoordShort(56, 53, 38, 1); // Back away from goal
setDelivery(0); // Stop delivering the ball
setIntake(127); // Begin intake
DriveCoordShort(30, 31.5, -142, 2); // Line up with ball
maxSpeed=200; // Set Maximum Speed
DriveCoordShort(20, 20, -142, 1); // Pick up ball
pros::delay(400); // Wait for ball to be picked up
setIntake(0); // Stop intake

// ----- Goal ----- //
DriveCoordShort(14, 14, -144, 1); // Drive into goal
setDelivery(127); // Start delivery to shoot ball in
setLift(80); // Start lift to lift ball into goal
pros::delay(800); // Wait for ball to deliver
// FilterBall("Blue",2); // Score ball into goal
setIntake(-127); // Stop intake
setLift(127); // Continue Lift to filter
setDelivery(127); // Continue Delivery to filter

// ---------- GOAL 3 (HOME MIDDLE) ---------- //
maxSpeed=800; // Set Maximum Speed
DriveCoordShort(73, 40, -180, 2); // Back up from goal
maxSpeed=200; // Set Maximum Speed
DriveCoordShort(73, 20, -180, 1); // Back up from goal
cycleGoal("blue", 2);


setIntake(-127); // Stop intake
setLift(80); // Continue Lift to filter
setDelivery(-127); // Continue Delivery to filter
DriveCoordShort(73, 50, -180, 2); // Back up from goal
}
