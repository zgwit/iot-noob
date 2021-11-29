#include "command.hpp"

#include "app.hpp"
#include "device.hpp"

Command::Command()
{
}

Command::~Command()
{
	for (auto& it : instructions) delete it;
}

void Command::Load(cJSON* json, App* app, Device* dev) {
    json_member_get_string(this, json, name);
    json_member_get_string(this, json, label);
    json_member_get_int(this, json, argc);

    json_array_foreach(json_get(json, "instructions"), item) {
        auto i = new Instruction();
        i->Load(item, app, dev);
        instructions.push_back(i);
    }

}

void Command::Execute(const std::vector<double>& argv) {
    for (auto& it : instructions) {
        it->Execute(argv);
    }
}
