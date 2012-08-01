#include "Controller.h"

Controller::Controller() {
  //xbee = new XBee();
  //ioSample = new Rx64IoSampleResponse();
  xbee.begin(115200);
  R1Pin = 1;
  R2Pin = 1;
  L1Pin = 1;
  L2Pin = 1;
  RXPin = 1;
  RYPin = 1;
  LXPin = 1;
  LYPin = 1;
}

void Controller::update() {
  xbee.readPacket();
  if (xbee.getResponse().isAvailable()) { // got something
    if (xbee.getResponse().getApiId() == RX_64_IO_RESPONSE) { //validity check
      xbee.getResponse().getRx64IoSampleResponse(ioSample);
    }
    else {
      Serial.print("Expected I/O Sample, but got ");
      Serial.println(xbee.getResponse().getApiId(), HEX);
    }
  }
  else if (xbee.getResponse().isError()) {
    Serial.print("Error reading packet.  Error code: ");
    Serial.println(xbee.getResponse().getErrorCode());
  }
   Serial.println("I got nothing");
}

bool Controller::getR1() {
  return !ioSample.isDigitalOn(R1Pin,sampleNum);
}
bool Controller::getR2() {
  return !ioSample.isDigitalOn(R2Pin,sampleNum);
}
bool Controller::getL1() {
  return !ioSample.isDigitalOn(L1Pin,sampleNum);
}
bool Controller::getL2() {
  return !ioSample.isDigitalOn(L2Pin,sampleNum);
}

short Controller::getRX() {
  return (short)map(ioSample.getAnalog(RXPin,sampleNum),0,0,-100,100);
}
short Controller::getRY() {
  return (short)map(ioSample.getAnalog(RYPin,sampleNum),0,0,-100,100);
}
short Controller::getLX() {
  return (short)map(ioSample.getAnalog(LXPin,sampleNum),0,0,-100,100);
}
short Controller::getLY() {
  return (short)map(ioSample.getAnalog(LYPin,sampleNum),0,0,-100,100);
}
