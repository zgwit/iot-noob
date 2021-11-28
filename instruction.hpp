#pragma once

#include "define.hpp"
#include "point.hpp"
//#include "device.hpp"

/* ����̫���ӣ�����ǰ׺��ʽ
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

    int delay; //�ӳ�ִ��

    bool Parse(cJSON* json);
};

//����δ����
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
