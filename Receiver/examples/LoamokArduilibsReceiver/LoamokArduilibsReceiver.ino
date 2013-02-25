/*
  Loamok/Ardui-libs/Receiver/examples/LoamokArduilibsReceiver
  LoamokArduilibsReceiver.ino
  Example of Managing an RX2 RC Receiver board with arduino
  Send the commands received to serial port.
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

#include <Receiver.h>

Receiver rc(2, 3, 4, 5);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  RDATAS rcd = rc.readDatas();
  Serial.println("Desc : \t; f; b; l; r");
  Serial.print("Valeurs : \t");
  Serial.print(rcd.f);
  Serial.print("; ");
  Serial.print(rcd.b);
  Serial.print("; ");
  Serial.print(rcd.l);
  Serial.print("; ");
  Serial.println(rcd.r);
  delay(500);
}
