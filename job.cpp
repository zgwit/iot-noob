#include "job.hpp"

bool JobProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_member_get_bool(this, json, enable);
	json_member_get_string(this, json, type);
	json_member_get_int(this, json, clock);
	json_member_get_int_array(this, json, days);
	json_member_get_string(this, json, crontab);
	json_get_object_array(this, json, invokes);

	return true;
}


Job::Job(/* args */)
{
}

Job::~Job()
{
	//proto->commands.data();
	//Cron.Cancel(job);
}

