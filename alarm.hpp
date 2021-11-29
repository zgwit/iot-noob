#pragma once

#include "define.hpp"
#include "condition.hpp"
#include "daily.hpp"
#include "cron.hpp"

class Alarm
{
public:
    bool enable;

    std::string message;
    int level;

    Condition condition;

    DailyRange range;

    int delay;

    StatusReset reset;

    time_t start;
    bool reported;
    time_t reportAt;
    unsigned int resetTimes;

public:
    Alarm();
    ~Alarm();

    void Enable(bool enable = false){}
    void Start() {}
    void Stop() {}

    void Load(cJSON* json, const Context& ctx);
    void Execute();
};

