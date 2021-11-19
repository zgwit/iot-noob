#include "instruction.hpp"

bool InstructionProfile::Parse(cJSON* json)
{
	if (!json)
		return false;

	json_get_string(this, json, device);
	json_get_string(this, json, point);
	json_get_number(this, json, value);
	json_get_string(this, json, expr);

    return true;
}
