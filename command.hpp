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


class Command
{
public:
    CommandProfile* profile;

    std::vector<Instruction> instructions;


	Command();
	~Command();

    void Execute(const std::vector<double>& argv) {
        for (auto& it : instructions) {
            it.Execute(argv);
        }
    }

private:

};

class InvokeProfile
{
public:
    std::string command;
    std::vector<double> argv;

    bool Parse(cJSON *json);
};

class Invoke {
public:
    InvokeProfile* profile;

    Command* command;

    void Execute() {
        command->Execute(profile->argv);
    }

};
