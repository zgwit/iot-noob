#pragma once

#include "define.hpp"

class Job : Proto
{
public:
    std::string type;
    std::string crontab;
    uint16_t interval;

    std::vector<Command*> commands;
};

class JobInstance
{
private:
    Job* proto;
    
public:
    JobInstance(/* args */);
    ~JobInstance();
};

JobInstance::JobInstance(/* args */)
{
}

JobInstance::~JobInstance()
{
}
