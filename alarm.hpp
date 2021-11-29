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
        //TODO ��Ҫ�ͷ�

        //���ʱ������
        if (!profile->range.Check(now_tm)) {
            start = 0;
            reported = false;
            resetTimes = 0;
            return;
        }

        //�������
        bool cond = condition->Evaluate();
        if (!cond) {
            start = 0;
            reported = false;
            resetTimes = 0;
            return;
        }

        //��ʱ
        if (profile->delay > 0) {
            if (!start) {
                start = now;
                return;
            }
            if (start + profile->delay > now)
                return;
        }

        //�Ѿ��ϱ��������ϱ�
        if (reported) {
            //�����߼�
            if (profile->reset.interval > 0) {
                //������ô�������
                if (profile->reset.total > 0)
                    if (resetTimes > profile->reset.total)
                        return;

                //�����û������ʱ�䣬������
                if (reportAt + profile->reset.interval > now)
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

        //TODO �����������ϱ�

    }
};

