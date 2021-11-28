#pragma once

#include "define.hpp"
#include "variable.hpp"
#include "expression.hpp"


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

    Variable* variable;
    Expression* expression;

    void Evaluate() {
        variable->value = expression->Evaluate();
    }
};
