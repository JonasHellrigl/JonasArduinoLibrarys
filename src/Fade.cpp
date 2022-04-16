#ifndef FADECLASS_H
#define FADECLASS_H
#include <Arduino.h>

class Fade
{
private:
    int _Pin;
    unsigned long _Interval;
    int _Brightness;
    uint32_t _LastFade;
    bool _Direction;

public:
    // Fade Constructor
    Fade(int Pin, unsigned long Interval)
    {
        _Pin = Pin;
        _Interval = Interval;
        _LastFade = millis();
        _Brightness = 0;
        _Direction = true;
        pinMode(_Pin, OUTPUT);
    }

    void Set_Interval(unsigned long Interval)
    {
        _Interval = Interval;
    }

    void FadeLED()
    {
        if (_Interval < millis() - _LastFade && _Direction == true)
        {
            _LastFade = millis();
            _Brightness = _Brightness + 15;
            if (_Brightness > 255)
            {
                _Brightness = 255;
            }
            analogWrite(_Pin, _Brightness);
        }
        if (_Interval < millis() - _LastFade && _Direction == false)
        {
            _LastFade = millis();
            _Brightness = _Brightness - 15;
            if (_Brightness < 0)
            {
                _Brightness = 0;
            }
            analogWrite(_Pin, _Brightness);
        }

        if (_Brightness >= 255 || _Brightness <= 0)
        {
            _Direction = !_Direction;
        }
    }
};
#endif