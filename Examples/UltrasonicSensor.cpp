#include <Arduino.h>
#include <UltrasonicSensor.h>

UltrasonicSensor Sensor = UltrasonicSensor(5, 8); // echoPin, triggerPin
long distance = 0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  distance = Sensor.Use_UltrasonicSensor();
  Serial.println(distance);
}