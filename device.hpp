#pragma once

#include "define.hpp"

class DeviceDef: Define
{
public:
    std::string name;
    uint8_t slave;
    std::string element;

};



class Device
{
private:
    DeviceDef* def;


public:
    Device(/* args */);
    ~Device();
};

Device::Device(/* args */)
{
}

Device::~Device()
{
}
