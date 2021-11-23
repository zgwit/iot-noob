#include "context.hpp"


extern "C" {
    double _max(double a, double b) { return a > b ? a : b; };
    double _min(double a, double b) { return a < b ? a : b; };
    double _if(double a, double b, double c) { return a > 0 ? b : c; };
    double _and(double a, double b) { return a > 0 && b > 0; };
    double _or(double a, double b) { return a > 0 || b > 0; };

    te_variable default_context[] = {
        {"max", (void*)_max, TE_FUNCTION2},
        {"min", (void*)_min, TE_FUNCTION2},
        {"if", (void*)_if, TE_FUNCTION3},
        {"and", (void*)_and, TE_FUNCTION2},
        {"or", (void*)_or, TE_FUNCTION2},
    };
}


Context::Context(/* args */)
{
}

Context::~Context()
{
}
