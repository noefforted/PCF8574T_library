#include <PCF8574T.h>

PCF8574T::PCF8574T(uint8_t address)
{
    _address = address;
    _dataState = 0xFF;
}

void PCF8574T::begin()
{
    Wire.begin();
    writeAll(_dataState);
}

void PCF8574T::writeAll(bool state)
{
    _dataState = state;
    Wire.beginTransmission(_address);
    Wire.write(_dataState);
    Wire.endTransmission();
}

uint8_t PCF8574T::readAll()
{
    Wire.requestFrom(_address, (uint8_t)1);
    if (Wire.available())
    {
        _dataState = Wire.read();
        return _dataState;
    }
    return 0xFF;
}

void PCF8574T::writePin(uint8_t pin, bool state)
{
    if (state)
    {
        _dataState |= (1 << pin);
    }
    else
    {
        _dataState &= ~(1 << pin);
    }
    writeAll(_dataState);
}

bool PCF8574T::readPin(uint8_t pin)
{
    return (_dataState & (1 << pin)) != 0;
}