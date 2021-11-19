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

Compare::Compare()
{
}

Compare::~Compare()
{
}

Compare::OP Compare::ParseOperator(const char* op)
{
    if (!strcmp(op, "lt") || !strcmp(op, "<"))
        return OP::LT;
    if (!strcmp(op, "le") || !strcmp(op, "<="))
        return OP::LE;
    if (!strcmp(op, "eq") || !strcmp(op, "=="))
        return OP::EQ;
    if (!strcmp(op, "ne") || !strcmp(op, "!=") || !strcmp(op, "<>"))
        return OP::NE;
    if (!strcmp(op, "gt") || !strcmp(op, ">"))
        return OP::GT;
    if (!strcmp(op, "ge") || !strcmp(op, ">="))
        return OP::GE;
    return OP::NONE;
}