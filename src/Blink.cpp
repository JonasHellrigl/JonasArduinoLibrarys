#ifndef BLINKCLASS_H
#define BLINKCLASS_H
#include <Arduino.h>

class Blink
{
private:
    int _pin;
    bool _statusLED;
    unsigned long _lastToggle;
    unsigned long _interval;
    int _quantityBlink;
    int _lastQuantityBlink;
    unsigned long _durationHIGH;
    unsigned long _durationLOW;

public:
    // Infinite Blink Constructor:
    Blink(int pin, unsigned long interval)
    {
        _interval = interval;
        _statusLED = false;
        _pin = pin;
        _lastToggle = millis();
        pinMode(_pin, OUTPUT);
    }

    void Set_IntervalInfinite(unsigned long interval)
    {
        _interval = interval;
    }

    // it blinks in a infinite loop
    void BlinkInfinite()
    {
        if (_interval < millis() - _lastToggle)
        {
            _lastToggle = millis();
            _statusLED = !_statusLED;
            digitalWrite(_pin, _statusLED);
        }
    }

    //------------------------------------------------------------------------------------

    // Blink with Quantity of flashes and duration Constructor:
    Blink(int pin, unsigned long durationHIGH, unsigned long durationLOW, int quantityBlink)
    {
        _durationHIGH = durationHIGH;
        _durationLOW = durationLOW;
        _statusLED = false;
        _pin = pin;
        _lastToggle = millis();
        _quantityBlink = quantityBlink;
        _lastQuantityBlink = _quantityBlink;
        pinMode(_pin, OUTPUT);
    }

    // It sets a new quantity of Blinking
    void Set_QuantityBlink(int quantityBlink)
    {
        _quantityBlink = quantityBlink;
    }

    // it flashes n times and then stops
    void BlinkQuantity()
    {
        if (_quantityBlink > 0)
        {
            if (_durationHIGH < millis() - _lastToggle && _statusLED == true)
            {
                _lastToggle = millis();
                _statusLED = !_statusLED;
                digitalWrite(_pin, _statusLED);
                _quantityBlink--;
            }

            if (_durationLOW < millis() - _lastToggle && _statusLED == false)
            {
                _lastToggle = millis();
                _statusLED = !_statusLED;
                digitalWrite(_pin, _statusLED);
            }
        }
        //it contols, that the LED is low at the end
        if (_quantityBlink == 0 && _statusLED == true)
        {
            _statusLED = false;
            digitalWrite(_pin, _statusLED);
        }
    }
};
#endif