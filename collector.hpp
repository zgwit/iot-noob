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

    //ÂË²¨Æ÷
    FilterProfile filter;

    //¼ÆËãÆ÷
    std::vector<CalculatorProfile> calculators;

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
