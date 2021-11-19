#pragma once

#include "define.hpp"

#include "tinyexpr/tinyexpr.h"

#include "variable.hpp"
#include "variant.hpp"
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

    bool Parse(const char *expr);
    double Eval(Context &ctx);

};

Expression::Expression(/* args */)
{
}

Expression::~Expression()
{
    te_free(_expr);
}

bool Expression::Parse(const char* expr)
{
    int err;
    //释放历史
    if (_expr) te_free(_expr);

    _expr = te_compile(expr, NULL, 0, &err);
    return _expr != nullptr;
}

double Expression::Eval(Context &ctx)
{
    return te_eval(_expr);
}
