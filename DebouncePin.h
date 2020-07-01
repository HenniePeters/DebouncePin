#include <Arduino.h>

class DebouncePin {
public:
    DebouncePin( byte Pin, byte Mode ); // default DebounceTime 10ms     
    byte State(); 
    unsigned long Duration();    
    unsigned long Timer();                
private:
    byte OldSwitchState;
    byte SwitchPin;             
    unsigned long DebounceTime;         // 10 milliseconds initially, set in constructor    
    unsigned long SwitchPressTime;      // when the switch last changed state
    unsigned long PreviousPeriod;       // how long was the key pressed/released in the previous period
};
