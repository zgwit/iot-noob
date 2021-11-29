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

    void Parse(cJSON* json);
};

class App;
class Device;

class AggregatorItem {
public:
    Device* device;
    Variable* variable;
    Expression* expression;
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

    Aggregator(AggregatorProfile* profile, App* app);

    void Execute();
};