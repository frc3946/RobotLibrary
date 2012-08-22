#include "Controller.h"

Controller::Controller() {
  xbee = new XBee();
  ioSample = new Rx64IoSampleResponse();
  xbee->begin(115200);
  R1Pin = 2;  //DIO2
  R2Pin = 0;  //DIO0
  L1Pin = 6;  //DIO6
  L2Pin = 1;  //DIO1
  RXPin = 5;  //DIO5
  RYPin = 3;  //DIO3
  LXPin = 0;  //Pin not set
  LYPin = 4;  //DIO4
  UpPin = 7;  //DIO7
  potCenter = -101;
}

void Controller::update() {
  xbee->readPacket();
  if (xbee->getResponse().isAvailable()) { // got something
    if (xbee->getResponse().getApiId() == RX_64_IO_RESPONSE) { //validity check
      xbee->getResponse().getRx64IoSampleResponse(*ioSample);
      error = 0;
      //Serial.println("WE ARE GOOD!");
      if(potCenter == -101) {
        potCenter = (getRX() + getRY() + getLX() + getLY())/4;
      }
    }
    else {
      //Serial.print("Expected I/O Sample, but got ");
      //Serial.println(xbee->getResponse().getApiId(), HEX);
      error++;
    }
  }
  else if (xbee->getResponse().isError()) {
    //Serial.print("Error reading packet.  Error code: ");
    //Serial.println(xbee->getResponse().getErrorCode());
    error++;
  } else {
  	//Serial.println("Um... Why is this here? No packet and no error?");
  	error++;
  }
}

bool Controller::getR1() {
  if(error == 0) {
    return !ioSample->isDigitalOn(R1Pin,sampleNum);
  } else {
    return false;
  }
}
bool Controller::getR2() {
  if(error == 0) {
    return !ioSample->isDigitalOn(R2Pin,sampleNum);
  } else {
    return false;
  }
}
bool Controller::getL1() {
  if(error == 0) {
    return !ioSample->isDigitalOn(L1Pin,sampleNum);
  } else {
    return false;
  }
}
bool Controller::getL2() {
  if(error == 0) {
    return !ioSample->isDigitalOn(L2Pin,sampleNum);
  } else {
    return false;
  }
  
}
bool Controller::getUp() {
  if(error == 0) {
    return !ioSample->isDigitalOn(UpPin,sampleNum);
  } else {
    return false;
  }
}

short Controller::getRX() {
  static short RXprev = potCenter;
  if(error == 0) {
    RXprev = (short)map(ioSample->getAnalog(RXPin,sampleNum),0,1023,-100,100);
    return RXprev;
  } else if(error <= 3) {
    return RXprev;
  } else {
    return potCenter;
  }
}
short Controller::getRY() {
  static short RYprev = potCenter;
  if(error == 0) {
    RYprev = (short)map(ioSample->getAnalog(RYPin,sampleNum),0,1023,-100,100);
    return RYprev;
  } else if(error <= 3) {
    return RYprev;
  } else {
    return potCenter;
  }
}
short Controller::getLX() {
  static short LXprev = potCenter;
  if(error == 0) {
    LXprev = (short)map(ioSample->getAnalog(LXPin,sampleNum),0,1023,-100,100);
    return LXprev;
  } else if(error <= 3) {
    return LXprev;
  } else {
    return potCenter;
  }
}
short Controller::getLY() {
  static short LYprev = potCenter;
  if(error == 0) {
    LYprev = (short)map(ioSample->getAnalog(LYPin,sampleNum),0,1023,-100,100);
    return LYprev;
  } else if(error <= 3) {
    return LYprev;
  } else {
    return potCenter;
  }
}
