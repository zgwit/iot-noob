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

    //�������
    if (!condition.Evaluate()) {
        delay.Reset();
        repeat.Reset();
        return;
    }

    //ʱ����
    if (!daily.Check(now)) {
        delay.Reset();
        repeat.Reset();
        return;
    }

    //��ʱ���
    if (!delay.Check(now)) {
        repeat.Reset();
        return;
    }

    //�ظ����
    if (!repeat.Check(now)) {
        return;
    }

    //TODO ִ������

}
