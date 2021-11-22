#pragma once

#include "define.hpp"

class CompareProfile
{
public:
    std::string device;
    std::string variable;

    std::string compare;

    double value;

    bool Parse(cJSON* json);
};

class Compare
{
public:
    CompareProfile* profile;

    enum class OP
    {
        NONE = 0,
        LT,
        LE,
        EQ,
        NE,
        GT,
        GE,
        BT,
        NB,
    };

    OP compare;

    double* variable;


public:
    Compare();
    ~Compare();

private:
    OP ParseOperator(const char* op);
};
