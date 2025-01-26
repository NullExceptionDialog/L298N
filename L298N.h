/*
 L298N.h - A library for the motor driver L298N.
 Created by Ahmet Efe C. - 26th Jan 2025
 Distributable - requires a credit in the source code
*/

#ifndef L298N_h
#define L298N_h

#include "Arduino.h"

class L298N {
public:
    L298N(int IN1, int IN2, int IN3, int IN4, int ENA = 0, int ENB = 0);

    void driveFWD(int speed = 100);
    void driveRVS(int speed = 100);
    void driveLEFT(int speed = 100);
    void driveRIGHT(int speed = 100);
    void drive(int motor, bool forward, int speed = 100);  // Updated order
private:
    int _IN1;
    int _IN2;
    int _IN3;
    int _IN4;

    int _ENA;
    int _ENB;

    int _motor;
    int _speed;
    bool _forward;
};

#endif
