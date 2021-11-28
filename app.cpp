#include "app.hpp"

bool AppProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_string(this, json, name);
	json_get_string(this, json, version);

	json_get_object_array(this, json, devices);
	json_get_object_array(this, json, variables);
	json_get_object_array(this, json, aggregators);
	json_get_object_array(this, json, commands);
	json_get_object_array(this, json, alarms);
	json_get_object_array(this, json, jobs);
	json_get_object_array(this, json, reactors);

	return true;
}


App::App(/* args */)
{
}

App::~App()
{
	for (auto& it : devices) delete it;
	for (auto& it : variables) delete it;
	for (auto& it : aggregators) delete it;
	for (auto& it : commands) delete it.second;
	for (auto& it : alarms) delete it;
	for (auto& it : jobs) delete it;
	for (auto& it : reactors) delete it;
}

