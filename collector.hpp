#pragma once

#include "define.hpp"

class Collector: Proto
{
public:
    std::string type;
    std::string crontab;
    uint16_t interval;

    uint8_t code;
    uint16_t address;
    uint16_t length;


    bool Parse(JsonObject& obj);
};



class CollectorInstance
{
private:
    Collector* proto;
    
public:
    CollectorInstance(/* args */);
    ~CollectorInstance();
};

CollectorInstance::CollectorInstance(/* args */)
{
}

CollectorInstance::~CollectorInstance()
{
}
