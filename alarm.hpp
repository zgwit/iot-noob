#pragma once

#include "define.hpp"
#include "variable.hpp"


class Alarm : Proto
{
public:
    std::string name;
    std::string variable;
    bool enable;

    std::vector<RangeTime> times;
    RangeWeek weeks;

    unsigned int level;
    unsigned int timeout;
    unsigned int resetInterval;
    unsigned int resetTotal;

    bool Parse(JsonObject& obj);
};

class AlarmInstance
{
public:
    Alarm* proto;

    Variable *variablePtr;

    time_t start;
    bool reported;
    unsigned int resetTimes;

public:
    AlarmInstance(/* args */);
    ~AlarmInstance();
};

AlarmInstance::AlarmInstance(/* args */)
{
}

AlarmInstance::~AlarmInstance()
{
}
