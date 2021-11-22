#include "context.hpp"


extern "C" {
    double _max(double a, double b) { return a > b ? a : b; };
    double _min(double a, double b) { return a < b ? a : b; };
    double _if(double a, double b, double c) { return a > 0 ? b : c; };

    te_variable default_context[] = {
        {"max", (void*)_max, TE_FUNCTION2},
        {"min", (void*)_min, TE_FUNCTION2},
        {"if", (void*)_if, TE_FUNCTION3},
    };
}


Context::Context(/* args */)
{
}

Context::~Context()
{
}
