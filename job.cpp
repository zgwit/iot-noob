#include "job.hpp"
#include "application.hpp"
#include "device.hpp"

void Job::Load(cJSON* json, Application* app, Device* dev)
{
	if (!json) return;

	this->enable = json_get_bool(json, "enable");
	this->type = json_get_string(json, "type");
	this->clock = json_get_int(json, "clock");
	this->crontab = json_get_string(json, "crontab");

	auto items = json_get(json, "days");
	json_foreach(items, [&, this](cJSON* item) {
		//TODO json_is_number, or error
		this->days.push_back(item->valueint);
		});

	items = json_get(json, "invokes");
	json_foreach(items, [&, this](cJSON* item) {
		auto i = new Invoke();
		i->Load(item, app, dev);
		invokes.push_back(i);
		});
}


Job::Job(/* args */)
{
}

Job::~Job()
{
	//proto->commands.data();
	//Crontab.Cancel(job);
}

