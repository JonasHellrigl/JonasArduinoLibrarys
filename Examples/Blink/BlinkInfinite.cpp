#include <Arduino.h>
#include <Blink.h>

Blink LED = Blink(5, 250); // Pin, Interval

void setup()
{
}

void loop()
{
  LED.BlinkInfinite();
}