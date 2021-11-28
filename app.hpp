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

class AppProfile {
public:
    std::string name;
    std::string version;

    std::vector<DeviceProfile> devices;
    std::vector<VariableProfile> variables;
    std::vector<AggregatorProfile> aggregators;
    std::vector<CommandProfile> commands;
    std::vector<AlarmProfile> alarms;
    std::vector<ReactorProfile> reactors; 
    std::vector<JobProfile> jobs;

    bool Parse(cJSON* json);
};

class App
{
private:
    AppProfile* profile;

    Context context;

    std::vector<Device*> devices;
    std::vector<Variable*> variables;
    std::vector<Aggregator*> aggregators;
    std::vector<std::string, Command*> commands;
    std::vector<Alarm*> alarms;
    std::vector<Job*> jobs;
    std::vector<Reactor*> reactors;

public:
    App(/* args */);
    ~App();
};
