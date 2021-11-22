#pragma once

#include "define.hpp"
#include "point.hpp"
//#include "device.hpp"


class InstructionProfile
{
public:
    std::string device; // "Ãû³Æ" "@tag" "#uuid"
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
