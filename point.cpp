#include "point.hpp"

bool PointProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_member_get_string(this, json, name);
	json_member_get_string(this, json, label);
	json_member_get_string(this, json, unit);
	json_member_get_number(this, json, value);
	json_member_get_string(this, json, type);
	json_member_get_string(this, json, crontab);
	json_member_get_int(this, json, interval);
	json_member_get_int(this, json, code);
	json_member_get_int(this, json, address);
	json_member_get_int(this, json, precision);
	json_member_get_int(this, json, littleEndian);
	json_member_get_int(this, json, readable);
	json_member_get_int(this, json, writable);

	return true;
}


Point::Point(/* args */)
{
}

Point::~Point()
{
}

