#pragma once

#include "define.hpp"

class Alarm : Proto
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
    ~Alarm();
};

AlarmInstance::AlarmInstance(/* args */)
{
}

AlarmInstance::~AlarmInstance()
{
}
