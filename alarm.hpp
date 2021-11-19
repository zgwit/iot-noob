#pragma once

#include "define.hpp"
#include "compare.hpp"


class AlarmProfile
{
public:
    bool enable;

    std::string name;
    unsigned int level;
    

    std::vector<CompareProfile> compares;

    std::vector<DailyRange> dailyRanges;
    WeekRange weekRange;

    unsigned int delay;

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

Alarm::Alarm(/* args */)
{
}

Alarm::~Alarm()
{
}
