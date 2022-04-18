#ifndef DEBOUNCECLASS_H
#define DEBOUNCECLASS_H
#include <Arduino.h>

class Debounce
{
private:
    int _Pin;
    bool _StatusBefore;
    bool _Status;
    bool _debouncedStatus;
    bool _Unstable;
    bool _StayingButtonState;
    uint32_t _LastChange;
    uint32_t _DebounceTime;

    int _counter;

public:
    // Constructor
    Debounce(int Pin)
    {
        _StatusBefore = LOW;
        _Status = LOW;
        _Unstable = LOW;
        _StayingButtonState = LOW;
        _LastChange = 0;
        _DebounceTime = 25;
        _Pin = Pin;
        pinMode(_Pin, INPUT);
        _StatusBefore = _Status;
    }

    // Use
    void DebounceButton()
    {
        // It reads in the Button state
        _Status = digitalRead(_Pin);

        // It detects the rising flank
        if (_StatusBefore == 0 && _Status == 1)
        {
            if (_Unstable == false)
            {
                _Unstable = true;
                _StayingButtonState = !_StayingButtonState;
                _counter++;
                _debouncedStatus = true;
            }
            _LastChange = millis();
        }
        // The Status is save
        if (_StatusBefore == 1 && _Status == 1)
        {
            if (_DebounceTime <= (millis() - _LastChange))
            {
                _Unstable = false;
            }
        }
        // It detects the falling flank
        if (_StatusBefore == 1 && _Status == 0)
        {
            _LastChange = millis();
            if (_Unstable == false)
            {
                _Unstable = true;
            }
        }
        // The Status is save
        if (_StatusBefore == 0 && _Status == 0)
        {
            if (_DebounceTime <= (millis() - _LastChange))
            {
                _Unstable = false;
                _debouncedStatus = false;
            }
        }
        _StatusBefore = _Status;
    }



    // Get the current state of the Button
    int Get_State()
    {
        return _debouncedStatus;
    }

    // get the state that remains if you press the Button
    int Get_StayingState()
    {
        return _StayingButtonState;
    }

    // get a counter, how often you pressed the counter
    int Get_Counter()
    {
        return _counter;
    }

    // it sets the time, that it waits
    void Set_DebounceTime(uint32_t DebounceTime)
    {
        _DebounceTime = DebounceTime;
    }
    // it sets a value to the counter
    void Set_Counter(int counter)
    {
        _counter = counter;
    }
    // reset the counter, so that it starts again at 0
    void Reset_Counter()
    {
        _counter = 0;
    }
};
#endif