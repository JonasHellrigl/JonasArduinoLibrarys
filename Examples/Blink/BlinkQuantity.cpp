#include <Arduino.h>
#include <Blink.h>

Blink LED = Blink(5, 500, 250, 10); // Pin, DurationHigh, DurationLOW, QuantityBlinks
void setup()
{
}

void loop()
{
  LED.BlinkQuantity();
}