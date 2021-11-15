#pragma once

#include "define.hpp"

#include "variable.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "job.hpp"
#include "reactor.hpp"

class ProjectDef {
public:
    std::string name;
    std::string version;

    std::vector<VariableDef> variables;
    std::vector<CommandDef> commands;
    std::vector<AlarmDef> alarms;
    std::vector<JobDef> jobs;
    std::vector<ReactorDef> reactors; 

    bool Parse(JsonDocument &doc);
};

class Project
{
private:
    ProjectDef* def;

    std::vector<Variable> variables;
    std::vector<Command> commands;
    std::vector<Alarm> alarms;
    std::vector<Job> jobs;
    std::vector<Reactor> reactors;

public:
    Project(/* args */);
    ~Project();
};

Project::Project(/* args */)
{
}

Project::~Project()
{
}

bool Project::Parse(JsonDocument &doc) {
    


}
