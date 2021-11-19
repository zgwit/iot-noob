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
public:
	Cron();
	~Cron();

	void loop() {
		time_t now = time(nullptr);
		for (auto it : crons) {
			if (it.tick < now) {
				it.expr;
				//ִ�лص�
				it.callback();
			}
			it.tick = cron_next(&it.expr, now);
		}

		//����ʱ������
		//crons.sort([](cron_item& a, cron_item& b) {	return a.tick < b.tick;	});
	}

	CronJob* Create(const char* crontab, std::function<void()> callback) {
		//CronJob
		crons.push_back()
	}

	bool Cancel(CronJob& job) {
		crons.remove(job);
	}

private:
	std::list<CronJob> crons;

};

Cron Cron;

Cron::Cron()
{
}

Cron::~Cron()
{
	//crons.front().expr;
	

}