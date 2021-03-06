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
 * Receiver constructor #1 ; Params in order are : 
 *  Forward pin
 *  backward pin
 *  Left pin
 *  Right pin
**/
Receiver::Receiver(byte forward, byte backward, byte left, byte right)
{
  // Assigns the pins
  init(forward, backward, left, right);
}

/**
 * Receiver constructor #2 ; Params in order are : 
 *  RDATAS STRUCT of pins
**/
Receiver::Receiver(RDATAS pins)
{
  init(pins);
}

/**
 * Receiver constructor #3
**/
Receiver::Receiver()
{
  // Datas are initialized to LOW (0)
  _datas = {LOW, LOW, LOW, LOW};
}

/**
 * Initialize an empty object create with constructor #3
**/
void Receiver::init(byte forward, byte backward, byte left, byte right) {
  // Assigns the pins
  RDATAS pins = { forward, backward, left, right };
  init(pins);
}

/**
 * Initialize an empty object create with constructor #3
**/
void Receiver::init(RDATAS pins) {
  // Assigns the pins
  _pins = pins;
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
byte Receiver::_readPin (byte pin) {
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

