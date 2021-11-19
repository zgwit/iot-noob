#pragma once

#include "define.hpp"

class CollectorProfile
{
public:
    bool enable;

    std::string type; // interal, crontab

    uint16_t interval; // seconds
    std::string crontab;

    uint8_t code;
    uint16_t address;
    uint16_t length;

    bool Parse(cJSON* json);
};



class Collector
{
private:
    CollectorProfile* profile;
    
public:
    Collector(/* args */);
    ~Collector();
};

Collector::Collector(/* args */)
{
}

Collector::~Collector()
{
}
