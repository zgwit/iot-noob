#include "alarm.hpp"

bool Alarm::Parse(JsonObject &doc)
{
	name = doc["name"].as<std::string>();
	variable = doc["variable"].as<std::string>();

	level = doc["level"];
	timeout = doc["timeout"];
	resetInterval = doc["resetInterval"];
	resetTotal = doc["resetTotal"];

	return false;
}
