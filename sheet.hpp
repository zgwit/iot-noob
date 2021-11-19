#pragma once

#include "define.hpp"

enum DataType {
    NONE = 0,
    BIT,
    BYTE,
    WORD,
    DWORD,
    INT,
    DINT,
    FLOAT,
    DOUBLE,
};

class SheetProfile
{
public:
    std::string name;
    std::string label;
    std::string unit;

    DataType type;

    std::string crontab;
    uint16_t interval;

    uint8_t code;
    uint16_t address;
    uint8_t precision;
    bool le;
    bool readable;
    bool writable;

    bool Parse(cJSON* json);
};

class Sheet
{
private:
    SheetProfile *profile;

    /* data */
public:
    Sheet(/* args */);
    ~Sheet();
};

Sheet::Sheet(/* args */)
{
}

Sheet::~Sheet()
{
}
