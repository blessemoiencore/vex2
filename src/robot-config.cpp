#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);
motor leftMotorA = motor(PORT20, ratio6_1, true);
motor leftMotorB = motor(PORT19, ratio6_1, false);
motor leftMotorC = motor(PORT18, ratio6_1,true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB, leftMotorC);
motor rightMotorA = motor(PORT9, ratio6_1, false);
motor rightMotorB = motor(PORT7, ratio6_1, true);
motor rightMotorC = motor(PORT8, ratio6_1,false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB, rightMotorC);
inertial DrivetrainInertial = inertial(PORT17);
controller Controller1 = controller(primary);
motor conveyor = motor(PORT3, ratio18_1, true);
motor intake = motor(PORT5, ratio18_1, true); 
digital_out grab = digital_out(Brain.ThreeWirePort.H);
//Add your devices below, and don't forget to do the same in robot-config.h:


void vexcodeInit( void ) {
  // nothing to initialize
}