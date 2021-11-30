#include "reactor.hpp"


Reactor::Reactor()
{

}

Reactor::~Reactor()
{
	//condition;
}

void Reactor::Load(cJSON* json, Context& ctx) {
    enable = json_get_bool(json, "enable");
    condition.Load(json_get(json, "condition"), ctx);
    daily.Load(json_get(json, "daily"));
    delay.Load(json); //delay
    repeat.Load(json_get(json, "repeat"));
}

void Reactor::Execute() {
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

    //TODO 执行命令

}
