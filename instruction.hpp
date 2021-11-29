#pragma once

#include "define.hpp"
#include "point.hpp"
//#include "device.hpp"

/* 定义太复杂，改用前缀方式
struct DeviceTarget
{
    std::string name; //device name
    std::string uuid; //element uuid
    std::vector<std::string> tags; //element tags
};*/


//避免未声明
class App;
class Device;

class InstructionTarget {
public:
    Device* device;
    Point* point;
};

class Instruction
{
private:
    double value;
    int arg;
    int delay; //延迟执行

    //std::vector<Device*> devices;
    //PointProfile* point;
    std::vector<InstructionTarget> targets;

public:
	Instruction();
	~Instruction();

    void Load(cJSON* json, App* app, Device* dev) {
        std::string  name = json_get_string(json, "device");
        std::string  point = json_get_string(json, "point");

        std::vector<Device*> devices;
        if (app) {
            app->findDevice(name, devices);
        } else {
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

    void Execute(const std::vector<double>& argv) {
        double val = value;
        if (arg > 0 && arg < argv.size()) {
            val = argv[arg];
        }
        for (auto& d : targets) {
            if (delay) {
                //setTimeout;
                //d->Set(point, val);
            } else {
                //d->Set(point, val);
            }
        }
    }

private:

};
