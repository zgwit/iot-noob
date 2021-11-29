#include "aggregator.hpp"
#include "app.hpp"

void AggregatorProfile::Parse(cJSON* json)
{
    json_get_string(this, json, device);
    json_get_string(this, json, query);
    json_get_string(this, json, group);
    json_get_string(this, json, variable);
    json_get_string(this, json, as);
}

const std::map<std::string, Aggregator::Type> aggregator_map = {
    {"sum", Aggregator::Type::SUM},
    {"count", Aggregator::Type::COUNT},
    {"avg", Aggregator::Type::AVG},
    {"min", Aggregator::Type::MIN},
    {"max", Aggregator::Type::MAX},
    {"first", Aggregator::Type::FIRST},
    {"last", Aggregator::Type::LAST},
};

Aggregator::Aggregator(AggregatorProfile* profile, App* app) {

    //std::tolower
    std::transform(profile->group.begin(), profile->group.end(), profile->group.begin(), std::tolower);
    
    auto it = aggregator_map.find(profile->group);
    if (it != aggregator_map.end())
        type = it->second;

    //TODO 找设备，编译表达式
    std::vector<Device*> devices;
    app->findDevice(profile->device, devices);

    //items.resize(devices.size());
    for (auto& d : devices) {
        AggregatorItem item{nullptr, nullptr, nullptr};
        item.device = d;
        item.variable = d->findVariable(profile->variable);
        if (profile->query.length())
            item.expression = new Expression(profile->query, d->context);
        items.push_back(item);
    }

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

