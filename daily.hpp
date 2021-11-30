#pragma once

#include "define.hpp"


class TimeChecker {
public:
	int start = 0;
	int end = 0;

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
    time_t start = 0;
    int delay = 0;

    void Load(cJSON* json);

    void Reset();

    bool Check(time_t now);
};

class RepeatChecker {
public:
    int interval = 0;
    int total = 0;

    bool raised = false;
    time_t last = 0;

    int resetTimes = 0;


    void Load(cJSON* json);

    void Reset();

    bool Check(time_t now);

};

