#pragma once

#include "define.hpp"
#include "compare.hpp"


class AlarmProfile
{
public:
    std::string name;
    std::string content;
    
    bool enable;

    std::vector<CompareProfile> compare;

    std::vector<RangeTime> times;
    RangeWeek weeks;

    unsigned int level;
    unsigned int timeout;
    unsigned int resetInterval;
    unsigned int resetTotal;

    bool Parse(cJSON* json);
};


class Alarm
{
public:
    Alarm* proto;

    Variable *variablePtr;

    time_t start;
    bool reported;
    unsigned int resetTimes;

public:
    Alarm(/* args */);
    ~Alarm();
};

Alarm::Alarm(/* args */)
{
}

Alarm::~Alarm()
{
}
