#pragma once

#include "define.hpp"

extern "C" {
	#include "ccronexpr/ccronexpr.h"
}


class CronJob{
public:
	cron_expr expr;
	time_t tick;
	std::function<void()> callback;
};

class Cron
{
private:
	std::list<CronJob*> crons;

public:
	Cron();
	~Cron();

	void loop();

	CronJob* Create(const char* crontab, std::function<void()> callback);

	void Cancel(CronJob* job);

};

//Cron cron;
