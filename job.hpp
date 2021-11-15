#pragma once

#include "define.hpp"

class JobDef : Define
{
public:
    std::string type;
    std::string crontab;
    uint16_t interval;
    
    std::vector<CommandDef> commands;
};

class Job
{
private:
    JobDef *def;
    
public:
    Job(/* args */);
    ~Job();
};

Job::Job(/* args */)
{
}

Job::~Job()
{
}
