#pragma once

#include "define.hpp"

#include "context.hpp"
#include "device.hpp"
#include "variable.hpp"
#include "aggregator.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "job.hpp"
#include "reactor.hpp"


class App
{
private:
    Context context;

    std::vector<Device*> devices;
    //std::vector<Variable*> variables;
    std::vector<Aggregator*> aggregators;
    std::vector<Command*> commands;
    std::vector<Alarm*> alarms;
    std::vector<Job*> jobs;
    std::vector<Reactor*> reactors;

    std::map<std::string, Command*> commandsIndex;
public:
    App();
    ~App();

    void Load(cJSON* json);

    void findDevice(const std::string& name, std::vector<Device*>& devices) {}
};
