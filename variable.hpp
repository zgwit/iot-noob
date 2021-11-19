#pragma once

#include "define.hpp"


class VariableProfile {
public:
    std::string name;
    double value;
    std::string expr;

    bool Parse(cJSON* json);
};

class Variable
{
private:
    /* data */
public:
    Variable(/* args */);
    ~Variable();
};

Variable::Variable(/* args */)
{
}

Variable::~Variable()
{
}
