#include "alarm.hpp"

bool AlarmProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_bool(this, json, enable);
	json_get_string(this, json, label);
	json_get_int(this, json, level);
	json_get_object_array(this, json, compares);
	json_get_object_array(this, json, dailyRanges);
	json_get_int(this, json, weekRange);
	json_get_int(this, json, delay);
	json_get_object(this, json, reset);

	return true;
}

Alarm::Alarm(/* args */)
{
}

Alarm::~Alarm()
{
}
