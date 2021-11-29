#pragma once

#include "define.hpp"


class TimeChecker {
public:
	int start;
	int end;

	void Load(cJSON* json);

	bool Check(struct tm* t);
};

class DailyChecker {
public:
	std::vector<TimeChecker> times; //8:00 - 10:00
	std::vector<int> days; //0-6

	void Load(cJSON* json);

	bool Check(time_t t);
};



class DelayChecker {
public:
    time_t start;
    int delay;

    void Load(cJSON* json);

    void Reset();

    bool Check(time_t now);
};

class RepeatChecker {
public:
    int interval;
    int total;

    bool raised;
    time_t last;

    int resetTimes;


    void Load(cJSON* json);

    void Reset();

    bool Check(time_t now);

};

