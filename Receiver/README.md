Loamok/Ardui-libs/Receiver
keywords.txt
Functions description for the arduino© ide

Created by Franck Huby, February 25, 2013.

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

Usage :

// #1 With empty object and init
#include <Receiver.h>
Receiver rc;

void setup() {
  // Define the pins as 
  // 2 = forward
  // 3 = backward
  // 4 = left
  // 5 = right
  RDATAS p = {2, 3, 4, 5};
  rc.init(p);
  // or shorter with :
  rc.init({2, 3, 4, 5});
}

void loop() {
  RDATAS rcv = rc.readDatas();
  // do something sexy with you're datas from an RX2 RC Receiver board
}

// #2 With short object creation
#include <Receiver.h>
// Define the pins as 
// 2 = forward
// 3 = backward
// 4 = left
// 5 = right
RDATAS p = {2, 3, 4, 5};
Receiver rc(p);

void setup() {
}

void loop() {
  RDATAS rcv = rc.readDatas();
  // do something sexy with you're datas from an RX2 RC Receiver board
}

// #3 With long object creation
#include <Receiver.h>
// Define the pins as 
// 2 = forward
// 3 = backward
// 4 = left
// 5 = right
Receiver rc(2, 3, 4, 5);

void setup() {
}

void loop() {
  RDATAS rcv = rc.readDatas();
  // do something sexy with you're datas from an RX2 RC Receiver board
}


