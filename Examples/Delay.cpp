#include <Arduino.h>
#include <Delay.h>

Delay delay1 = Delay();
void setup()
{
}

void loop()
{
  if (delay1.Use_Delay(500))
  {
    // Put in here the Code
  }
}
