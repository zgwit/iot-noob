#include "condition.hpp"


Compare::Compare()
{
}

Compare::~Compare()
{
}

void Compare::Load(cJSON* json, const Context& ctx) {
    //std::string device = cJSON_GetStringValue(cJSON_GetObjectItem(json, "device"));
    std::string variable = json_get_string(json, "variable");
    this->variable = ctx.find(variable);
    this->type = ParseOperator(json_get_string(json, "type"));
    value = json_get_number(json, "value");
}

bool Compare::Evaluate() {
    switch (type)
    {
    case Type::LT: return variable->value < value;
    case Type::LE: return variable->value <= value;
    case Type::EQ: return variable->value == value;
    case Type::NE: return variable->value != value;
    case Type::GT: return variable->value > value;
    case Type::GE: return variable->value >= value;
    default:
        return false;
    }
}

Compare::Type Compare::ParseOperator(const char* op)
{
    if (!strcmp(op, "lt") || !strcmp(op, "<"))
        return Type::LT;
    if (!strcmp(op, "le") || !strcmp(op, "<="))
        return Type::LE;
    if (!strcmp(op, "eq") || !strcmp(op, "=="))
        return Type::EQ;
    if (!strcmp(op, "ne") || !strcmp(op, "!=") || !strcmp(op, "<>"))
        return Type::NE;
    if (!strcmp(op, "gt") || !strcmp(op, ">"))
        return Type::GT;
    if (!strcmp(op, "ge") || !strcmp(op, ">="))
        return Type::GE;
    return Type::NONE;
}

Condition::Condition() {}

Condition::~Condition() {
    for (auto& it : compares) delete it;
    for (auto& it : children) delete it;
}

void Condition::Load(cJSON* json, const Context& ctx) {
    const char* type = json_get_string(json, "type");
    if (!strcmpi(type, "and"))
        both = true;

    cJSON* item;
    cJSON* arr = json_get(json, "compares");
    cJSON_ArrayForEach(item, arr)
    {
        auto cmp = new Compare();
        cmp->Load(item, ctx);
        compares.push_back(cmp);
    }

    arr = json_get(json, "children");
    cJSON_ArrayForEach(item, arr)
    {
        auto cld = new Condition();
        cld->Load(item, ctx);
        children.push_back(cld);
    }
}

bool Condition::Evaluate() {
    if (both) {
        for (auto& it : compares)
            if (!it->Evaluate())
                return false;
        for (auto& it : children)
            if (!it->Evaluate())
                return false;
        return true;
    }
    else {
        for (auto& it : compares)
            if (it->Evaluate())
                return true;
        for (auto& it : children)
            if (it->Evaluate())
                return true;
        return false;
    }
}
