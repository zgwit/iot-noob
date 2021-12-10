#include "alarm.hpp"


Alarm::Alarm(): enable(0), level(0), condition(), daily(), delay(), repeat()
{
}

Alarm::~Alarm()
{
    //condition;
}

void Alarm::Load(cJSON* json, Context& ctx) {
    enable = json_get_bool(json, "enable");
    message = json_get_string(json, "message");
    level = json_get_int(json, "level");
    condition.Load(json_get(json, "condition"), ctx);
    daily.Load(json_get(json, "daily"));
    delay.Load(json); //delay
    repeat.Load(json_get(json, "repeat"));
}

void Alarm::Execute() {
    time_t now = time(NULL);

    //条件检查
    if (!condition.Evaluate()) {
        delay.Reset();
        repeat.Reset();
        return;
    }

    //时间检查
    if (!daily.Check(now)) {
        delay.Reset();
        repeat.Reset();
        return;
    }

    //延时检查
    if (!delay.Check(now)) {
        repeat.Reset();
        return;
    }

    //重复检查
    if (!repeat.Check(now)) {
        return;
    }

    //TODO 产生报警，上报

}
