#include "PCF8591.h"
pcf8591 pcf1;
void setup() {
  pcf1.begin(0x48);
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = pcf1.analogRead(0,0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
