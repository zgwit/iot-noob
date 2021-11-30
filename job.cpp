#include "job.hpp"
#include "app.hpp"
#include "device.hpp"

void Job::Load(cJSON* json, App* app, Device* dev)
{
	if (!json) return;

	json_member_get_bool(this, json, enable);
	json_member_get_string(this, json, type);
	json_member_get_int(this, json, clock);
	json_member_get_int_array(this, json, days);
	json_member_get_string(this, json, crontab);
	//json_get_object_array(this, json, invokes);
	json_array_foreach(json_get(json, "invokes"), item) {
		auto i = new Invoke();
		i->Load(item, app, dev);
		invokes.push_back(i);
	}
}


Job::Job(/* args */)
{
}

Job::~Job()
{
	//proto->commands.data();
	//Cron.Cancel(job);
}

