#include "DebouncePin.h"

class DebouncePin pin10( 10, INPUT_PULLUP ); // switch connected to GND  

void setup() {
    Serial.begin( 115200 );
}

void loop() {
    KeyHandler(); 
}

void KeyHandler( void ) {
    static unsigned long previous_millis = millis();
    static bool previous_pin_printed = pin10.State();
    if( previous_millis != millis() ) {
        previous_millis = millis();
        if( previous_pin_printed != pin10.State() ) {
            Serial.print(   "key changed from "   );
            Serial.print(   previous_pin_printed  );            
            previous_pin_printed = pin10.State();
            Serial.print(   " to "                );
            Serial.print(   previous_pin_printed  );
            Serial.print(   " after "             );
            Serial.print(   pin10.Duration()      );                        
            Serial.println( "ms"                  );
        }
    }   
}

/*
 * .State() returns the state of the key, LOW is connected to GND, HIGH is open.
 * .Duration() returns the time in millseconds between the last two edges.
 * .Timer() returns the value of a running timer in milliseconds since the last edge.
 * 
 */
