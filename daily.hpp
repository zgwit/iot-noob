#pragma once

#include "define.hpp"


class TimeRange {
public:
	int start;
	int end;

	void Load(cJSON* json);

	bool Check(struct tm* t);
};

class DailyRange {
public:
	std::vector<TimeRange> times; //8:00 - 10:00
	std::vector<int> days; //0-6

	void Parse(cJSON* json);

	bool Check(struct tm* t);
};

