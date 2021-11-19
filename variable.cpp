#include "variable.hpp"

bool VariableProfile::Parse(cJSON* json)
{
	if (!json)
		return false;

	json_get_string(this, json, name);
	json_get_number(this, json, value);
	json_get_string(this, json, expr);

	return true;
}
