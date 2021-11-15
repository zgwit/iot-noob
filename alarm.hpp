#pragma once
#include <string>
#include <stdint.h>
#include "define.hpp"

class AlarmDefine : Define
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
    AlarmDefine *define;

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
