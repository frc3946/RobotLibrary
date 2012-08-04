#include "Drivetrain.h"

Drivetrain::Drivetrain(
  short leftMotorPin,
  short rightMotorPin)
{
  numMotors = 2;
  motors = (SpeedController*) calloc(numMotors,sizeof(SpeedController));
  motors[0] = SpeedController(leftMotorPin);
  motors[1] = SpeedController(rightMotorPin);
}
Drivetrain::Drivetrain(
  short frontLeftMotorPin,
  short frontRightMotorPin,
  short rearLeftMotorPin,
  short rearRightMotorPin)
{
  numMotors = 4;
  motors = (SpeedController*) calloc(numMotors,sizeof(SpeedController));
  motors[0] = SpeedController(frontLeftMotorPin);
  motors[1] = SpeedController(frontRightMotorPin);
  motors[2] = SpeedController(rearLeftMotorPin);
  motors[3] = SpeedController(rearRightMotorPin);
  
}

Drivetrain::Drivetrain(
  SpeedController *leftMotor,
  SpeedController *rightMotor)
{
  numMotors = 2;
  motors = (SpeedController*) calloc(numMotors,sizeof(SpeedController));
  motors[0] = *leftMotor;
  motors[1] = *rightMotor;
}
Drivetrain::Drivetrain(
  SpeedController *frontLeftMotor,
  SpeedController *frontRightMotor,
  SpeedController *rearLeftMotor,
  SpeedController *rearRightMotor)
{
  numMotors = 4;
  motors = (SpeedController*) calloc(numMotors,sizeof(SpeedController));
  motors[0] = *frontLeftMotor;
  motors[1] = *frontRightMotor;
  motors[2] = *rearLeftMotor;
  motors[3] = *rearRightMotor;
}
void Drivetrain::tankDrive(short leftSpeed, short rightSpeed) {
  if(numMotors == 2) {
    motors[0].setSpeed(leftSpeed);
    motors[1].setSpeed(rightSpeed);
  } else {
    motors[0].setSpeed(leftSpeed);
    motors[1].setSpeed(rightSpeed);
    motors[2].setSpeed(leftSpeed);
    motors[3].setSpeed(rightSpeed);
  }
}

void Drivetrain::arcadeDrive(short speed, short turn) {
  
}

short Drivetrain::getSpeed(short motorNumber) {
  return motors[motorNumber].getSpeed();
}
