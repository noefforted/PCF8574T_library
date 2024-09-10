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
  for(int i = 2; i >= 0 ; i--){
  pcf.writePin(i, HIGH);
  Serial.print("Status pin ");
  Serial.print(i);
  Serial.println(pcf.readPin(i) ? " HIDUP" : " MATI");
  delay(200);
  pcf.writePin(i, LOW);
  Serial.print("Status pin ");
  Serial.print(i);
  Serial.println(pcf.readPin(i) ? " HIDUP" : " MATI");
  delay(200);
  }
  // pcf.writePin(2, HIGH);
  // delay(1000);
  // pcf.writePin(2, LOW);
  // delay(1000);
  // pcf.writeAll(0xFF);
  // delay(500);
  // pcf.writeAll(0x00);
  // delay(500);
}