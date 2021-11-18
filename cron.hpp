#pragma once

#include "define.hpp"

extern "C" {
	#include "ccronexpr/ccronexpr.h"
}

typedef struct {
	cron_expr expr;
	time_t tick;
	void* callback;
}cron_item;

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
				//执行回调
				//it.callback();
			}
			it.tick = cron_next(&it.expr, now);
		}
		//按照时间排序
		//crons.sort([](cron_item& a, cron_item& b) {	return a.tick < b.tick;	});
	}

private:
	std::list<cron_item> crons;

};

Cron::Cron()
{
}

Cron::~Cron()
{
	//crons.front().expr;
	

}