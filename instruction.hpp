#pragma once

#include "define.hpp"
#include "variant.hpp"
#include "point.hpp"
//#include "device.hpp"


class InstructionProfile
{
public:
    std::string device;
    std::string point;

    double value;

    std::string expr;

    bool Parse(cJSON* json);
};

class Instruction
{
private:
    InstructionProfile* profile;

    //Device* device;
    //Point* point;

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


