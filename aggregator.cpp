#include "aggregator.hpp"


void Aggregator::Execute() {
    double val = 0;
    switch (type)
    {
    case Aggregator::AggregatorType::SUM:
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                val += it.variable->value;
        }
        as->value = val;
        break;
    case Aggregator::AggregatorType::COUNT:
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                val += 1;
        }
        as->value = val;
        break;
    case Aggregator::AggregatorType::AVG:
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                val += it.variable->value;
        }
        as->value = val / items.size();
        break;
    case Aggregator::AggregatorType::MIN:
        val = DBL_MAX;
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                if (it.variable->value < val)
                    val = it.variable->value;
        }
        as->value = val;
        break;
    case Aggregator::AggregatorType::MAX:
        val = DBL_MIN;
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate())
                if (it.variable->value > val)
                    val = it.variable->value;
        }
        as->value = val;
        break;
    case Aggregator::AggregatorType::FIRST:
        for (auto& it : items) {
            if (!it.expression || it.expression->Evaluate()) {
                //val = it.variable->value;
                as->value = it.variable->value;
                break;
            }
        }
        break;
    case Aggregator::AggregatorType::LAST:
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