#pragma once

#include "define.hpp"

class CompareProfile
{
public:
    std::string device;
    std::string variable;

    std::string type;

    double value;

    bool Parse(cJSON* json);
};

class ConditionProfile
{
public:
    //bool both;
    std::string type; //and or
    std::vector<CompareProfile> compares;
    std::vector<ConditionProfile> children;

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

    bool Eval();

private:
    OP ParseOperator(const char* op);
};

class Condition
{
public:
    bool both;

public:
    Condition();
    ~Condition();

private:

};
