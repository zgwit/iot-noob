#pragma once

#include "define.hpp"

class Command: Proto
{
public:
    std::string name;
    std::string label;

    std::vector<Instruction> instructions;

    bool Parse(JsonDocument &doc);
};
