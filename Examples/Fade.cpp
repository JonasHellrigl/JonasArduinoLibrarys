#include <Arduino.h>
#include <Fade.h>

Fade LED = Fade(5, 100); // Pin, Interval

void setup()
{
}

void loop()
{
  LED.FadeLED();
}