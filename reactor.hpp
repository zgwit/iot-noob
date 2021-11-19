#pragma once

#include "define.hpp"
#include "compare.hpp"


class ReactorProfile
{
public:
    //std::string name;
    bool enable;

    std::vector<CompareProfile> compare;

    std::vector<RangeTime> times;
    RangeWeek weeks;

    unsigned int level;
    unsigned int timeout;
    unsigned int resetInterval;
    unsigned int resetTotal;

    std::vector<InvokeProfile> commands;

    bool Parse(cJSON* json);
};

class Reactor {
public:
    ReactorProfile* profile;


};

