#pragma once

#include "define.hpp"
#include "condition.hpp"
#include "daily.hpp"
#include "cron.hpp"

class Alarm
{
public:
    bool enable = false;

    std::string message;
    int level = 0;

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

