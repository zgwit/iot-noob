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
    std::string device; // "����" "@tag" "#uuid"

    std::string point;

    double value;

    std::string expr;

    bool Parse(cJSON* json);
};

//����δ����
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
