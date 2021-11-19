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

class Instruction
{
private:
    InstructionProfile* profile;

public:
	Instruction(InstructionProfile* profile);
	~Instruction();

private:

};

Instruction::Instruction(InstructionProfile* p)
{
    profile = p;
    //TODO ±‡“Î±Ì¥Ô Ω
}

Instruction::~Instruction()
{
}


