#include "vex.h"
#include "Autons.h"
#include "Functions.h"
#include "DriveFunctionsConfig.h"

//Put your auton routines in here

void Auton1()
{
  //setRotGains(0, 0, 0, 20, 10); //update PID gains to tune robot
  //setLinGains(0, 0, 0, 20, 10);

 // moveLinear(24, 100, 10000);
  moveArm(reverse, 750, 100);
  wait(1000, msec);
  moveArm(fwd, 750, 100);
}

void Auton2()
{
  //grab goal from balance
  moveArm(reverse, 1750, 100);
  moveLinear(15, 50, 1000);
  moveStop(brake);
  moveArm(fwd, 1750, 100);

  //turn to yellow and lower arm
  moveLinear(-15, 50, 1000);
  moveStop(brake);
  moveRotate(-80, 50, 1000);
  moveStop(brake);
  moveArm(reverse, 1750, 100);

  //approach yellow
  moveLinear(48, 100, 1000);
  moveStop(brake);
  moveArm(fwd, 1750, 100); //pick up yellow

  moveLinear(60, 100, 1000); //approach balance
  moveStop(brake);

  moveRotate(-45, 60, 1000); //turn to align with balance
  moveStop(brake);

  moveLinear(30, 100, 1000); //drive up balance and stop
  moveStop(brake);
}