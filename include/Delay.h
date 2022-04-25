#ifndef DELAYCLASS_H
#define DELAYCLASS_H
#include <Arduino.h>

class Delay
{
private:
    unsigned long _lastChange;
    unsigned long _delay;
    bool _DelayPassed;

public:
    // Constructor
    Delay()
    {
        _delay = 0;
        _lastChange = millis();
        _DelayPassed = false;
    }

    bool Use_Delay(unsigned long delay)
    {
        _delay = delay;
        if (_delay < millis() - _lastChange)
        {
            _lastChange = millis();
            _DelayPassed = true;
        }
        else
        {
            _DelayPassed = false;
        }
        return _DelayPassed;
    }

    void Set_Delay(unsigned long delay)
    {
        _delay = delay;
    }
};
#endif
