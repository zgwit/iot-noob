#include "compare.hpp"

bool CompareProfile::Parse(cJSON* json)
{
    if (!json)
        return false;

	json_get_string(this, json, variable);
	json_get_string(this, json, compare);
	json_get_number(this, json, value1);
	json_get_number(this, json, value2);

	return true;

}
