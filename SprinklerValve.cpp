#include "SprinklerValve.h"

SprinklerValve::SprinklerValve() {
  attached = false;
}

SprinklerValve::SprinklerValve(short forwardPin, short reversePin) {
  valve = new Spike(forwardPin, reversePin);
  attached = true;
  closeValve();
  state = false;
}

void SprinklerValve::attach(short forwardPin, short reversePin) {
  valve = new Spike(forwardPin, reversePin);
  attached = true;
  closeValve();
  state = false;
}

void SprinklerValve::openValve() {
  if(attached == true) {
    valve->setForward();
    delay(10);
    valve->setOff();
    state = true;
  }
}

void SprinklerValve::closeValve() {
  if(attached == true) {
    valve->setReverse();
    delay(10);
    valve->setOff();
    state = false;
  }
}

void SprinklerValve::shootValve(int length) {
  if(attached == true) {
    openValve();
    delay(length);
    closeValve();
  }
}

bool SprinklerValve::getState() {
  if(attached == true) {
    return state;
  } else {
    return -105;
  }
}
