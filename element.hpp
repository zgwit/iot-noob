#pragma once

#include "define.hpp"

#include "job.hpp"
#include "collector.hpp"
#include "command.hpp"
#include "alarm.hpp"
#include "variable.hpp"
#include "sheet.hpp"

class ElementSlave
{
    uint8_t origin;
    uint16_t address;
    bool writable;
};

class Element : Proto
{
public:
    std::string name;
    std::string version;
    ElementSlave slave;

    std::vector<Variable*> variables;
    std::vector<Sheet*> sheets;
    std::vector<Collector*> collectors;
    std::vector<Command*> commands;
    std::vector<Alarm*> alarms;
    std::vector<Job*> jobs;
};
