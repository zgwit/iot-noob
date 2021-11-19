#pragma once

class VariableProfile {
public:
    std::string name;
    double value;

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
