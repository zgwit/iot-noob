#pragma once

#include "define.hpp"


class VariableProfile {
public:
    std::string name;
    double value; //д╛хож╣

    bool Parse(cJSON* json);
};

class Variable
{
public:
    VariableProfile* profile;

    double value;

private:
    /* data */

public:
    Variable(/* args */);
    ~Variable();
};
