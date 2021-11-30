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

    DailyChecker daily;
    DelayChecker delay;
    RepeatChecker repeat;

public:
    Alarm();
    ~Alarm();

    void Enable(bool enable = false){}
    void Start() {}
    void Stop() {}

    void Load(cJSON* json, Context& ctx);
    void Execute();
};

