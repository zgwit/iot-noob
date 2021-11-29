#include "daily.hpp"

void TimeRange::Load(cJSON* json) {
	json_member_get_int(this, json, start);
	json_member_get_int(this, json, end);
}

bool TimeRange::Check(tm* t) {
	int min = t->tm_min + t->tm_hour * 60;
	if (start < end)
		return start <= min && min <= end;
	//¿çÌì
	return start >= min || min >= end;
}

void DailyRange::Parse(cJSON* json) {
	//json_member_get_object_array(this, json, times);
	json_array_foreach(json_get(json, "times"), item) {
		TimeRange tr{};
		tr.Load(item);
		times.push_back(tr);
	}

	json_member_get_int_array(this, json, days);
}

bool DailyRange::Check(tm* t) {
	for (auto& it : times) {
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
