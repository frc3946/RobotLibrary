#include "SpeedController.h"

SpeedController::SpeedController(short pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  //servo = new Servo();
  servo.attach(_pin);
  servo.writeMicroseconds(1500);
  speed = 0;
}

void SpeedController::setSpeed(short newSpeed) {
  if(newSpeed >= -100 && newSpeed <= 100) {
    speed = newSpeed;
  } else {
    speed = 0; //Sets to OFF
    Serial.println("Jaguar: Input Out Of Range");
  }
  servo.writeMicroseconds(map(speed,-100, 100, 1000, 2000));
}

short SpeedController::getSpeed() {
  return speed;
}
