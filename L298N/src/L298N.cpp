#include "L298N.h"

L298N::L298N(int IN1, int IN2, int IN3, int IN4, int ENA, int ENB)
    : _IN1(IN1), _IN2(IN2), _IN3(IN3), _IN4(IN4), _ENA(ENA), _ENB(ENB), _motor(0), _speed(0), _forward(true) {
    pinMode(_IN1, OUTPUT);
    pinMode(_IN2, OUTPUT);
    pinMode(_IN3, OUTPUT);
    pinMode(_IN4, OUTPUT);
    if (_ENA != 0) pinMode(_ENA, OUTPUT);
    if (_ENB != 0) pinMode(_ENB, OUTPUT);
}

void L298N::drive(int motor, bool forward, int speed) {  // Updated order
    _motor = motor;
    _speed = speed;
    _forward = forward;

    if (motor == 1) {
        digitalWrite(_IN1, forward ? HIGH : LOW);
        digitalWrite(_IN2, forward ? LOW : HIGH);
        if (_ENA != 0) {
            analogWrite(_ENA, speed);
        } else {
            // Control speed using IN1 and IN2 if ENA is not used
            analogWrite(_IN1, forward ? speed : 0);
            analogWrite(_IN2, forward ? 0 : speed);
        }
    } else if (motor == 2) {
        digitalWrite(_IN3, forward ? HIGH : LOW);
        digitalWrite(_IN4, forward ? LOW : HIGH);
        if (_ENB != 0) {
            analogWrite(_ENB, speed);
        } else {
            // Control speed using IN3 and IN4 if ENB is not used
            analogWrite(_IN3, forward ? speed : 0);
            analogWrite(_IN4, forward ? 0 : speed);
        }
    }
}

void L298N::driveFWD(int speed) {
    drive(1, true, speed);  // Drive motor 1 forward
    drive(2, true, speed);  // Drive motor 2 forward
}

void L298N::driveRVS(int speed) {
    drive(1, false, speed); // Drive motor 1 backward
    drive(2, false, speed); // Drive motor 2 backward
}

void L298N::driveLEFT(int speed) {
    drive(1, false, speed); // Drive motor 1 backward
    drive(2, true, speed);  // Drive motor 2 forward
}

void L298N::driveRIGHT(int speed) {
    drive(1, true, speed);  // Drive motor 1 forward
    drive(2, false, speed); // Drive motor 2 backward
}
