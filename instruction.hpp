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


//����δ����
class Application;
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
    int delay; //�ӳ�ִ��

    //std::vector<Device*> devices;
    //PointProfile* point;
    std::vector<InstructionTarget> targets;

public:
    Instruction();
    ~Instruction();

    void Load(cJSON* json, Application* app, Device* dev);

    void Execute(const std::vector<double>& argv);

private:

};
