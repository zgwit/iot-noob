#include "point.hpp"

Point::Point(/* args */)
{
}

Point::~Point()
{
}

void Point::Load(cJSON* json) {
	json_member_get_string(this, json, name);
	value = json_get_number(json, "default");
	const char* tp = json_get_string(json, "type");
	type = parseType(tp);

	json_member_get_int(this, json, interval);
	json_member_get_string(this, json, crontab);

	json_member_get_int(this, json, code);
	json_member_get_int(this, json, address);
	json_member_get_int(this, json, precision);

	json_member_get_bool(this, json, littleEndian);

	filter.Load(json_get(json, "filter"));
}

