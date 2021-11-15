#pragma once

#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <string>
#include <map>
#include <vector>

class Variant
{
public:
    typedef enum
    {
        NONE,
        BOOL,
        BYTE,
        WORD,
        DWORD,
        INT,
        DINT,
        FLOAT,
        DOUBLE,
        STRING,
        ARRAY,
        OBJECT,
    } Type;

private:
    union
    {
        bool asBool;
        uint8_t asByte;
        uint16_t asWord;
        uint32_t asDWord;
        int16_t asInt;
        int32_t asDInt;
        float asFloat;
        double asDouble;
    };

    std::string asString;
    std::vector<Variant> asArray;
    std::map<std::string, Variant> asObject;

public:
    Variant(/* args */);
    ~Variant();

    Type ParseType(const char *name);
};

Variant::Variant(/* args */)
{
}

Variant::~Variant()
{
}

Variant::Type Variant::ParseType(const char *name)
{
    if (!strcmp(name, "bool"))
        return BOOL;
    if (!strcmp(name, "byte"))
        return BYTE;
    if (!strcmp(name, "word"))
        return WORD;
    if (!strcmp(name, "dword"))
        return DWORD;
    if (!strcmp(name, "int"))
        return INT;
    if (!strcmp(name, "dint"))
        return DINT;
    if (!strcmp(name, "float"))
        return FLOAT;
    if (!strcmp(name, "double"))
        return DOUBLE;
    if (!strcmp(name, "string"))
        return STRING;
    if (!strcmp(name, "array"))
        return ARRAY;
    if (!strcmp(name, "object"))
        return OBJECT;
    return NONE;
}
