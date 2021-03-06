#include "Controller.h"

Controller::Controller() {
  xbee = new XBee();
  ioSample = new Rx64IoSampleResponse();
  xbee->begin(115200);
  R1Pin = 6;  //Pin 16
  R2Pin = 4;  //Pin 11
  R3Pin;      //Pin Not Set
  L1Pin = 5;  //Pin 15
  L2Pin = 7;  //Pin 12
  L3Pin;      //Pin Not set
  RXPin = 2;  //Pin 18
  RYPin = 3;  //Pin 17
  LXPin = 1;  //Pin 19
  LYPin = 0;  //Pin 20
  update();
  potCenter = 0;
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
<<<<<<< HEAD
=======
//bool Controller::getL3() {
//  if(error == 0) {
//    return !ioSample->isDigitalOn(L3Pin,sampleNum);
//  } else {
//    return false;
//  }
//}
>>>>>>> d67b2e5674d08b47cdf1af47128628c2541e2589

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
