#pragma once

#include "define.hpp"
#include "tinyexpr/tinyexpr.h"


class Context
{
private:
    /* data */
    std::map<std::string, double> _props;
    te_variable* variable;

public:
    Context(/* args */);
    ~Context();

    //void getModified();

    //void Set(const char *name, void *value);
};
