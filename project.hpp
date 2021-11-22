#pragma once

#include "define.hpp"

#include "context.hpp"
#include "device.hpp"
#include "variable.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "job.hpp"
#include "reactor.hpp"

class ProjectProfile {
public:
    std::string name;
    std::string version;

    std::vector<DeviceProfile> devices;
    std::vector<VariableProfile> variables;
    std::vector<CommandProfile> commands;
    std::vector<AlarmProfile> alarms;
    std::vector<JobProfile> jobs;
    std::vector<ReactorProfile> reactors; 

    bool Parse(cJSON* json);
};

class Project
{
private:
    ProjectProfile* profile;

    Context context;

    std::vector<Device*> devices;
    std::vector<Variable> variables;
    std::vector<Command> commands;
    std::vector<Alarm> alarms;
    std::vector<Job> jobs;
    std::vector<Reactor> reactors;

public:
    Project(/* args */);
    ~Project();
};
