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


class InstructionProfile
{
public:
    std::string device; // "$name" "@tag" "#uuid"

    std::string point;

    double value;

    int arg;
    //std::string expr;

    int delay; //延迟执行

    bool Parse(cJSON* json);
};

//避免未声明
class Device;

class Instruction
{
private:
    InstructionProfile* profile;

    std::list<Device*> devices;
    PointProfile* point;

public:
	Instruction(InstructionProfile* profile);
	~Instruction();

    void Execute(const std::vector<double>& argv) {
        double val = profile->value;
        if (profile->arg > 0 && profile->arg < argv.size()) {
            val = argv[profile->arg];
        }
        for (auto& d : devices) {
            if (profile->delay) {
                //setTimeout;
                //d->Set(point, val);
            } else {
                //d->Set(point, val);
            }
        }
    }

private:

};
