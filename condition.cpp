#include "condition.hpp"



bool CompareProfile::Parse(cJSON* json)
{
    if (!json) return false;

    json_get_string(this, json, device);
    json_get_string(this, json, variable);
    json_get_string(this, json, type);
    json_get_number(this, json, value);

    return true;
}


bool ConditionProfile::Parse(cJSON* json)
{
    if (!json) return false;
    
    json_get_string(this, json, type);
    json_get_object_array(this, json, compares);
    json_get_object_array(this, json, children);

	return true;

}


Compare::Compare()
{
}

Compare::~Compare()
{
}

Compare::OP Compare::ParseOperator(const char* op)
{
    if (!strcmp(op, "lt") || !strcmp(op, "<"))
        return OP::LT;
    if (!strcmp(op, "le") || !strcmp(op, "<="))
        return OP::LE;
    if (!strcmp(op, "eq") || !strcmp(op, "=="))
        return OP::EQ;
    if (!strcmp(op, "ne") || !strcmp(op, "!=") || !strcmp(op, "<>"))
        return OP::NE;
    if (!strcmp(op, "gt") || !strcmp(op, ">"))
        return OP::GT;
    if (!strcmp(op, "ge") || !strcmp(op, ">="))
        return OP::GE;
    return OP::NONE;
}