#include "variable.hpp"


Variable::Variable(/* args */)
{
}

Variable::~Variable()
{
}

void Variable::Load(cJSON* json) {
	name = json_get_string(json, "name");
	_default = json_get_number(json, "default");
	value = _default;
}

void Variable::Reset() {
	value = _default;
}

