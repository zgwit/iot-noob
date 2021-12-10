#include "command.hpp"

#include "application.hpp"
#include "device.hpp"

Command::Command()
{
}

Command::~Command()
{
	for (auto& it : instructions) delete it;
}

void Command::Load(cJSON* json, Application* app, Device* dev) {
    this->name = json_get_string(json, "name");
    this->label = json_get_string(json, "label");
    this->argc = json_get_int(json, "argc");

    auto items = json_get(json, "instructions");
    json_foreach(items, [&, this](cJSON* item) {
        auto i = new Instruction();
        i->Load(item, app, dev);
        instructions.push_back(i);
        });
}

void Command::Execute(const std::vector<double>& argv) {
    for (auto& it : instructions) {
        it->Execute(argv);
    }
}


void Invoke::Load(cJSON* json, Application* app, Device* dev) {
    std::string name = json_get_string(json, "command");
    if (app) {
        command = app->findCommand(name);
    }
    else if (dev) {
        command = dev->findCommand(name);
    }

    auto items = json_get(json, "argv");
    json_foreach(items, [&, this](cJSON* item) {
        //TODO json_is_number, or error
        this->argv.push_back(item->valuedouble);
        });
}
