#ifndef ULTRASONICCLASS_H
#define ULTRASONICCLASS_H
#include <Arduino.h>

class UltrasonicSensor
{
private:

    class Delay
    {
    private:
        unsigned long _lastChange;
        unsigned long _interval;
        bool _DelayPassed;

    public:
        Delay()
        {
            _lastChange = millis();
            _DelayPassed = false;
        }

        bool Use_Delay(unsigned long interval)
        {
            _interval = interval;
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
    };

    int _triggerPin;
    int _echoPin;
    long _time;
    long _distance;
    Delay _delay1 = Delay();
    Delay _delay2 = Delay();
    Delay _delay3 = Delay();

public:
    UltrasonicSensor(int echoPin, int triggerPin)
    {
        _echoPin = echoPin;
        _triggerPin = triggerPin;
        _time = 0;
        _distance = 0;

        pinMode(triggerPin, OUTPUT);
        pinMode(echoPin, INPUT);
    }

    long Use_UltrasonicSensor()
    {
        if (_delay1.Use_Delay(100))
        {
            digitalWrite(_triggerPin, LOW);
            if (_delay2.Use_Delay(5))
            {
                digitalWrite(_triggerPin, HIGH);
            }
            if (_delay3.Use_Delay(10))
            {
                digitalWrite(_triggerPin, LOW);
            }

            _time = pulseIn(_echoPin, HIGH);
            _distance = (_time / 2) * 0.03432;
        }
        
        return _distance;
    }
};
#endif