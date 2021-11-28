#include "alarm.hpp"

bool AlarmProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_bool(this, json, enable);
	json_get_string(this, json, message);
	json_get_int(this, json, level);
	json_get_object(this, json, condition);
	json_get_object(this, json, range);
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
