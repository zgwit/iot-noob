#pragma once

#include <vector>

#include "variable.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "job.hpp"
#include "reactor.hpp"

class Project
{
private:
    /* data */
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
