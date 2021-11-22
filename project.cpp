#include "project.hpp"

bool ProjectProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_string(this, json, name);
	json_get_string(this, json, version);

	json_get_object_array(this, json, devices);
	json_get_object_array(this, json, variables);
	json_get_object_array(this, json, commands);
	json_get_object_array(this, json, alarms);
	json_get_object_array(this, json, jobs);
	json_get_object_array(this, json, reactors);

	return true;
}


Project::Project(/* args */)
{
}

Project::~Project()
{
}

