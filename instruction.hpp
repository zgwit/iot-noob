#pragma once

#include "define.hpp"
#include "variant.hpp"


class InstructionProfile
{
public:
    std::string target;
    std::string variable;

    double value;

    std::string expr;

    bool Parse(cJSON* json);
};


