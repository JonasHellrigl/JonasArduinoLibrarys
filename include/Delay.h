#ifndef DELAYCLASS_H
#define DELAYCLASS_H
#include <Arduino.h>

class Delay
{
private:
    unsigned long _lastChange;
    unsigned long _interval;
    bool _DelayPassed;

public:
    // Constructor
    Delay(unsigned long interval)
    {
        _interval = interval;
        _lastChange = millis();
        _DelayPassed = false;
    }

    bool Use_Delay()
    {
        if (_interval < millis() - _lastChange)
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
        _interval = delay;
    }
};
#endif