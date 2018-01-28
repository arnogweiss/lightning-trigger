# lightning-trigger
An arduino-based lightning trigger for still cameras. The increased ligh level
of a lightning should trigger the electric remote release of a camear.

This is mainly for me to play around with some arduino programming and arduino
based hardware design. At the same time I want to have something that my
be at least remotely useful.

All software and hardware designs are GPL V3.0, see LICENSE.txt.

## Project roadmap

### Version 0.1

Prototype with breadboard.

Functions:
* Connect to photo sensor.
* Edge detection of light level.
* Light up a LED when edge is detected.

### Version 0.2

Prototype with breadboard.

Functions:
* Make parameters modifyable at runtime:
  * edge detection threshold
  * delay for next trigger detection (blackout time)
  * length of tigger HIGH level
* Connect to display (current parameter value, set parameter value).
* Implement modes:
  * Operation
  * Set parameter _X_

### Verion 0.3

Prototype with breadboard.

Functions:
* Connect to camera via release cable.
* Experiment with relaeas duration, meter on/off signal,...

...futher versions tbd.

### Further versions

Features:

* Add PCB layout
* Add body
* Add detailed parts list
