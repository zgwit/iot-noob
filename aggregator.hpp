#pragma once

#include "define.hpp"
#include "expression.hpp"

class AggregatorProfile
{
public:
    std::string device; // "$name" "@tag" "#uuid"
    std::string query;
    std::string group; //sum count avg min max first last
    std::string variable; //var point calc
    std::string target; //目标变量

    void Parse(cJSON* json)
    {
        json_get_string(this, json, device);
        json_get_string(this, json, query);
        json_get_string(this, json, group);
        json_get_string(this, json, variable);
        json_get_string(this, json, target);
    }
};

class Device;

class Aggregator {
public:
    AggregatorProfile* profile;

    std::vector<Device*> devices;
    std::vector<Expression*> exprs;

};