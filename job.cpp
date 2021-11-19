#include "job.hpp"

bool JobProfile::Parse(cJSON* json)
{
	if (!json)
		return false;

	json_get_bool(this, json, enable);
	json_get_string(this, json, type);
	json_get_int(this, json, daily);
	json_get_int(this, json, weekRange);
	json_get_string(this, json, crontab);
	json_get_object_array(this, json, commands);

	return true;
}
