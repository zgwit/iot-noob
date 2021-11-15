#pragma once

#include <vector>

#include <ArduinoJson.hpp>

#include "variable.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "job.hpp"
#include "reactor.hpp"

class Project
{
private:
    std::string name;
    std::string version;

    std::vector<Variable> variables;
    std::vector<Command> commands;
    std::vector<Alarm> alarms;
    std::vector<Job> jobs;
    std::vector<Reactor> reactors;

public:
    Project(/* args */);
    ~Project();

    bool Parse(JsonDocument &doc);
};

Project::Project(/* args */)
{
}

Project::~Project()
{
}

bool Project::Parse(JsonDocument &doc) {
    


}
