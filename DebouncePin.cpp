#include "DebouncePin.h"

DebouncePin::DebouncePin( byte Pin, byte Mode ) {
    DebounceTime = 10;
    SwitchPin = Pin;
    pinMode( Pin, Mode );
    if( Mode == INPUT_PULLUP ) {   
        OldSwitchState = HIGH;
    }
}

byte DebouncePin::State() {
    byte SwitchState = digitalRead( SwitchPin );            // see if switch is open or closed    
    if( SwitchState != OldSwitchState ) {                   // has it changed since last time?      
        if( millis()-SwitchPressTime >= DebounceTime ) {    // debounce
            PreviousPeriod = millis() - SwitchPressTime;
            SwitchPressTime = millis();                     // when we closed the switch 
            OldSwitchState =  SwitchState;                  // remember for next time   
        }                                                   // end if debounce time up  
    }                                                       // end of state change
    return OldSwitchState;
}

unsigned long DebouncePin::Duration() {                     // returns the duration of the period between the last two edges in milliseconds.
    return( PreviousPeriod );  
}

unsigned long DebouncePin::Timer() {                        // returns the number of milliseconds since the last edge
    return( millis() - SwitchPressTime );
}
