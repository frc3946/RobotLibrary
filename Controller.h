/*
||
||
|| @description
|| | Control an XBee and devliver the results
|| #
||
|| @author
|| | Gus Michel
|| #
||
|| @license
|| | This library is free software; you can redistribute it and/or
|| | modify it under the terms of the GNU General Public
|| | License as published by the Free Software Foundation; version
|| | 4 of the License.
|| |
|| | This library is distributed in the hope that it will be useful,
|| | but WITHOUT ANY WARRANTY; without even the implied warranty of
|| | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
|| | General Public License for more details.
|| |
|| | You should have received a copy of the GNU General Public
|| | License along with this library; if not, write to the Free Software
|| | Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
|| #
||
*/


#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Arduino.h"
#include <XBee.h>
#include <NewSoftSerial.h>

class Controller {
  public:
    Controller();
    void update();
  //Digital (Buttons)
    bool getR1();
    bool getR2();
    bool getL1();
    bool getL2();
  //Analog
    short getRX();
    short getRY();
    short getLX();
    short getLY();
  private:
    XBee xbee;
    Rx64IoSampleResponse ioSample;
  //Pins
    short R1Pin;
    short R2Pin;
    short L1Pin;
    short L2Pin;
    short RXPin;
    short RYPin;
    short LXPin;
    short LYPin;
    const static int sampleNum = 1; //there is always just one sample
};
#endif
