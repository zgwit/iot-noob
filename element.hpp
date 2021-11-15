#pragma once

#include <vector>

#include "job.hpp"
#include "collector.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "variable.hpp"
#include "sheet.hpp"

class Element
{
private:
    /* data */
    std::vector<Variable> variables;
    std::vector<Sheet> sheets;
    std::vector<Collector> collectors;
    std::vector<Command> commands;
    std::vector<Alarm> alarms;
    std::vector<Job> jobs;

public:
    Element(/* args */);
    ~Element();
};

Element::Element(/* args */)
{
}

Element::~Element()
{
}
