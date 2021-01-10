#include "main.h"
 using namespace okapi;

//HELPER FUNCTIONS
double resetEnc(double original, double current);

//STRAFE DRIVE
void strafeDrive(double target, float maxSpeed, float endSpace);

void strafeWithAngle(double ispeed, double iangle, double iturnSpeed, double iturnAngle, double iturnAngleSpeed);

//Calculate Left Front and Right Rear wheel speeds
static double calc1(double ispeed, double iangle, double iturnSpeed);

//Calculate Right Front and Left Rear wheel speeds
static double calc2(double ispeed, double iangle, double iturnSpeed);

static double rotateSpeed (double irotateSpeed);
