#pragma once

#include "define.hpp"
#include "variable.hpp"
#include "context.hpp"

class Compare
{
public:
    double value;

    enum class Type
    {
        NONE = 0,
        LT,
        LE,
        EQ,
        NE,
        GT,
        GE,
    };

    Type type;

    Variable* variable;


public:
    Compare();
    ~Compare();

    void Load(cJSON* json, const Context& ctx);

    bool Evaluate();

private:
    Type ParseOperator(const char* op);
};

class Condition
{
public:
    bool both;
    std::vector<Compare*> compares;
    std::vector<Condition*> children;

public:
    Condition();
    ~Condition();

    void Load(cJSON* json, const Context& ctx);

    bool Evaluate();

private:

};
