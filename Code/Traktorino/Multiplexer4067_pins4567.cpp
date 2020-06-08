
#include <Arduino.h>
#include "Multiplexer4067_pins4567.h"
#include <digitalWriteFast.h>

Multiplexer4067_pins4567::Multiplexer4067_pins4567(const uint8_t sig) : _sig(sig){
  
}

void Multiplexer4067_pins4567::begin(uint8_t dir){
  pinModeFast(4, OUTPUT); 
  digitalWriteFast(4,LOW);
  pinModeFast(5, OUTPUT); 
  digitalWriteFast(5,LOW);
  pinModeFast(6, OUTPUT); 
  digitalWriteFast(6,LOW);
  pinModeFast(7, OUTPUT); 
  digitalWriteFast(7,LOW);

  if (dir != 1) { //out
    _dir = 0;
    pinMode(_sig, OUTPUT); 
  } else {
    _dir = 1;
  }
}

int Multiplexer4067_pins4567::readChannel(uint8_t ch, uint8_t readings){
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

void Multiplexer4067_pins4567::_addressing (uint8_t ch){
  switch(ch) {
      case 0:
        digitalWriteFast(4, 0);
        digitalWriteFast(5, 0);
        digitalWriteFast(6, 0);
        digitalWriteFast(7, 0);
        break;
      case 1:
        digitalWriteFast(4, 1);
        digitalWriteFast(5, 0);
        digitalWriteFast(6, 0);
        digitalWriteFast(7, 0);
        break;
      case 2:
        digitalWriteFast(4, 0);
        digitalWriteFast(5, 1);
        digitalWriteFast(6, 0);
        digitalWriteFast(7, 0);
        break;
      case 3:
        digitalWriteFast(4, 1);
        digitalWriteFast(5, 1);
        digitalWriteFast(6, 0);
        digitalWriteFast(7, 0);
        break;
      case 4:
        digitalWriteFast(4, 0);
        digitalWriteFast(5, 0);
        digitalWriteFast(6, 1);
        digitalWriteFast(7, 0);
        break;
      case 5:
        digitalWriteFast(4, 1);
        digitalWriteFast(5, 0);
        digitalWriteFast(6, 1);
        digitalWriteFast(7, 0);
        break;
      case 6:
        digitalWriteFast(4, 0);
        digitalWriteFast(5, 1);
        digitalWriteFast(6, 1);
        digitalWriteFast(7, 0);
        break;
      case 7:
        digitalWriteFast(4, 1);
        digitalWriteFast(5, 1);
        digitalWriteFast(6, 1);
        digitalWriteFast(7, 0);
        break;
      case 8:
        digitalWriteFast(4, 0);
        digitalWriteFast(5, 0);
        digitalWriteFast(6, 0);
        digitalWriteFast(7, 1);
        break;
      case 9:
        digitalWriteFast(4, 1);
        digitalWriteFast(5, 0);
        digitalWriteFast(6, 0);
        digitalWriteFast(7, 1);
        break;
      case 10:
        digitalWriteFast(4, 0);
        digitalWriteFast(5, 1);
        digitalWriteFast(6, 0);
        digitalWriteFast(7, 1);
        break;
      case 11:
        digitalWriteFast(4, 1);
        digitalWriteFast(5, 1);
        digitalWriteFast(6, 0);
        digitalWriteFast(7, 1);
        break;
      case 12:
        digitalWriteFast(4, 0);
        digitalWriteFast(5, 0);
        digitalWriteFast(6, 1);
        digitalWriteFast(7, 1);
        break;
      case 13:
        digitalWriteFast(4, 1);
        digitalWriteFast(5, 0);
        digitalWriteFast(6, 1);
        digitalWriteFast(7, 1);
        break;
      case 14:
        digitalWriteFast(4, 0);
        digitalWriteFast(5, 1);
        digitalWriteFast(6, 1);
        digitalWriteFast(7, 1);
        break;
      case 15:
        digitalWriteFast(4, 1);
        digitalWriteFast(5, 1);
        digitalWriteFast(6, 1);
        digitalWriteFast(7, 1);
        break;
    }
}
