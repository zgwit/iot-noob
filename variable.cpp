#include "variable.hpp"

bool VariableProfile::Parse(cJSON* json)
{
	if (!json)
		return false;

	json_get_string(this, json, name);
	json_get_number(this, json, value);

	return true;
}


Variable::Variable(/* args */)
{
}

Variable::~Variable()
{
}

