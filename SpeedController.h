/*
||
||
|| @description
|| | Control a Speed Controller (victor or jaguar)
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


#ifndef JAGUAR_H
#define JAGUAR_H

#include "Arduino.h"
#include <Servo.h>

class SpeedController {
  public:
    SpeedController(short pin);
    void setSpeed(short newSpeed);
    short getSpeed();
  private:
    short speed;
    short _pin;
    Servo servo;
};
#endif
