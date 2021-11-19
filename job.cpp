#include "job.hpp"

bool JobProfile::Parse(cJSON* json)
{
	if (!json)
		return false;

	json_get_bool(this, json, enable);
	json_get_string(this, json, type);
	json_get_int(this, json, daily);
	json_get_int(this, json, weekRange);
	json_get_string(this, json, crontab);

	auto _commands = json_get(json, commands);
	if (json_is_array(_commands)) {
		commands.resize(json_array_size(_commands));
		auto iter = commands.begin();
		json_array_foreach(_commands, ins) {
			iter->Parse(ins);
			iter++;
		}
	}

	return true;
}
