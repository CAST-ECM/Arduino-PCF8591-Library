#ifndef PCF8591_H
#define PCF8591_H
#define control_base 0
#define endac_addr 0x40
class pcf8591
{
private:
  uint8_t i2caddr;
  uint8_t analogRead(uint8_t p);
  uint8_t control_byte=control_base;
public:
  void begin(uint8_t addr);
  uint8_t analogRead(uint8_t channel,int input_type);
  void analogWrite(uint8_t val);
};
#endif