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
    std::string device; // "名称" "@tag" "#uuid"

    std::string point;

    double value;

    std::string expr;

    bool Parse(cJSON* json);
};

//避免未声明
class Device;

class Instruction
{
private:
    InstructionProfile* profile;

    std::list<Device*> targets;
    PointProfile* point;

public:
	Instruction(InstructionProfile* profile);
	~Instruction();

private:

};
