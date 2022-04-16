#include <Arduino.h>
#include <Debounce.h>

Debounce Button = Debounce(8); // Pin
void setup()
{
}

void loop()
{
  Button.DebounceButton();

  // It depends on what, you want to do:
  //// Button.Get_Counter();
  //// Button.Get_State();
  //// Button.Get_StayingState();
}