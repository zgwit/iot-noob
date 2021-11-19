#include "instruction.hpp"

bool InstructionProfile::Parse(cJSON* json)
{
	if (!json)
		return false;

	json_get_string(this, json, target);
	json_get_string(this, json, variable);
	json_get_number(this, json, value);
	json_get_string(this, json, expr);

    return true;
}
