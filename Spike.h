/*
||
|| @description
|| | Control a Spike Relay
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

#ifndef SPIKE_H
#define SPIKE_H

#include "Arduino.h"

class Spike {
  public:
    Spike(short forwardPin, short reversePin);
    void setForward();
    void setReverse();
    void setOff();
    short getState();
  private:
    short _forwardPin;
    short _reversePin;
    short state;
};
#endif
