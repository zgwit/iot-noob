#pragma once

#include "define.hpp"

class Variable
{
public:
    std::string name;
    double _default; //Ĭ��ֵ

    double value;

public:
    Variable(/* args */);
    ~Variable();

    void Load(cJSON* json);

    void Reset();
};
