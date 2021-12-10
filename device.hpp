#pragma once

#include "define.hpp"

#include "job.hpp"
#include "collector.hpp"
#include "calculator.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "variable.hpp"
#include "point.hpp"
#include "context.hpp"
#include "modbus.hpp"


class Device
{
public:
    bool enable;
    std::string name;
    std::vector<std::string> tags;
    //std::string label;
    std::string element; //uuid

    int slave;

    //TODO 上下文，采集器，定时器 等
    Context context;

    //std::vector<Variable*> variables;
    std::vector<Point*> points;
    std::vector<Collector*> collectors;
    std::vector<Calculator*> calculators;
    std::vector<Command*> commands;
    std::vector<Alarm*> alarms;
    std::vector<Job*> jobs;

    std::map<std::string, Command*> commandsIndex;

public:
    Device(/* args */);
    ~Device();

    void Load(cJSON* json, Application* app);

    Variable* findVariable(const std::string& name);
    Command* findCommand(const std::string& name) { return nullptr; }
    Point* findPoint(const std::string& name) { return nullptr; }

    void Start();

    void Stop();
};
