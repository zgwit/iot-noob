#pragma once

#include "define.hpp"
#include "instruction.hpp"


class CommandProfile
{
public:
    std::string name;
    std::string label;
    int argc;

    std::vector<InstructionProfile> instructions;

    bool Parse(cJSON *json);
};

class InvokeProfile
{
public:
    std::string command;
    std::vector<double> argv;

    bool Parse(cJSON *json);
};

class Command
{
public:
    CommandProfile* profile;


	Command();
	~Command();

private:

};
