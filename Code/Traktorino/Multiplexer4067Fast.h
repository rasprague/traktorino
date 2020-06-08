/*
  --------------------------------------------------
  Multiplexer4067Fast https://github.com/rasprague/Multiplexer4067Fast
  CD4067 Multiplexer library for Arduino et al - a fast and easy driver for TI 4067 chip
  Templated version by rasprague 
  to use digitalWriteFast library https://github.com/NicksonYap/digitalWriteFast

  -------------------------------------------------------------------------
  based on work by Max MC Costa https://github.com/sumotoy/Multiplexer4067
  
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
#ifndef _MULTIPLEXER4067FAST_H_
#define _MULTIPLEXER4067FAST_H_

#include "Arduino.h"
#include "digitalWriteFast.h"

template <uint8_t adrsPin0, uint8_t adrsPin1, uint8_t adrsPin2, uint8_t adrsPin3>
class Multiplexer4067Fast {
public:
  Multiplexer4067Fast(const uint8_t sig) : _sig(sig) {
    
  }
  
  void begin(uint8_t dir=1) {
    pinModeFast(adrsPin0, OUTPUT); 
    digitalWriteFast(adrsPin0,LOW);
    pinModeFast(adrsPin1, OUTPUT); 
    digitalWriteFast(adrsPin1,LOW);
    pinModeFast(adrsPin2, OUTPUT); 
    digitalWriteFast(adrsPin2,LOW);
    pinModeFast(adrsPin3, OUTPUT); 
    digitalWriteFast(adrsPin3,LOW);
  
    if (dir != 1) { //out
      _dir = 0;
      pinMode(_sig, OUTPUT); 
    } else {
      _dir = 1;
    }
  }
  
  int readChannel(uint8_t ch, uint8_t readings=5) {
    if (_dir > 0){
      uint8_t i;
      if (ch > 15) ch = 15;
      if (readings < 1) readings = 1;
      int temp = 0;
      _addressing(ch);
      for (i=0;i<readings;i++){
        temp = temp + analogRead(_sig);
      }
      return temp/readings;
    }
    return 0;
  }

private:
  uint8_t  _sig;
  uint8_t  _dir;
  
  void _addressing(uint8_t ch) {
    switch(ch) {
      case 0:
        digitalWriteFast(adrsPin0, 0);
        digitalWriteFast(adrsPin1, 0);
        digitalWriteFast(adrsPin2, 0);
        digitalWriteFast(adrsPin3, 0);
        break;
      case 1:
        digitalWriteFast(adrsPin0, 1);
        digitalWriteFast(adrsPin1, 0);
        digitalWriteFast(adrsPin2, 0);
        digitalWriteFast(adrsPin3, 0);
        break;
      case 2:
        digitalWriteFast(adrsPin0, 0);
        digitalWriteFast(adrsPin1, 1);
        digitalWriteFast(adrsPin2, 0);
        digitalWriteFast(adrsPin3, 0);
        break;
      case 3:
        digitalWriteFast(adrsPin0, 1);
        digitalWriteFast(adrsPin1, 1);
        digitalWriteFast(adrsPin2, 0);
        digitalWriteFast(adrsPin3, 0);
        break;
      case 4:
        digitalWriteFast(adrsPin0, 0);
        digitalWriteFast(adrsPin1, 0);
        digitalWriteFast(adrsPin2, 1);
        digitalWriteFast(adrsPin3, 0);
        break;
      case 5:
        digitalWriteFast(adrsPin0, 1);
        digitalWriteFast(adrsPin1, 0);
        digitalWriteFast(adrsPin2, 1);
        digitalWriteFast(adrsPin3, 0);
        break;
      case 6:
        digitalWriteFast(adrsPin0, 0);
        digitalWriteFast(adrsPin1, 1);
        digitalWriteFast(adrsPin2, 1);
        digitalWriteFast(adrsPin3, 0);
        break;
      case 7:
        digitalWriteFast(adrsPin0, 1);
        digitalWriteFast(adrsPin1, 1);
        digitalWriteFast(adrsPin2, 1);
        digitalWriteFast(adrsPin3, 0);
        break;
      case 8:
        digitalWriteFast(adrsPin0, 0);
        digitalWriteFast(adrsPin1, 0);
        digitalWriteFast(adrsPin2, 0);
        digitalWriteFast(adrsPin3, 1);
        break;
      case 9:
        digitalWriteFast(adrsPin0, 1);
        digitalWriteFast(adrsPin1, 0);
        digitalWriteFast(adrsPin2, 0);
        digitalWriteFast(adrsPin3, 1);
        break;
      case 10:
        digitalWriteFast(adrsPin0, 0);
        digitalWriteFast(adrsPin1, 1);
        digitalWriteFast(adrsPin2, 0);
        digitalWriteFast(adrsPin3, 1);
        break;
      case 11:
        digitalWriteFast(adrsPin0, 1);
        digitalWriteFast(adrsPin1, 1);
        digitalWriteFast(adrsPin2, 0);
        digitalWriteFast(adrsPin3, 1);
        break;
      case 12:
        digitalWriteFast(adrsPin0, 0);
        digitalWriteFast(adrsPin1, 0);
        digitalWriteFast(adrsPin2, 1);
        digitalWriteFast(adrsPin3, 1);
        break;
      case 13:
        digitalWriteFast(adrsPin0, 1);
        digitalWriteFast(adrsPin1, 0);
        digitalWriteFast(adrsPin2, 1);
        digitalWriteFast(adrsPin3, 1);
        break;
      case 14:
        digitalWriteFast(adrsPin0, 0);
        digitalWriteFast(adrsPin1, 1);
        digitalWriteFast(adrsPin2, 1);
        digitalWriteFast(adrsPin3, 1);
        break;
      case 15:
        digitalWriteFast(adrsPin0, 1);
        digitalWriteFast(adrsPin1, 1);
        digitalWriteFast(adrsPin2, 1);
        digitalWriteFast(adrsPin3, 1);
        break;
    }
  }
};
#endif
