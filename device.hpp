#pragma once

#include "define.hpp"
#include "element.hpp"

class Device: Proto
{
public:
    std::string name;
    uint8_t slave;
    std::string element;

};



class DeviceInstance
{
private:
    Device* proto;
    Element* element;

    //TODO 上下文，采集器，定时器 等


public:
    DeviceInstance(/* args */);
    ~DeviceInstance();
};

DeviceInstance::DeviceInstance(/* args */)
{
}

DeviceInstance::~DeviceInstance()
{
}
