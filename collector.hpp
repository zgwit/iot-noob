#pragma once

#include "define.hpp"
#include "filter.hpp"
#include "calculator.hpp"




class CollectorProfile
{
public:
    bool enable;

    std::string type; // interal, crontab

    int interval; // seconds
    std::string crontab;

    int code;
    int address;
    int length;

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
