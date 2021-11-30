#pragma once

#include "define.hpp"
#include "expression.hpp"

class App;
class Device;

class AggregatorItem {
public:
    Device* device;
    Variable* variable;
    Expression* expression;

    ~AggregatorItem() {
        if (expression)
            delete expression;
    }
};

class Aggregator {
public:
    enum class Type
    {
        NONE,SUM,COUNT,AVG,MIN,MAX,FIRST,LAST
    };

    Type type;
    std::vector<AggregatorItem> items;
    Variable* as;

    Type parseType(const char* group);

    void Load(cJSON* json, App* app);
    void Execute();
};