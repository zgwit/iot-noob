#pragma once

#include "define.hpp"

#include "variable.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "job.hpp"
#include "reactor.hpp"

class Project {
public:
    std::string name;
    std::string version;

    std::vector<Variable> variables;
    std::vector<Command> commands;
    std::vector<Alarm> alarms;
    std::vector<Job> jobs;
    std::vector<Reactor> reactors; 

    bool Parse(JsonDocument &doc);
};

class ProjectInstance
{
private:
    Project* proto;

    std::vector<Variable> variables;
    std::vector<Command> commands;
    std::vector<Alarm> alarms;
    std::vector<Job> jobs;
    std::vector<Reactor> reactors;

public:
    ProjectInstance(/* args */);
    ~ProjectInstance();
};

ProjectInstance::ProjectInstance(/* args */)
{
}

ProjectInstance::~ProjectInstance()
{
}
