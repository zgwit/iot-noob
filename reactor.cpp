#include "reactor.hpp"

bool ReactorProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_bool(this, json, enable);
	json_get_object(this, json, condition);
	json_get_object(this, json, range);
	json_get_int(this, json, delay);
	json_get_object(this, json, reset);
	json_get_object_array(this, json, invokes);

	return true;
}
