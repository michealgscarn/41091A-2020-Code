#include "main.h"
using namespace okapi;



void a_HR1_HMC_HL1_MM1(){
//----------Set Up----------//
  startTime=pros::millis();
  drive->setState({117.5_in,16.75_in,90_deg});   //Set the state for odometry
  maxSpeed=500;

// ---------- GOAL 1 ---------- //
  DriveCoordShort(126,21,139,1);
  setLift(40);
  // maxSpeed=200;
  DriveCoordShort(128,14,140,0.6);
  setLift(127);
  setDelivery(127);
  FilterBallNoIn("blue",1);
  setDelivery(80);
  pros::delay(400);
  cycleGoal("red",1);

// ---------- GOAL 2 ---------- //
  setDelivery(-40);
  setLift(40);
  maxSpeed=500;
  DriveCoordShort(72,25,180,2);
  maxSpeed=200;
  DriveCoordShort(72,22,180,1);
  setDelivery(127);
  setLift(127);
  pros::delay(500);

// ---------- GOAL 3 ---------- //
  setDelivery(0);
  setLift(0);
  maxSpeed=500;
  DriveCoordShort(48,48,226,1.5);
  setLift(40);
  DriveCoordShort(20,29,225,1.5);
  maxSpeed=200;
  DriveCoordShort(14,23,225,1.5);
  setLift(127);
  setDelivery(127);
  cycleGoal("red",1);
  pros::delay(500);

// ---------- GOAL 4 ---------- //
  setDelivery(0);
  setLift(0);
  setIntake(-127);
  DriveCoordShort(58,60,380,1.75);
  setIntake(-5);
  DriveCoordShort(68,60,380,1);
  DriveCoordShort(44,50.7,366,1.75);
}
