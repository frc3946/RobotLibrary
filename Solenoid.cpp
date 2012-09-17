#include "Solenoid.h"

Solenoid::Solenoid() {
  attached = false;
}

Solenoid::Solenoid(short forwardPin, short reversePin) {
  valve = new Spike(forwardPin, reversePin);
  attached = true;
  closeValve();
  state = false;
}

void Solenoid::attach(short forwardPin, short reversePin) {
  valve = new Spike(forwardPin, reversePin);
  attached = true;
  closeValve();
  state = false;
}

void Solenoid::openValve() {
  if(attached == true) {
    valve->setForward();
    state = true;
  }
}

void Solenoid::closeValve() {
  if(attached == true) {
    valve->setOff();
    state = false;
  }
}

void Solenoid::shootValve(int length) {
  if(attached == true) {
    openValve();
    delay(length);
    closeValve();
  }
}

bool Solenoid::getState() {
  if(attached == true) {
    return state;
  } else {
    return -105;
  }
}
