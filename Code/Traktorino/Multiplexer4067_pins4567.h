/*
  --------------------------------------------------
  CD4067 Multiplexer library - a fast and easy driver for TI 4067 chip
  https://github.com/sumotoy/Multiplexer4067
  --------------------------------------------------
  Version:0.1 basic implementation (NEVER TESTED!)
  ++++++++++++++++++++++++++++++++++++++++++++++++++
  Written by: Max MC Costa for s.u.m.o.t.o.y
  ++++++++++++++++++++++++++++++++++++++++++++++++++
  Specialized by rasprague to use pins 4, 5, 6, 7 so that digitalWriteFast can be used
-------------------------------------------------------------------------------------
          >>>>>>>>>>>> Description <<<<<<<<<<<<<<<
-------------------------------------------------------------------------------------
  The Texas Instruments CD4067 it's a CMOS multiplexer, you can use to scan 16 analog values
  (example:pots!) and feed any analog input of your processor.
-------------------------------------------------------------------------------------
        >>>>>>>>>>>>>>>>>>>>> Wiring <<<<<<<<<<<<<<<<<<<<<<<<<
-------------------------------------------------------------------------------------
  S0,S1,S2,S3 = addressing
  SIG = output to an analog pin
  EN = tied to GND

*/

#ifndef _MULTIPLEX4067_PINS4567_H_
#define _MULTIPLEX4067_PINS4567_H_
#include "Arduino.h"

class Multiplexer4067_pins4567 {
public:
  Multiplexer4067_pins4567(const uint8_t sig);
  void begin(uint8_t dir=1);
  int readChannel(uint8_t ch, uint8_t readings=5);
private:
  uint8_t  _sig;
  uint8_t  _dir;
  void _addressing(uint8_t ch);
};
#endif
