#pragma once

#include "define.hpp"

#include "tinyexpr.h"

#include "variable.hpp"
#include "context.hpp"

class Expression
{
private:
    te_expr* _expr;

private:
    /* data */
public:
    Expression(const std::string& expr, Context& ctx);
    ~Expression();

    //bool Parse(const char *expr, Context& ctx);
    double Evaluate();

};

