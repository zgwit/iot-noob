#pragma once

#include "define.hpp"
#include "variable.hpp"
#include "expression.hpp"


class Calculator {
public:
    Variable* variable;
    Expression* expression;

    ~Calculator() {
        delete expression;
    }

    void Load(cJSON* json, const Context& ctx);
    void Evaluate();
};
