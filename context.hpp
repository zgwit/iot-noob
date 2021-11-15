#pragma once

#include <map>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "variant.hpp"

class Context
{
private:
    /* data */
    std::map<std::string, Variant*> _props;

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
