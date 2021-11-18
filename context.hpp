#pragma once

#include "define.hpp"
#include "tinyexpr/tinyexpr.h"

extern "C" {
    double _max(double a, double b) { return a > b ? a : b; };
    double _min(double a, double b) { return a < b ? a : b; };
    double _if(double a, double b, double c) { return a > 0 ? b : c; };

    te_variable default_context[] = {
        {"max", _max, TE_FUNCTION2},
        {"min", _min, TE_FUNCTION2},
        {"if", _if, TE_FUNCTION3},
    };
}


class Context
{
private:
    /* data */
    std::map<std::string, double> _props;
    te_variable* variable;

public:
    Context(/* args */);
    ~Context();

    void getModified();

    void Set(const char *name, void *value);
};

Context::Context(/* args */)
{
}

Context::~Context()
{
}
