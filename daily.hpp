#pragma once

#include "define.hpp"


class TimeRange {
public:
	int start;
	int end;

	void Parse(cJSON* json) {
		json_get_int(this, json, start);
		json_get_int(this, json, end);
	}

	bool Check(struct tm* t) {
		int min = t->tm_min + t->tm_hour * 60;
		if (start < end)
			return start <= min && min <= end;
		//¿çÌì
		return start >= min || min >= end;
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

	bool Check(struct tm* t) {
		for (auto &it : times) {
			if (!it.Check(t))
				return false;
		}
		if (days.size() == 0)
			return true;
		for (auto& it : days) {
			if (it == t->tm_wday)
				return true;
		}
		return false;
	}
};

