#pragma once

#include "define.hpp"
#include "element.hpp"
#include "context.hpp"

class DeviceProfile
{
public:
    bool enable;

    std::string name;
    uint8_t slave;
    std::string element;

    bool Parse(cJSON* json);
};



class Device
{
private:
    DeviceProfile* profile;
    ElementProfile* element;

    //TODO 上下文，采集器，定时器 等
    Context context;
    std::map<std::string, Command*> commands;



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
