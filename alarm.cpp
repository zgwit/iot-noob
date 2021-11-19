#include "alarm.hpp"

bool AlarmProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_bool(this, json, enable);
	json_get_string(this, json, name);
	json_get_int(this, json, level);

	auto _compares = json_get(json, compares);
	if (json_is_array(_compares)) {
		compares.resize(json_array_size(_compares));
		auto iter = compares.begin();
		json_array_foreach(_compares, cmp) {
			iter->Parse(cmp);
			iter++;
		}
	}
	else {
		//error
	}

	auto _ranges = json_get(json, dailyRanges);
	if (json_is_array(_ranges)) {
		dailyRanges.resize(json_array_size(_ranges));
		auto iter = dailyRanges.begin();
		json_array_foreach(_ranges, r) {
			iter->Parse(r);
			iter++;
		}
	}
	else {
		//error
	}

	json_get_int(this, json, weekRange);
	json_get_int(this, json, delay);

	auto _reset = json_get(json, reset);
	if (json_is_object(_reset)) {
		reset.Parse(_reset);
	}

	return true;
}
