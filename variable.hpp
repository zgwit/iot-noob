#pragma once

#include "define.hpp"

class Variable
{
public:
    std::string name;
    double _default; //д╛хож╣

    double value;

public:
    Variable(/* args */);
    ~Variable();

    void Load(cJSON* json);

    void Reset();
};
