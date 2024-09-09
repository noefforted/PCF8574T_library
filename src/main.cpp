#include <Arduino.h>
#include <PCF8574T.h>

PCF8574T pcf(0x20);

void setup()
{
  Serial.begin(9600);
  Wire.begin();
}

void loop()
{
  pcf.writePin(8, HIGH);
  Serial.println("Status pin 8: ");
  pcf.readPin(8) ? "HIDUP" : "MATI";
  delay(1000);
}