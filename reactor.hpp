#pragma once

#include "define.hpp"
#include "condition.hpp"
#include "command.hpp"
#include "daily.hpp"
#include "cron.hpp"

class Reactor
{
public:
    bool enable;

    Condition condition;

    DailyRange range;

    int delay;

    StatusReset reset;

    std::vector<Invoke> invokes;


    time_t start;
    bool reported;
    time_t reportAt;
    unsigned int resetTimes;

public:
    Alarm();
    ~Alarm();

    void Enable(bool enable = false){}

    void Load(cJSON* json, const Context& ctx);
    void Execute();
};

