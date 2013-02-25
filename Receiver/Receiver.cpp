/*
  Loamok/Ardui-libs/Receiver
  Receiver.cpp
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


#include "Arduino.h"
#include "Receiver.h"

/**
 * Receieer constructor ; Params in order are : 
 *  Forward pin
 *  backward pin
 *  Left pin
 *  Right pin
**/
Receiver::Receiver(int forward, int backward, int left, int right)
{
  // Assigns the pins
  _pins = { forward, backward, left, right };
  // Set the pins as inputs
  pinMode(_pins.f, INPUT);
  pinMode(_pins.b, INPUT);
  pinMode(_pins.l, INPUT);
  pinMode(_pins.r, INPUT);
  // Datas are initialized to LOW (0)
  _datas = {LOW, LOW, LOW, LOW};
}

/**
 * Entry point to obtain datas from youre RX2 rc receiver
**/
RDATAS Receiver::readDatas()
{
  _readFB();
  _readLR();
  return _datas;
}

/***********************************************************/
/******************** INTERNAL WORKFLOW ********************/
/***********************************************************/
// DRY Mode

/**
 * Read a pin from the arduino
**/
int Receiver::_readPin (int pin) {
  return digitalRead(pin);
}

/**
 * Read Datas for Forward/Backward
**/
void Receiver::_readFB() {
  _datas.f = _readPin(_pins.f);
  _datas.b = _readPin(_pins.b);
}


/**
 * Read Datas for Left/Right
**/
void Receiver::_readLR() {
  _datas.l = _readPin(_pins.l);
  _datas.r = _readPin(_pins.r);
}

