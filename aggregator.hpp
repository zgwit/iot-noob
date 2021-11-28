#pragma once

#include "define.hpp"
#include "expression.hpp"

class AggregatorProfile
{
public:
    std::string device; // "$name" "@tag" "#uuid"
    std::string query; //expr
    std::string group; //sum count avg min max first last
    std::string variable; //device context: var point calc
    std::string as; //app context, variable

    void Parse(cJSON* json)
    {
        json_get_string(this, json, device);
        json_get_string(this, json, query);
        json_get_string(this, json, group);
        json_get_string(this, json, variable);
        json_get_string(this, json, as);
    }
};

class Device;

class AggregatorItem {
public:
    Device* device;
    Variable* variable;
    Expression* expression;
};

class Aggregator {
public:
    enum class AggregatorType
    {
        NONE,SUM,COUNT,AVG,MIN,MAX,FIRST,LAST
    };


    AggregatorProfile* profile;

    AggregatorType type;
    std::vector<AggregatorItem> items;


    void Execute() {
        double val = 0;
        switch (type)
        {
        case Aggregator::AggregatorType::SUM:
            for (auto& it : items)
                if (!it.expression || it.expression->Evaluate())
                        val += it.variable->value;
            break;
        case Aggregator::AggregatorType::COUNT:
            for (auto& it : items)
                if (!it.expression || it.expression->Evaluate())
                    val += 1;
            break;
        case Aggregator::AggregatorType::AVG:
            for (auto& it : items)
                if (!it.expression || it.expression->Evaluate())
                    val += it.variable->value;
            val /= items.size();
            break;
        case Aggregator::AggregatorType::MIN:
            val = DBL_MAX;
            for (auto& it : items)
                if (!it.expression || it.expression->Evaluate())
                    if (it.variable->value < val)
                        val = it.variable->value;
            break;
        case Aggregator::AggregatorType::MAX:
            val = DBL_MIN;
            for (auto& it : items)
                if (!it.expression || it.expression->Evaluate())
                    if (it.variable->value > val)
                        val = it.variable->value;
            break;
        case Aggregator::AggregatorType::FIRST:
            for (auto& it : items)
                if (!it.expression || it.expression->Evaluate()) {
                    val = it.variable->value;
                    break;
                }
            break;
        case Aggregator::AggregatorType::LAST:
            for (auto it = items.rbegin(); it != items.rend(); ++it)
                if (!it->expression || it->expression->Evaluate()) {
                    val = it->variable->value;
                    break;
                }
            break;
        default:
            break;
        }
    }

};