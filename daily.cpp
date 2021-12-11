#include "daily.hpp"

void TimeChecker::Load(cJSON* json) {
    this->start = json_get_int(json, "start");
    this->end = json_get_int(json, "end");
}

bool TimeChecker::Check(tm* t) {
    int min = t->tm_min + t->tm_hour * 60;
    if (start < end)
        return start <= min && min <= end;
    //����
    return start >= min || min >= end;
}

void DailyChecker::Load(cJSON* json) {
    auto items = json_get(json, "times");
    json_array_foreach(items, item) {
        TimeChecker tr{};
        tr.Load(item);
        times.push_back(tr);
    }

    items = json_get(json, "days");
    json_array_foreach(items, item) {
        //TODO json_is_number, or error
        this->days.push_back(item->valueint);
    }
}

bool DailyChecker::Check(time_t t) {
    if (times.size() == 0 && days.size() == 0)
        return true;
    auto tm = localtime(&t); //�����ͷ�
    for (auto& it : times) {
        if (!it.Check(tm))
            return false;
    }
    for (auto& it : days) {
        if (it == tm->tm_wday)
            return true;
    }
    return (days.size() == 0);
}

void DelayChecker::Load(cJSON* json) {
    this->delay = json_get_int(json, "delay");
}

void DelayChecker::Reset() {
    start = 0;
}

bool DelayChecker::Check(time_t now) {
    if (delay <= 0)
        return true;

    if (start == 0) {
        start = now;
        return false;
    }
    return (start + delay < now);
}

void RepeatChecker::Load(cJSON* json) {
    this->interval = json_get_int(json, "interval");
    this->total = json_get_int(json, "total");
}

void RepeatChecker::Reset() {
    raised = false;
    resetTimes = 0;
}

bool RepeatChecker::Check(time_t now) {
    //����
    if (!raised) {
        raised = true;
        last = now;
        resetTimes = 0;

        return true;
    }

    //���ü��
    if (interval <= 0) {
        return false;
    }

    //������ô�������
    if (total > 0)
        if (resetTimes > total)
            return false;

    //�����û������ʱ�䣬������
    if (last + interval > now)
        return false;

    //����
    //start = now;
    last = now;
    resetTimes++;
    return true;
}
