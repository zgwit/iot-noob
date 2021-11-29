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

    void Load(cJSON* json, App* app, Device* dev) {
        std::string name = json_get_string(json, "command");
        if (app) {
            command = app->findCommand(name);
        }
        else if (dev) {
            command = dev->findCommand(name);
        }
    }

    void Execute() {
        command->Execute(argv);
    }

};
