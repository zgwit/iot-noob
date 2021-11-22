#include "collector.hpp"


bool CollectorProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_bool(this, json, enable);
	json_get_string(this, json, type);
	json_get_int(this, json, interval);
	json_get_string(this, json, crontab);
	json_get_int(this, json, code);
	json_get_int(this, json, address);
	json_get_int(this, json, length);
	json_get_object_array(this, json, calculators);

	return true;
}


Collector::Collector(/* args */)
{
}

Collector::~Collector()
{
}
