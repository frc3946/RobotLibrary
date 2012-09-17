#include "Spike.h"

Spike::Spike() {
  attached = false;
}

Spike::Spike(short forwardPin, short reversePin) {
  _forwardPin = forwardPin;
  _reversePin = reversePin;
  pinMode(_forwardPin, OUTPUT);
  pinMode(_reversePin, OUTPUT);
  attached = true;
  setOff();
}

void Spike::attach(short forwardPin, short reversePin) {
  _forwardPin = forwardPin;
  _reversePin = reversePin;
  pinMode(_forwardPin, OUTPUT);
  pinMode(_reversePin, OUTPUT);
  attached = true;
  setOff();
}

void Spike::setOff() {
  if(attached == true) {
    digitalWrite(_forwardPin, LOW);
    digitalWrite(_reversePin, LOW);
    state = 0;
  }
}

void Spike::setForward() {
  if(attached == true) {
    digitalWrite(_forwardPin, HIGH);
    digitalWrite(_reversePin, LOW);
    state = 1;
  }
}

void Spike::setReverse() {
  if(attached == true) {
    digitalWrite(_forwardPin, LOW);
    digitalWrite(_reversePin, HIGH);
    state = -1;
  }
}

short Spike::getState() {
  if(attached == true) {
    return(state);
  } else {
    return -105;
  }
}


