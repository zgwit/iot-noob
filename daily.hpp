#pragma once

#include "define.hpp"


class TimeRange {
public:
	uint16_t start;
	uint16_t end;

	void Parse(cJSON* json) {
		json_get_int(this, json, start);
		json_get_int(this, json, end);
	}
};

class DailyRange {
public:
	std::vector<TimeRange> times; //8:00 - 10:00
	std::vector<int> days; //0-6

	void Parse(cJSON* json) {
		json_get_object_array(this, json, times);
		json_get_int_array(this, json, days);
	}
};

