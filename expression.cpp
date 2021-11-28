#include "expression.hpp"


Expression::Expression(/* args */)
{
}

Expression::~Expression()
{
    te_free(_expr);
}

bool Expression::Parse(const char* expr, const Context& ctx)
{
    int err;
    // Õ∑≈¿˙ ∑
    if (_expr) te_free(_expr);

    _expr = te_compile(expr, NULL, 0, &err);
    return _expr != nullptr;
}

double Expression::Evaluate()
{
    return te_eval(_expr);
}

