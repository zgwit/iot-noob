#pragma once

#include "define.hpp"
#include "instruction.hpp"


class Command
{
public:
    //CommandProfile* profile;
    std::string name;
    std::string label;
    int argc;

    std::vector<Instruction*> instructions;

public:
	Command();
	~Command();

    void Load(cJSON* json, App* app, Device* dev);
    void Execute(const std::vector<double>& argv);

};


class Invoke {
public:
    std::vector<double> argv;

    Command* command;

    void Load(cJSON* json, App* app, Device* dev);

    void Execute() {
        command->Execute(argv);
    }

};
