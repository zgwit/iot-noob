#include "point.hpp"

bool PointProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_string(this, json, name);
	json_get_string(this, json, label);
	json_get_string(this, json, unit);
	json_get_number(this, json, value);
	json_get_string(this, json, type);
	json_get_string(this, json, crontab);
	json_get_int(this, json, interval);
	json_get_int(this, json, code);
	json_get_int(this, json, address);
	json_get_int(this, json, precision);
	json_get_int(this, json, littleEndian);
	json_get_int(this, json, readable);
	json_get_int(this, json, writable);

	return true;
}


Point::Point(/* args */)
{
}

Point::~Point()
{
}

