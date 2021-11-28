#pragma once

#include "define.hpp"

#include "job.hpp"
#include "collector.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "variable.hpp"
#include "point.hpp"
#include "context.hpp"

class DeviceProfile
{
public:
    bool enable;

    std::string name;
    std::vector<std::string> tags;

    std::string label;
    std::string element; //uuid

    int slave;

    std::vector<VariableProfile> variables;
    std::vector<PointProfile> points;
    std::vector<CollectorProfile> collectors;
    std::vector<CalculatorProfile> calculators;
    std::vector<CommandProfile> commands;
    std::vector<AlarmProfile> alarms;
    std::vector<JobProfile> jobs;

    bool Parse(cJSON* json);
};



class Device
{
public:
    DeviceProfile* profile;

    //TODO 上下文，采集器，定时器 等
    Context context;

    std::vector<Variable*> variables;
    std::vector<Collector*> collectors;
    std::vector<Calculator*> calculators;
    //std::vector<Command*> commands;
    std::map<std::string, Command*> commands;
    std::vector<Alarm*> alarms;
    std::vector<Job*> jobs;



public:
    Device(/* args */);
    ~Device() {
        for (auto& it : variables) delete it;
        for (auto& it : collectors) delete it;
        for (auto& it : calculators) delete it;
        for (auto& it : commands) delete it.second;
        for (auto& it : alarms) delete it;
        for (auto& it : jobs) delete it;

    }
};
