#pragma once

#include "define.hpp"

#include "tinyexpr/tinyexpr.h"

#include "variable.hpp"
#include "context.hpp"

class Expression
{
private:
    te_expr* _expr;

private:
    /* data */
public:
    Expression(/* args */);
    ~Expression();

    bool Parse(const char *expr, const Context& ctx);
    double Evaluate();

};

