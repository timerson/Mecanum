// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include "Arduino.h"
#include "AFMotor.h"

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {

}

void loop() {
  int speed = analogRead(2);
  speed = map(speed, 0, 1023, -255, 255);
  if (speed < 0)
  {
    motor2.run(FORWARD);
    motor2.setSpeed(abs(speed));
    motor3.run(BACKWARD);
    motor3.setSpeed(abs(speed));
  }
  if (speed > 0)
  {
    motor2.run(BACKWARD);
    motor2.setSpeed(speed);
    motor3.run(FORWARD);
    motor3.setSpeed(speed);
  }
  int speed2 = analogRead(3);
  speed2 = map(speed2,  0, 1023, -255, 255);
  if (speed2 < 0)
  {
    motor1.run(BACKWARD);
    motor1.setSpeed(abs(speed2));
    motor4.run(FORWARD);
    motor4.setSpeed(abs(speed2));
  }
  if (speed2 > 0)
  {
    motor1.run(FORWARD);
    motor1.setSpeed(speed2);
    motor4.run(BACKWARD);
    motor4.setSpeed(speed2);
  }

}
