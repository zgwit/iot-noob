#pragma once

#include "define.hpp"
#include "condition.hpp"
#include "daily.hpp"


class AlarmProfile
{
public:
    bool enable;

    std::string message;
    int level;

    
    ConditionProfile condition;

    DailyRange range;

    int delay;

    StatusReset reset;

    bool Parse(cJSON* json);
};


class Alarm
{
public:
    AlarmProfile* profile;

    time_t start;
    bool reported;
    unsigned int resetTimes;

public:
    Alarm(/* args */);
    ~Alarm();
};

