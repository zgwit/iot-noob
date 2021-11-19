#include "command.hpp"

bool CommandProfile::Parse(cJSON* json)
{
    if (!json)
        return false;

	json_get_string(this, json, name);
	json_get_string(this, json, label);
	json_get_int(this, json, argc);

	auto _instructions = json_get(json, instructions);
	if (json_is_array(_instructions)) {
		instructions.resize(json_array_size(_instructions));
		auto iter = instructions.begin();
		json_array_foreach(_instructions, ins) {
			iter->Parse(ins);
			iter++;
		}
	}

	return true;
}

bool InvokeProfile::Parse(cJSON* json)
{
	if (!json)
		return false;

	json_get_string(this, json, command);
	auto _argv = json_get(json, argv);
	if (json_is_array(_argv)) {
		argv.resize(json_array_size(_argv));
		auto iter = argv.begin();
		json_array_foreach(_argv, v) {
			*iter = cJSON_GetNumberValue(v);
		}
	}

	return true;
}
