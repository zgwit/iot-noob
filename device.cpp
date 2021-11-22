#include "device.hpp"

bool DeviceProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_string(this, json, name);
	json_get_string(this, json, label);
	json_get_int(this, json, slave);
	json_get_string(this, json, element);

	return true;
}


Device::Device(/* args */)
{
}

Device::~Device()
{
}
