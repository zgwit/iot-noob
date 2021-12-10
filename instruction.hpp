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
    int delay; //延迟执行

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
