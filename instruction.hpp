#pragma once

#include "define.hpp"
#include "variable.hpp"

class InstructionDefine: Define
{
public:
    std::string target;
    std::string variable;
    Variant value;

    bool Parse(JsonDocument &doc);
};


class Instruction
{
private:
    InstructionDefine* define;

    Variable* variablePtr;

    /* data */
public:
    Instruction(/* args */);
    ~Instruction();
};

Instruction::Instruction(/* args */)
{
}

Instruction::~Instruction()
{
}
