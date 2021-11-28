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

    Variable* as;
    AggregatorType type;
    std::vector<AggregatorItem> items;


    void Execute();

};