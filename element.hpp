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

class ElementDef : Define
{
public:
    std::string name;
    std::string version;
    ElementSlave slave;

    std::vector<VariableDef> variables;
    std::vector<SheetDef> sheets;
    std::vector<CollectorDef> collectors;
    std::vector<CommandDef> commands;
    std::vector<AlarmDef> alarms;
    std::vector<JobDef> jobs;
};
