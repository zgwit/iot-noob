#include "instruction.hpp"
#include "application.hpp"
#include "device.hpp"

Instruction::Instruction()
{
    //TODO ±‡“Î±Ì¥Ô Ω
}

Instruction::~Instruction()
{
}

void Instruction::Load(cJSON* json, Application* app, Device* dev) {
    std::string  name = json_get_string(json, "device");
    std::string  point = json_get_string(json, "point");

    std::vector<Device*> devices;
    if (app) {
        app->findDevice(name, devices);
    }
    else {
        devices.push_back(dev);
    }

    for (auto& d : devices) {
        InstructionTarget target{};
        target.device = d;
        target.point = d->findPoint(point);
    }

    value = json_get_number(json, "value");
    arg = json_get_int(json, "arg");
    delay = json_get_int(json, "delay");
}

void Instruction::Execute(const std::vector<double>& argv) {
    double val = value;
    if (arg > 0 && arg < argv.size()) {
        val = argv[arg];
    }
    for (auto& d : targets) {
        if (delay) {
            //setTimeout;
            //d->Set(point, val);
        }
        else {
            //d->Set(point, val);
        }
    }
}


