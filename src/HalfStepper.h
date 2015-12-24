/*
 * HalfStepper.h - Half Stepper library for Wiring/Arduino - Version 0.1.0
 *
 * Adapted from the Arduino Stepper Library version 1.1.0
 *
 * Adapted                 (0.1)   by Jeff Mitzelfelt
 * 
 * Allows for finer control on a 4 wire stepper motor
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *
 * Drives a bipolar stepper motor.
 *
 * The sequence of control signals for 4 control wires is as follows:
 * 
 * Step C0 C1 C2 C3
 *    1  1  0  0  0
 *    2  1  0  1  0
 *    3  0  0  1  0
 *    4  0  1  1  0
 *    5  0  1  0  0
 *    6  0  1  0  1
 *    7  0  0  0  1
 *    8  1  0  0  1
 *
 */

// ensure this library description is only included once
#ifndef HalfStepper_h
#define HalfStepper_h

#include "Arduino.h"

// library interface description
class HalfStepper {
  public:
    // constructors:
    HalfStepper(int number_of_steps, int motor_pin_1, int motor_pin_2,
                                 int motor_pin_3, int motor_pin_4);

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void step(int number_of_steps);

    int version(void);

  private:
    void stepMotor(int this_step);

    int direction;            // Direction of rotation
    unsigned long step_delay; // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take
    int step_number;          // which step the motor is on

    // motor pin numbers:
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;
 
    unsigned long last_step_time; // time stamp in us of when the last step was taken
};

#endif

