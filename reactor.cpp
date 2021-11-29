#include "reactor.hpp"


Reactor::Reactor()
{

}

Reactor::~Reactor()
{
	//condition;
}

void Reactor::Load(cJSON* json, const Context& ctx) {
    enable = json_get_bool(json, "enable");
    condition.Load(json_get(json, "condition"), ctx);
    range.Parse(json_get(json, "range"));
    delay = json_get_int(json, "delay");
    reset.Parse(json_get(json, "reset"));

}

void Reactor::Execute() {
    time_t now = time(NULL);
    auto now_tm = localtime(&now);
    //TODO ��Ҫ�ͷ�

    //���ʱ������
    if (!range.Check(now_tm)) {
        start = 0;
        reported = false;
        resetTimes = 0;
        return;
    }

    //�������
    bool cond = condition.Evaluate();
    if (!cond) {
        start = 0;
        reported = false;
        resetTimes = 0;
        return;
    }

    //��ʱ
    if (delay > 0) {
        if (!start) {
            start = now;
            return;
        }
        if (start + delay > now)
            return;
    }

    //�Ѿ��ϱ��������ϱ�
    if (reported) {
        //�����߼�
        if (reset.interval > 0) {
            //������ô�������
            if (reset.total > 0)
                if (resetTimes > reset.total)
                    return;

            //�����û������ʱ�䣬������
            if (reportAt + reset.interval > now)
                return;

            //����
            start = now;
            resetTimes++;
            return; //�´���ִ�У���Ϊ���ܻ���delay
        }
        return;
    }

    reported = true;
    reportAt = now;

    //TODO ִ������

}
