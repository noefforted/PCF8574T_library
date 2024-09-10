#ifndef PCF8574T_H
#define PCF8574T_H

#include <Arduino.h>
#include <Wire.h>

class PCF8574T
{
public:
    PCF8574T(uint8_t address);
    void begin();
    void writeAll(uint8_t state);
    uint8_t readAll();
    void writePin(uint8_t pin, bool state);
    bool readPin(uint8_t pin);

private:
    uint8_t _address;
    uint8_t _dataState;
};

#endif