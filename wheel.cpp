#include "wheel.hpp"

WaterWheel Wheel;

WaterWheel::~WaterWheel() {
	for (auto item : items) delete item;
}

Pace* WaterWheel::once(int ms, std::function<void()> fn) {
	auto item = new Pace(ms, fn, true);
	items.push_back(item);
	return item;
}

Pace* WaterWheel::attach(int ms, std::function<void()> fn) {
	auto item = new Pace(ms, fn);
	items.push_back(item);
	return item;
}

void WaterWheel::detach(Pace* item) {
	items.remove(item);
	delete item;
}

void WaterWheel::loop() {
	auto now = time(NULL);
	for (auto item : items) {
		if (item->nextTick < now) {
			item->callback();
			if (item->once)
				detach(item);
			else
				item->nextTick = now + item->milliseconds;
		}
	}
}
