#pragma once

#include "define.hpp"
#include "variable.hpp"

class Instruction: Proto
{
public:
    std::string target;
    std::string variable;
    Variant value;

    bool Parse(JsonDocument &doc);
};
