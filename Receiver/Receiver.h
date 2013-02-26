/*
  Loamok/Ardui-libs/Receiver
  Receiver.h
  Manage an RX2 RC Receiver board with arduino
  Created by Franck Huby, February 23, 2013.

    This file is part of "Loamok Ardui-libs".
    https://redmine.loamok.org/projects/ardui-libs

    "Loamok Ardui-libs" is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License.

    "Loamok Ardui-libs" is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
    See lgpl.txt
*/

#ifndef Loamok_RC_Receiver_h
#define Loamok_RC_Receiver_h

#include "Arduino.h"

struct RDATAS { // Pretty structure to manage both pins and datas
  byte f; // Forward
  byte b; // Backward
  byte l; // Left
  byte r; // Right
};

class Receiver // Class that represent the receiver
{
  public:
    Receiver(byte forward, byte backward, byte left, byte right); // Object constructor #1
    Receiver(RDATAS pins); // Object constructor #2
    Receiver(); // Object constructor #3
    void init(byte forward, byte backward, byte left, byte right); // initialize with an empty object (constructor #3)
    void init(RDATAS pins); // initialize with an empty object (constructor #3)
    RDATAS readDatas(); // Read the datas from the receiver
  private:
    byte _readPin(byte pin);
    void _readFB();
    void _readLR();
    RDATAS _pins;  // pins of the arduino
    RDATAS _datas; // Values read from pins
};

#endif

