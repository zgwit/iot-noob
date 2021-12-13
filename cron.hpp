#pragma once

#include "define.hpp"

extern "C" {
    #include "ccronexpr.h"
}


class CronJob{
public:
    cron_expr expr;
    time_t tick;
    std::function<void()> callback;
};

class Crontab
{
private:
    std::list<CronJob*> crons;

public:
    Crontab();
    ~Crontab();

    void loop();

    CronJob* Create(const char* crontab, std::function<void()> callback);

    void Cancel(CronJob* job);

};

extern Crontab Cron;
