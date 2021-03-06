#include "condition.hpp"
#include "variable.hpp"

Compare::Compare(): type(Type::NONE), variable(nullptr), value(0)
{
}

Compare::~Compare()
{
}

void Compare::Load(cJSON* json, Context& ctx) {
    //std::string device = cJSON_GetStringValue(cJSON_GetObjectItem(json, "device"));
    std::string var = json_get_string(json, "variable");
    
    this->variable = ctx.Get(var);
    this->type = parseType(json_get_string(json, "type"));
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

Compare::Type Compare::parseType(const char* op)
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

Condition::Condition(): both(false)
{
}

Condition::~Condition() {
    for (auto& it : compares) delete it;
    for (auto& it : children) delete it;
}

void Condition::Load(cJSON* json, Context& ctx) {
    const char* type = json_get_string(json, "type");
    if (!strcasecmp(type, "and"))
        both = true;

    auto items = json_get(json, "compares");
    json_array_foreach(items, item) {
        auto cmp = new Compare();
        cmp->Load(item, ctx);
        compares.push_back(cmp);
    }

    items = json_get(json, "children");
    json_array_foreach(items, item) {
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
