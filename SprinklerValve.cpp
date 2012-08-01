#include "SprinklerValve.h"

SprinklerValve::SprinklerValve(short forwardPin, short reversePin) {
  valve = new Spike(forwardPin, reversePin);
  closeValve();
  state = false;
}

void SprinklerValve::openValve() {
  valve->setForward();
  delay(10);
  valve->setOff();
  state = true;
}

void SprinklerValve::closeValve() {
  valve->setReverse();
  delay(10);
  valve->setOff();
  state = false;
}

void SprinklerValve::shootValve(int length) {
  openValve();
  delay(length);
  closeValve();
}

bool SprinklerValve::getState() {
  return state;
}
