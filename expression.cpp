#include "expression.hpp"



Expression::~Expression()
{
    te_free(_expr);
}

Expression::Expression(const std::string &expr, Context& ctx)
{
    int err;
    // Õ∑≈¿˙ ∑
    if (_expr) te_free(_expr);

    _expr = te_compile(expr.c_str(), NULL, 0, &err);
    //return _expr != nullptr;
}

double Expression::Evaluate()
{
    return te_eval(_expr);
}

