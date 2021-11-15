#pragma once

#include "define.hpp"

class CollectorDefine: Define
{
public:
    std::string type;
    std::string crontab;
    uint16_t interval;

    uint8_t code;
    uint16_t address;
    uint16_t length;


    bool Parse(JsonDocument &doc);
};



class Collector
{
private:
    CollectorDefine* define;
    
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
