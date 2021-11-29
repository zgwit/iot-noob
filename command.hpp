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

    void Load(cJSON* json) {
        name = json_get_string(json, "name");
        label = json_get_string(json, "label");
        argc = json_get_int(json, "argc");
        auto ins = json_get(json, "instructions");
        cJSON* item;
        json_array_foreach(ins, item) {
            auto i = new Instruction();
            i->Load(ins);
            instructions.push_back(i);
        }

    }

    void Execute(const std::vector<double>& argv) {
        for (auto& it : instructions) {
            it->Execute(argv);
        }
    }

private:

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
            command = dev->findCommnad(name);
        }
    }

    void Execute() {
        command->Execute(argv);
    }

};
