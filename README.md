# DebouncePin

A class to debounce pins of your arduino

Initialise for each pin you want to debounce
  #include "DebouncePin.h"
  class DebouncePin pin10( 10, INPUT_PULLUP ); // switch connects to GND, initial state HIGH. 
  class DebouncePin pin11( 11, INPUT );        // initial state unknown, call pin11.State() in setup(). 

The class includes 3 methods: 

 .State() returns the state of the key, LOW is connected to GND, HIGH is connected to VCC.
 
 .Duration() returns the time in milliseconds between the last two edges.
 
 .Timer() returns the value of a running timer in milliseconds since the last edge.
