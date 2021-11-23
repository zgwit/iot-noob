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
