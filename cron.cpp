#include "cron.hpp"

Cron::Cron()
{
}

Cron::~Cron()
{
	for (auto& it : crons)delete it;

}

void Cron::loop() {
	time_t now = time(nullptr);
	for (auto& it : crons) {
		if (it->tick < now) {
			it->expr;
			//ִ�лص�
			it->callback();
		}
		it->tick = cron_next(&it->expr, now);
	}

	//����ʱ������
	//crons.sort([](cron_item& a, cron_item& b) {	return a.tick < b.tick;	});
}

CronJob* Cron::Create(const char* crontab, std::function<void()> callback) {
	//CronJob
	//crons.push_back()
	auto job = new CronJob();
	const char* error = nullptr;
	cron_parse_expr(crontab, &job->expr, &error);
	if (error) {
		delete job;
		return nullptr;
	}

	job->callback = callback;
	crons.push_back(job);

	return job;
}

void Cron::Cancel(CronJob* job) {
	crons.remove(job);
	delete job;
}
