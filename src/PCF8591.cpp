#include <Wire.h>
#include "PCF8591.h"
void pcf8591::begin(uint8_t addr)
{
	Wire.begin();
	i2caddr=addr;
}

void pcf8591::analogWrite(uint8_t val)
{
	control_byte=control_byte|endac_addr;
    Wire.beginTransmission(i2caddr);
	Wire.write(control_byte);
	Wire.write(val);
	Wire.endTransmission();
}

uint8_t pcf8591::analogRead(uint8_t channel,int input_type)
{
   uint8_t adc_buff;
   control_byte=control_byte&0xCF;
   control_byte=control_byte|(input_type*0x10);
   control_byte=control_byte&0xFC;
   control_byte=control_byte|channel;
   Wire.beginTransmission(i2caddr);
   Wire.write(control_byte);
   Wire.endTransmission();
   Wire.requestFrom(i2caddr,uint8_t(1));
   while (Wire.available()) 
   {
       adc_buff=Wire.read();
   };
   return adc_buff;
}