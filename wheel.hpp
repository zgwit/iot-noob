#pragma once

#include "define.hpp"

class Pace
{
public:
	int milliseconds;
	std::function<void()> callback;
	bool once;
	time_t nextTick;

	Pace(int ms, std::function<void()> fn, bool once=false): milliseconds(ms), callback(fn), once(once) {
		nextTick = time(NULL);
	}
};


class WaterWheel
{
public:
	~WaterWheel();

	std::list<Pace*> items;


	Pace* once(int ms, std::function<void()> fn);

	Pace* attach(int ms, std::function<void()> fn);

	void detach(Pace* item);

	void loop();

private:

};

extern WaterWheel Wheel;