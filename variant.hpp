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
    enum class Type
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
    };

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
        return Type::BOOL;
    if (!strcmp(name, "byte"))
        return Type::BYTE;
    if (!strcmp(name, "word"))
        return Type::WORD;
    if (!strcmp(name, "dword"))
        return Type::DWORD;
    if (!strcmp(name, "int"))
        return Type::INT;
    if (!strcmp(name, "dint"))
        return Type::DINT;
    if (!strcmp(name, "float"))
        return Type::FLOAT;
    if (!strcmp(name, "double"))
        return Type::DOUBLE;
    if (!strcmp(name, "string"))
        return Type::STRING;
    if (!strcmp(name, "array"))
        return Type::ARRAY;
    if (!strcmp(name, "object"))
        return Type::OBJECT;
    return Type::NONE;
}
