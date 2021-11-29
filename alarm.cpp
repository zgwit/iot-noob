#include "alarm.hpp"


Alarm::Alarm()
{

}

Alarm::~Alarm()
{
	//condition;
}

void Alarm::Load(cJSON* json, const Context& ctx) {
    enable = json_get_bool(json, "enable");
    message = json_get_string(json, "message");
    level = json_get_int(json, "level");
    condition.Load(json_get(json, "condition"), ctx);
    range.Parse(json_get(json, "range"));
    delay = json_get_int(json, "delay");
    reset.Parse(json_get(json, "reset"));

}

void Alarm::Execute() {
    time_t now = time(NULL);
    auto now_tm = localtime(&now);
    //TODO 需要释放

    //检测时间限制
    if (!range.Check(now_tm)) {
        start = 0;
        reported = false;
        resetTimes = 0;
        return;
    }

    //检查条件
    bool cond = condition.Evaluate();
    if (!cond) {
        start = 0;
        reported = false;
        resetTimes = 0;
        return;
    }

    //延时
    if (delay > 0) {
        if (!start) {
            start = now;
            return;
        }
        if (start + delay > now)
            return;
    }

    //已经上报，则不再上报
    if (reported) {
        //重置逻辑
        if (reset.interval > 0) {
            //最大重置次数限制
            if (reset.total > 0)
                if (resetTimes > reset.total)
                    return;

            //如果还没到重置时间，则不提醒
            if (reportAt + reset.interval > now)
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
