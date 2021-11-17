#pragma once

#include "define.hpp"
#include "variant.hpp"

class Instruction: Proto
{
public:
    std::string target;
    std::string variable;
    Variant value;

    bool Parse(JsonObject& obj);
};
