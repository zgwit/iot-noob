#pragma once

#include "define.hpp"


class CalculatorProfile {
public:
    std::string variable;
    std::string expression;

    void Parse(cJSON* json)
    {
        json_get_string(this, json, variable);
        json_get_string(this, json, expression);
    }
};

class Calculator {
public:
    CalculatorProfile* profile;


};


class FilterProfile
{
public:
    std::string algorithm;
    std::vector<double> arguments;

    void Parse(cJSON* json)
    {
        json_get_string(this, json, algorithm);
        json_get_number_array(this, json, arguments);
    }
};



class CollectorProfile
{
public:
    bool enable;

    std::string type; // interal, crontab

    int interval; // seconds
    std::string crontab;

    int code;
    int address;
    int length;

    FilterProfile filter;

    std::vector<CalculatorProfile> calculators;

    bool Parse(cJSON* json);
};



class Collector
{
private:
    CollectorProfile* profile;
    
public:
    Collector(/* args */);
    ~Collector();
};
