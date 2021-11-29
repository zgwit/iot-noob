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
    Condition* condition;


    time_t start;
    bool reported;
    time_t reportAt;
    unsigned int resetTimes;

public:
    Alarm(AlarmProfile* profile, const Context& ctx);
    ~Alarm();

    void Enable(bool enable = false){}
    void Start() {}
    void Stop() {}

    void Execute() {
        time_t now = time(NULL);
        auto now_tm = localtime(&now);
        //TODO 需要释放

        //检测时间限制
        if (!profile->range.Check(now_tm)) {
            start = 0;
            reported = false;
            resetTimes = 0;
            return;
        }

        //检查条件
        bool cond = condition->Evaluate();
        if (!cond) {
            start = 0;
            reported = false;
            resetTimes = 0;
            return;
        }

        //延时
        if (profile->delay > 0) {
            if (!start) {
                start = now;
                return;
            }
            if (start + profile->delay > now)
                return;
        }

        //已经上报，则不再上报
        if (reported) {
            //重置逻辑
            if (profile->reset.interval > 0) {
                //最大重置次数限制
                if (profile->reset.total > 0)
                    if (resetTimes > profile->reset.total)
                        return;

                //如果还没到重置时间，则不提醒
                if (reportAt + profile->reset.interval > now)
                    return;

                //重置
                start = now;
                resetTimes++;
                return; //下次再执行，因为可能会有delay
            }
            return;
        }

        reported = true;
        reportAt = now;

        //TODO 产生报警，上报

    }
};

