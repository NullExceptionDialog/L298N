#include "L298N.h"

const int IN1 = 4;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 7;

L298N motor(IN1, IN2, IN3, IN4);

void setup() {
  motor.driveFWD(75);
  delay(2000);
  motor.driveRIGHT(20);
  delay(2000);
  motor.driveRVS(100);
  delay(2000);
  motor.driveLEFT(100);
}

void loop() {
  motor.driveFWD(75);
  delay(2000);
  motor.driveRIGHT(20);
  delay(2000);
  motor.driveRVS(100);
  delay(2000);
  motor.driveLEFT(100);
}