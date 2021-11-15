#pragma once

#include "define.hpp"

class AlarmDef : Define
{
public:
    std::string name;
    unsigned int level;
    std::string variable;

    unsigned int timeout;
    unsigned int resetInterval;
    unsigned int resetTotal;

    bool Parse(JsonDocument &doc);
};

class Alarm
{
public:
    AlarmDef* def;

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
