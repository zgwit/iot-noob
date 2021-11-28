#include "device.hpp"

bool DeviceProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_bool(this, json, enable);

	json_get_string(this, json, name);
	json_get_string_array(this, json, tags);

	json_get_string(this, json, label);
	json_get_string(this, json, element);

	json_get_int(this, json, slave);

	json_get_object_array(this, json, variables);
	json_get_object_array(this, json, points);
	json_get_object_array(this, json, collectors);
	json_get_object_array(this, json, calculators);
	json_get_object_array(this, json, commands);
	json_get_object_array(this, json, alarms);
	json_get_object_array(this, json, jobs);

	return true;
}


Device::Device(/* args */)
{
}

Device::~Device()
{
}
