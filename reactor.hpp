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

    DailyChecker daily;
    DelayChecker delay;
    RepeatChecker repeat;
    std::vector<Invoke> invokes;

public:
    Alarm();
    ~Alarm();

    void Enable(bool enable = false){}

    void Load(cJSON* json, const Context& ctx);
    void Execute();
};

