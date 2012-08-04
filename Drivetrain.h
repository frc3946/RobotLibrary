#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Arduino.h"
#include "SpeedController.h"

class Drivetrain {
  public:
    Drivetrain( //Two Motors setup with Pin Numbers
      short leftMotorPin,
      short rightMotorPin
    );
    Drivetrain( //Four Motors setup with Pin Numbers
      short frontLeftMotorPin,
      short frontRightMotorPin,
      short rearLeftMotorPin,
      short rearRightMotorPin
    );
    Drivetrain( //Two Motors setup with Pointers
      SpeedController *leftMotor,
      SpeedController *rightMotor
    );
    Drivetrain( //Four Motors setup with Pointers
      SpeedController *frontLeftMotor,
      SpeedController *frontRightMotor,
      SpeedController *rearLeftMotor,
      SpeedController *rearRightMotor
    );
    void tankDrive(short leftSpeed, short rightSpeed);
    void arcadeDrive(short speed, short turn);
    short getSpeed(short motorNumber);
  private:
    SpeedController* motors;
    short numMotors;
};
#endif
