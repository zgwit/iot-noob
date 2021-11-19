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

    bool Parse(cJSON* json);
};

class ElementProfile
{
public:
    std::string name;
    std::string version;
    ElementSlave slave;

    std::vector<VariableProfile> variables;
    std::vector<SheetProfile> sheets;
    std::vector<CollectorProfile> collectors;
    std::vector<CommandProfile> commands;
    std::vector<AlarmProfile> alarms;
    std::vector<JobProfile> jobs;

    bool Parse(cJSON* json);
};

