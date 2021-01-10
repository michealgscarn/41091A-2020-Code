#include "main.h"
 using namespace okapi;

//HELPER FUNCTIONS
double resetEnc(double original, double current){
  return(current-original);
}

//STRAFE PID
void strafeDrive(double target, float dir, float exitTime){
  //Convert target into degrees
  target *= 41.34468;
  //Reset encoders
  double orginalM = m.get();
  double orginalL = l.get();
  double orginalR = r.get();

  //Set PID gains
  double kp = 0.18; double pSpeed;
  double ki = 0; double iSpeed;
  double kd = 0; double dSpeed;
  double motorSpeed;
  double alignSpeed;

  //Define the error and last error
  double error=-target;
  double lastError;

  //Define the current time
  double currTime=0;
  //Convert exit time into ms
  exitTime*=1000;

  //Speed up robot smoothly
  for(int slewSpeed;slewSpeed<100;slewSpeed+=9){
    setDrive(-slewSpeed*dir,slewSpeed*dir,slewSpeed*dir,-slewSpeed*dir);
    pros::delay(20);
  }

  //while the robot has not reached its target distance nor time, decellerate
  while(((resetEnc( orginalM , m.get() )) < (target - 25) || (resetEnc( orginalM , m.get() ) ) > (target + 25)) & (exitTime>currTime)){
    //Set the last error
    lastError=error;
    //Set the distance from target
    error=(resetEnc( orginalM , m.get() ) - target);

    //Set all PID speeds
    pSpeed =  error * kp;
    iSpeed += error * ki;
    dSpeed =  (error-lastError)*kd;
    motorSpeed = pSpeed+iSpeed+dSpeed;

    //Readjust robot if angled.  Used frequently for autonomous runs
    alignSpeed = (resetEnc( orginalR , r.get() )-resetEnc( orginalL , l.get() ))*0.45;

    //Set the drive speed
    setDrive(-motorSpeed+alignSpeed,motorSpeed+alignSpeed,motorSpeed-alignSpeed,-motorSpeed-alignSpeed);
    //Wait time and add to total
    pros::delay(20);
    currTime+=50;

    //Print encoder values to the screen
    pros::lcd::print(5,"Middle:       %f",m.get());
    pros::lcd::print(6,"Left:         %f",l.get());
    pros::lcd::print(7,"Right:        %f",r.get());
  }
    //Brake the motors when stopped
    left_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD); left_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD); right_fr_mtr.set_brake_mode(MOTOR_BRAKE_HOLD); right_bc_mtr.set_brake_mode(MOTOR_BRAKE_HOLD);
    setDrive(0,0,0,0);
}

// Drive in strafing motion while at some angle
void strafeWithAngle(double ispeed, double iangle, double iturnSpeed, double iturnAngle, double iturnAngleSpeed) {
  double pi =  (3.14159265358979323846264338327950288);
  double radiansAngle = iangle * pi / 180;      //Robot Angle

  double Vd = 1;      //Robot Speed [-1,1]
  double Vt = 0;      //Direction change speed [-1,1]
  double turnAngleTarget = 0;

  while (turnAngleTarget < iturnAngle) {
    left_fr_mtr.move_velocity(calc1(ispeed, radiansAngle, iturnSpeed));
    left_bc_mtr.move_velocity(calc2(ispeed, radiansAngle, iturnSpeed));
    right_fr_mtr.move_velocity(calc2(ispeed, radiansAngle, iturnSpeed));
    right_bc_mtr.move_velocity(calc1(ispeed, radiansAngle, iturnSpeed));
  }
}

//Calculate Left Front and Right Rear wheel speeds
static double calc1(double ispeed, double iangle, double iturnSpeed) {
      double pi =  (3.14159265358979323846264338327950288);
      double V;

      V = ispeed * std::sin(iangle + (pi / 4)) + iturnSpeed;
      return V;
  }

  //Calculate Right Front and Left Rear wheel speeds
 static double calc2(double ispeed, double iangle, double iturnSpeed) {
      double pi =  (3.14159265358979323846264338327950288);
      double V;

      V = ispeed * std::cos(iangle + (pi / 4)) + iturnSpeed;
      return V;
  }

  static double rotateSpeed (double irotateSpeed){
      double returnSpeed;
      int i = 0;
        while (i < irotateSpeed){
        i++;
        returnSpeed += 1;
        pros::delay(50);
      }
      return returnSpeed;
  }
