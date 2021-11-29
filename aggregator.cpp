#include "aggregator.hpp"
#include "app.hpp"


const std::map<std::string, Aggregator::Type> aggregator_map = {
    {"sum", Aggregator::Type::SUM},
    {"count", Aggregator::Type::COUNT},
    {"avg", Aggregator::Type::AVG},
    {"min", Aggregator::Type::MIN},
    {"max", Aggregator::Type::MAX},
    {"first", Aggregator::Type::FIRST},
    {"last", Aggregator::Type::LAST},
};

void Aggregator::Load(cJSON* json, App* app) {
    std::string device = json_get_string(json, "device");
    std::string query = json_get_string(json, "query");
    std::string group = json_get_string(json, "group");
    std::string variable = json_get_string(json, "variable");
    std::string as = json_get_string(json, "as");

    //查找设备
    std::vector<Device*> devices;
    app->findDevice(device, devices);
    for (auto& d : devices) {
        AggregatorItem item{ nullptr, nullptr, nullptr };
        item.device = d;
        item.variable = d->findVariable(variable);
        if (query.length())
            item.expression = new Expression(query, d->context);
        items.push_back(item);
    }

    //转换类型
    //std::transform(group.begin(), group.end(), group.begin(), std::tolower);
    auto it = aggregator_map.find(group);
    if (it != aggregator_map.end())
        type = it->second;

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

