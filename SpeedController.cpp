#include "SpeedController.h"

SpeedController::SpeedController() {
  attached = false;
}

SpeedController::SpeedController(short pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  servo.attach(_pin);
  attached = true;
  speed = 0;
  setSpeed(speed);
}

void SpeedController::attach(short pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  servo.attach(_pin);
  attached = true;
  speed = 0;
  setSpeed(speed);
}

void SpeedController::setSpeed(short newSpeed) {
  if(attached == true) {
    if(newSpeed >= -100 && newSpeed <= 100) {
      speed = newSpeed;
    } else {
      speed = 0; //Sets to OFF
      //Serial.println("SpeedController: Input Out Of Range");
    }
    servo.writeMicroseconds(map(speed,-100, 100, 1000, 2000));
  }
}

short SpeedController::getSpeed() {
  if(attached == true) {
    return speed;
  } else {
    return -105;
  }
}
