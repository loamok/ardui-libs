Copyright ©2013 Huby Franck <franck.huby@loamok.org>

* [Loamok ChiliProject](https://redmine.loamok.org/projects/ardui-libs)
* [Github](https://github.com/loamok/ardui-libs)

This program and it's parts are LGPL free software.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation, either version 3 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>

See lgpl.txt

# Receiver :

Library part to manage a board containing a RX2 RC Receiver connected to your arduino.

Install the folder "Receiver" in the "libraries" folder in your sketchbook folder.
Restart the arduino ide.

## Usage :

```C++
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
  // or better shorter with :
  rc.init((RDATAS){2, 3, 4, 5});
}

void loop() {
  RDATAS rcv = rc.readDatas();
  // do something sexy with your datas from an RX2 RC Receiver board
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
  // do something sexy with your datas from an RX2 RC Receiver board
}

// #2.2 With shorter object creation
#include <Receiver.h>
// Define the pins as 
// 2 = forward
// 3 = backward
// 4 = left
// 5 = right
Receiver rc((RDATAS){2, 3, 4, 5});

void setup() {
}

void loop() {
  RDATAS rcv = rc.readDatas();
  // do something sexy with your datas from an RX2 RC Receiver board
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
  // do something sexy with your datas from an RX2 RC Receiver board
}
```

