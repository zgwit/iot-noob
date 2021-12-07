#include "aggregator.hpp"
#include "app.hpp"

Aggregator::Type Aggregator::parseType(const char* group)
{
    if (!strcmp(group, "sum"))
        return Type::SUM;
    if (!strcmp(group, "count"))
        return Type::COUNT;
    if (!strcmp(group, "avg"))
        return Type::AVG;
    if (!strcmp(group, "min"))
        return Type::MIN;
    if (!strcmp(group, "max"))
        return Type::MAX;
    if (!strcmp(group, "first"))
        return Type::FIRST;
    if (!strcmp(group, "last"))
        return Type::LAST;
    return Type::NONE;
}

void Aggregator::Load(cJSON* json, App* app) {
    const char* device = json_get_string(json, "device");
    const char* query = json_get_string(json, "query");
    const char* group = json_get_string(json, "group");
    const char* variable = json_get_string(json, "variable");
    const char* as = json_get_string(json, "as");

    //查找设备
    std::vector<Device*> devices;
    app->findDevice(device, devices);
    for (auto& d : devices) {
        AggregatorItem item;
        item.device = d;
        item.variable = d->findVariable(variable);
        if (query)
            item.expression = new Expression(query, d->context);
        items.push_back(item);
    }

    //转换类型
    type = parseType(group);

    //找到目标变量
    this->as = app->findVariable(as);
}


void Aggregator::Execute() {
    double val = 0;
    switch (type)
    {
    case Aggregator::Type::SUM:
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                val += it.variable->value;
        }
        as->value = val;
        break;
    case Aggregator::Type::COUNT:
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                val += 1;
        }
        as->value = val;
        break;
    case Aggregator::Type::AVG:
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                val += it.variable->value;
        }
        as->value = val / items.size();
        break;
    case Aggregator::Type::MIN:
        val = DBL_MAX;
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                if (it.variable->value < val)
                    val = it.variable->value;
        }
        as->value = val;
        break;
    case Aggregator::Type::MAX:
        val = DBL_MIN;
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                if (it.variable->value > val)
                    val = it.variable->value;
        }
        as->value = val;
        break;
    case Aggregator::Type::FIRST:
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate()) {
                //val = it.variable->value;
                as->value = it.variable->value;
                break;
            }
        }
        break;
    case Aggregator::Type::LAST:
        for (auto it = items.rbegin(); it != items.rend(); ++it) {
            if (!it->expression || it->expression->Evaluate()) {
                //val = it->variable->value;
                as->value = it->variable->value;
                break;
            }
        }
        break;
    default:
        break;
    }
}

