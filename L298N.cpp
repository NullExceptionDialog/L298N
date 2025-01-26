#include "L298N.h"
#include "Arduino.h"

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
    
    int formattedSpeed = map(speed,0,100,0,255);
    
    if(speed >= 100) speed= 100;
    
    if(formattedSpeed >= 255) formattedSpeed = 255;
    
    if (motor == 1) {
        digitalWrite(_IN1, forward ? HIGH : LOW); //if forward then high if not then low
        digitalWrite(_IN2, forward ? LOW : HIGH);//if forward then low if not then high
        if (_ENA != 0) {
            analogWrite(_ENA, formattedSpeed); //Writes the formatted speed to the _ENA pin (AX and ~X)
        } else{
          //I currently have no solutions to this, but i might add something in the future so nothing for now.
            speed = 100;
            formattedSpeed = 255;
        }
    } else if (motor == 2) {
        digitalWrite(_IN3, forward ? HIGH : LOW);
        digitalWrite(_IN4, forward ? LOW : HIGH);
        if (_ENB != 0) {
            analogWrite(_ENB, formattedSpeed);
        } else{
            speed = 100;
            formattedSpeed = 255;
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
