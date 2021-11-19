#include "command.hpp"

bool CommandProfile::Parse(cJSON* json)
{
    if (!json) return false;

	json_get_string(this, json, name);
	json_get_string(this, json, label);
	json_get_int(this, json, argc);
	json_get_object_array(this, json, instructions);

	return true;
}

bool InvokeProfile::Parse(cJSON* json)
{
	if (!json) return false;

	json_get_string(this, json, command);
	json_get_number_array(this, json, argv);

	return true;
}
