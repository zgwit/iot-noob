#pragma once

#include "define.hpp"

class SheetDef : Proto
{
public:
    std::string name;
    std::string label;
    std::string unit;
    //std::string default;
    std::string type;
    std::string crontab;
    uint8_t code;
    uint16_t address;
    uint8_t precision;
    bool le;
    bool readable;
    bool writable;

    bool Parse(JsonDocument &doc) override;
};

class Sheet
{
private:
    SheetDef *Proto;

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
