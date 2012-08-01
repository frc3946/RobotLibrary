#include "Spike.h"

Spike::Spike(short forwardPin, short reversePin) {
  _forwardPin = forwardPin;
  _reversePin = _reversePin;
  pinMode(_forwardPin, OUTPUT);
  pinMode(_reversePin, OUTPUT);
  //setOff();
  state = 0;
}

void Spike::setOff() {
  digitalWrite(_forwardPin, LOW);
  digitalWrite(_reversePin, LOW);
  state = 0;
}

void Spike::setForward() {
  digitalWrite(_forwardPin, HIGH);
  digitalWrite(_reversePin, LOW);
  state = 1;
}

short Spike::getState() {
  return(state);
}

void Spike::setReverse() {
  digitalWrite(_forwardPin, LOW);
  digitalWrite(_reversePin, HIGH);
  state = -1;
}


