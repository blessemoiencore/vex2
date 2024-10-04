#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

void RedPositive(){
odom_constants();
conveyor.setVelocity(100,percent);
intake.setVelocity(100,percent);
chassis.set_coordinates(0,0,0);
intake.spinFor(reverse,0.3,seconds);
intake.spin(forward,100,percent);
chassis.drive_distance(10,0);
conveyor.spin(forward,100,percent);
chassis.drive_max_voltage = 4.5; //star
chassis.drive_distance(27,0);
conveyor.stop();
wait(0.2,seconds);

//have red plastice conveyor tooth near top
default_constants();
chassis.turn_max_voltage = 10;
//chassis.turn_to_angle(180);
chassis.turn_to_angle(180);
intake.stop();
intake.spin(reverse);
chassis.drive_max_voltage = 12;
chassis.drive_distance(-8);
chassis.drive_distance(-4);
default_constants();
grab.set(true);
conveyor.spin(forward);
wait(1, seconds);
grab.set(false);
conveyor.spin(forward);
wait(0.2,seconds);
intake.spin(forward);
chassis.turn_to_angle(50, 5.5);
chassis.drive_distance(-32, 50);
intake.spin(reverse); // check this spot
grab.set(true);
//intake.stop();
wait(0.1,sec);
//intake.spin(forward);
//chassis.drive_distance(26, 186);
chassis.turn_to_angle(148, 5.5);
chassis.drive_distance(23, 148);
wait(.5, seconds);
chassis.drive_distance(-10);
chassis.turn_to_angle(270);
intake.spin(reverse);
chassis.drive_distance(20);


/*

chassis.drive_max_voltage = 10;
chassis.drive_distance(57,188,8, 
chassis.turn_max_voltage
);

/*

chassis.drive_distance(10); 
chassis.turn_to_angle(210);
chassis.drive_distance(-4);
grab.set(true);
conveyor.spinFor(forward,1,seconds);
/*
chassis.drive_distance(15);
chassis.turn_to_angle(180);
chassis.drive_distance(48);
conveyor.spinFor(forward,1,seconds);
grab.set(false);
chassis.drive_distance(8);
chassis.turn_to_angle(150);
chassis.drive_distance(10);
grab.set(true);
chassis.turn_to_angle(225);
conveyor.spin(forward);
chassis.drive_distance(15);
conveyor.stop();
chassis.turn_to_angle(0);
chassis.drive_distance(15); */
}