#pragma once

#include "define.hpp"
#include "condition.hpp"


class AlarmProfile
{
public:
    bool enable;

    std::string message;
    int level;
    
    ConditionProfile condition;

    std::vector<DailyRange> dailyRanges;
    WeekRange weekRange;

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

