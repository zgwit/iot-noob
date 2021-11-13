#pragma once

#include <map>
#include <stdint.h>
#include <stddef.h>

typedef enum {
    VariantTypeNone,
    VariantTypeBool,
    VariantTypeInt8,
    VariantTypeUint8,
    VariantTypeInt16,
    VariantTypeUint16,
    VariantTypeInt32,
    VariantTypeUint32,
    VariantTypeFloat,
    VariantTypeDouble,
    VariantTypeString,
    VariantTypeArray,
    VariantTypeObject,

} VariantType;

class Variant
{
private:
    /* data */
    union {
        bool asBoolean;
        float asFloat;
        double asDouble;

    } data;

public:
    Variant(/* args */);
    ~Variant();
};

Variant::Variant(/* args */)
{
}

Variant::~Variant()
{
}



class Context
{
private:
    /* data */
    std::map<String, Variant> _props;

public:
    Context(/* args */);
    ~Context();

    void getModified();

    void setProperty(const char *name, void *value);
};

Context::Context(/* args */)
{
}

Context::~Context()
{
}
