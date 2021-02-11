#include "main.h"
using namespace okapi;

void A_SKILLS_JANUARY_FEBRUARY(){
// ---------- SET UP ---------- //
  drive->setState({58.75_in,16_in,-90_deg});
  maxSpeed=500;

// ---------- GOAL 1 ---------- //
  // ----- Unfold ----- //
  setIntake(-127);  // Run intake in reverse to deploy
  setDelivery(127); // Spin the delivery forward
  DriveCoordShort(58,23,-90,0.8); // Line up with ball

  // ----- Ball 1 ----- //
  setDelivery(0); // Stop the Delivery
  setIntake(127); // Spin the Intake inward
  setLift(95);  // Spin the Lift forward
  DriveCoordShort(33,22,-90,0.9); // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(26.1,35.3,-88.9,0.9); // Line up with Ball
  DriveCoordShort(17,35.4,-88.9,0.75); // Pick up Ball

  // ----- Goal ----- //
  setIntake(0); // Stop the Intake
  setLift(60); // Stop the Lift
  setDelivery(0); // Stop the Delivery
  DriveCoordShort(21.9,21.8,-130.5,0.9);  // Line up with goal
  DriveCoordShort(10,10,-133.4,0.7);  // Drive into Goal
  cycleScoreSetup();  // Set up Balls to score
  filter=false; // Turn off Filtering after cycling
  setLift(127);
  setDelivery(127);
  while(!ballIn()){pros::delay(1);}
  cycleScore(1,3,2); // Cycle 2 Balls while Filtering Blue
  filter=true;

// ---------- GOAL 2 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(21.9,21.8,-130.5,0.5);  // Back up from Goal
  pros::Task dfasdf(cycleScoreFilter);
  DriveCoordShort(48.5,48,3.8,1.9); // Line up with Ball
  while(ballFiltering()){pros::delay(10);}
  setDelivery(0); // Stop the Delivery
  setIntake(127); // Run intake forward to pick up a ball
  setLift(90);  // Start running lift
  DriveCoordShort(49,70,5,0.9); // Drive forward to pick up ball

  // ----- Ball 2 ----- //
  DriveCoordShort(52,70,-86,.75); // Turn to face next ball

  // ----- Goal ---- //
  setLift(0);  // Start running lift
  setLift(90);  // Start running lift
  setIntake(80); // Run intake forward to pick up a ball
  DriveCoordShort(19,75,-86.5,1); // Drive into goal
  cycleScore(2,3,2);

// ---------- GOAL 3 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(46,71.8,-90,0.9); // Back away from goal
  DriveCoordShort(39,95,4.3,1.9); // Line up with ball
  setDelivery(0); //Stop running delivery
  setIntake(127); //Start running intake forward to pick up ball
  setLift(80);   //Start running lift

  // ----- Reset Position ----- //
    setDelivery(0); //Stop running delivery
    setIntake(127); //Start running intake forward to pick up ball
    setLift(80);   //Start running lift
  resetY=117.5; // Set the Y reset Position
  pros::Task yo(lineReset); // Start the Line Reset
  QLength preState=drive->getState().x;
  quickAlign("X");  // Reset the X position
  while((drive->getState().x>preState+5_in)|| (drive->getState().x<preState-5_in)){
    quickAlign("X");  // Reset the X position
  }
  maxSpeed=80; // Drive Slowly across the Line
  DriveCoordShort(35,122,3.1,1.1);  // Pick up Ball
  maxSpeed=500; // Resume normal Speed

  // ----- Ball 2 ----- //
  // DriveCoordShort(30,106,-90,1.1);  // Line up with ball
  // DriveCoordShort(18.4,106,-90,1.1);  // Pick up Ball

  // ----- Goal ----- //
  DriveCoordShort(23.6,118,-50,0.9);  // Line up with Goal
  setIntake(0);
  DriveCoordShort(14,131,-51,0.8);  // Drive into Goal
  filter=false;
  cycleScore(1,3,1);
  filter=true;

// ---------- GOAL 4 ---------- //
  // ----- Ball 1 ----- //
  setIntake(-127);  // Run intake in reverse
  setDelivery(-127);  // Stop running delivery
  setLift(80);  // Stop running lift
  DriveCoordShort(23.6,117,-50,1);  // Back away from goal
  pros::Task fdsfsdf(cycleScoreFilter);
  DriveCoordShort(51,93,90,1.8);  // Line up with Ball
  setIntake(127); // Run intake in reverse
  setDelivery(0); // Stop running delivery
  setLift(60);  // Stop running lift
  DriveCoordShort(72.5,93,90,1.1);  // Pick up Ball

  // ----- Goal ---- //
  setIntake(10);  // Run intake in reverse
  DriveCoordShort(72.8,119,-3,1.25); // Drive into Goal
  filter=false;
  cycleScore(1,3,1);
  filter=true;

// ---------- GOAL 5 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(72.8,112,-3,0.9); // Drive away from Goal
  pros::Task filterBall(cycleScoreFilter);
  DriveCoordShort(85,119,91,1.8); // Line up with Ball
  setLift(127);  // Stop running lift
  QLength preState2=drive->getState().y;
  quickAlignNorthEast("Y"); // Reset X and Theta position
  while((drive->getState().y>preState2+10_in)|| (drive->getState().y<preState2-10_in)){
    quickAlignNorthEast("Y"); // Reset X and Theta position
  }
  pros::delay(250);
  while(ballFiltering()){pros::delay(10);}
  pros::delay(50);
  setIntake(127); // Run intake in reverse
  setLift(127);  // Stop running lift
  setDelivery(0); // Stop running delivery
  DriveCoordShort(106,118,93,0.9);  // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(117,108.5,93,0.9); // Line up with Ball
  DriveCoordShort(124.5,108.5,93,0.9); // Pick up Ball

  // ----- Goal ----- //
  setIntake(0);
  DriveCoordShort(121,121,45,0.9); // Line up with Goal
  setLift(0);
  pros::Task setUpGoal5(cycleScoreSetup);
  DriveCoordShort(128,131,50,0.75); // Drive into Goal
  while(!isCycleScoreSetup){pros::delay(10);};
  filter=false;
  setLift(127);
  setDelivery(127);
  while(!ballIn()){pros::delay(1);}
  cycleScore(1,3,2);
  filter=true;

// ---------- GOAL 6 ---------- //
  // ----- Ball 1 ----- //
  DriveCoordShort(116,116,45,1); // Drive from Goal
  setIntake(0);
  setDelivery(-30);
  setLift(-30);
  pros::Task fdsf(cycleScoreFilter);
  DriveCoordShort(96,95,182,1.8); // Line up with Ball
  while(ballFiltering()){pros::delay(10);}
  setIntake(127);    //Run intake in reverse
  setDelivery(0);   //Stop running delivery
  setLift(127);   //Stop running lift
  DriveCoordShort(93,72.5,180,0.9); // Pick up Ball

  // ----- Ball 2 ----- //
  DriveCoordShort(92.5,73,93.5,1); // Line up with Ball

  // ----- Goal ----- //
  // pros::Task setUpGoal6(cycleScoreSetup);
  setLift(0);
  setIntake(80);
  DriveCoordShort(125,73,92,1.2); // Drive into Goal
  filter=false;
  cycleScore(2,2.25,2); // Cycle 1 Ball while Filtering Blue
  filter=true;

  // ---------- GOAL 7 ---------- //
  setIntake(-127);  // Run intake in reverse
  setDelivery(-127);  // Stop running delivery
  setLift(80);  // Stop running lift
  DriveCoordShort(113,68.5,92,0.9); // Back away from Goal
  pros::Task dfdfs(cycleScoreFilter);
  DriveCoordShort(110,50,182,2);  // Line up with Ball

  // ----- Reset Odometry ----- //
  resetY=22;  // Set Y postion
  pros::Task lo(lineReset); // Begin line reset
  quickAlignNorthEast("X"); // Reset X and Theta position
  setDelivery(0);   //Stop running delivery
  setIntake(127);   //Start running intake forward to pick up ball
  setLift(127);   //Start running lift
  maxSpeed=80;
  pros::delay(300);
  while(ballFiltering()){pros::delay(10);}
  setLift(127);   //Start running lift
  DriveCoordShort(106,18,183,1.5);    //Drive forward to pick up ball
  maxSpeed=500;
  DriveCoordShort(119,21,137,0.65);    //Line up with goal
  setIntake(0);   //Stop running intake
  pros::delay(200);   //Wait a bit
  pros::Task dfdsfss(cycleScoreSetup);
  DriveCoordShort(138,10,137,0.75);    //Drive into goal

  //-----Score in Goal-----//
  while(!isCycleScoreSetup){pros::delay(10);};
  cycleScore(1,3,1);

  DriveCoordShort(125,21,138,1); //Back away from goal

// ---------- Goal 8 (Center) ---------- //
  // ----- Transition to Goal-----//
  DriveCoordShort(108,34,90,1.25);   //Line up with ball 199 33

  setIntake(127);   //Start running intake
  setLift(127);   //Start running lift
  setDelivery(0);
  DriveCoordShort(125.5,34,90,0.9);    //Pick up ball
  pros::delay(200);
  setIntake(127);   //Start running intake
  setLift(80);   //Start running lift
  setDelivery(0);
  DriveCoordShort(94,63,270,1.9);    //Drive in front of goal
  pros::delay(400);

  // ----- Descore from Goal ----- //
  setIntake(-127);   //Run intake in reverse
  setLift(0);   //Stop running lift
  setDelivery(0);
  DriveCoordShort(80,62,270,0.75);    //Drive in front of goal
  DriveCoordShort(82,56,318,0.75);   // Line up to shoot
  setIntake(0);

  //-----Score in Goal-----//
  setDelivery(127);   //Start running delivery
  setLift(127);
  pros::delay(800);   //Wait for ball to score
  setDelivery(0);   //Stop running delivery

// ---------- Goal 9 (Front Wall) ---------- //
  // ----- Transition to Goal ----- //
  DriveCoordShort(96,48,309,1);   //Back away from goal
  DriveCoordShort(93,45.5,273,0.85);    //Turn to face ball
  setIntake(127);   //Start running intake to pick up ball
  setLift(127);   //Start running lift
  DriveCoordShort(70,45.5,273,1.15);    //Pick up ball
  pros::delay(200);
  setLift(0);   //Start running lift
  DriveCoordShort(72,28,180,1.3);    //Line up with goal
  setIntake(0);   //Stop running intake
  DriveCoordShort(72,18,180,0.5);    //Drive into goal

  // ----- Score in Goal ----- //
  cycleScore(2,3,1);
  DriveCoordShort(70,40,180,0.5);   //Back away from goal
}
