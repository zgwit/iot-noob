#pragma once

#include <map>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

class Context
{
private:
    /* data */
    std::map<String, Variant> _props;

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
