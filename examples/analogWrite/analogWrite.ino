#include "PCF8591.h"
pcf8591 pcf1;
void setup() {
  pcf1.begin(0x48);
}

void loop() {
int i=0;
  for (i=0;i<=255;i++)
  {
    pcf1.analogWrite(i);//max:255
    delay(1);
  }
}
