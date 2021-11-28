#pragma once

#include "define.hpp"
#include "condition.hpp"
#include "command.hpp"

class ReactorProfile
{
public:
    bool enable;

    ConditionProfile condition;

    std::vector<DailyRange> dailyRanges;
    WeekRange weekRange;

    int delay;

    StatusReset reset;

    std::vector<InvokeProfile> invokes;

    bool Parse(cJSON* json);
};


class Reactor {
public:
    ReactorProfile* profile;

    time_t start;
    bool reported;
    unsigned int resetTimes;
};

