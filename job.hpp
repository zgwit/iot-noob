#pragma once

#include "define.hpp"

class Job : Proto
{
public:
    std::string type; //interval, daily, crontab
    uint32_t interval; //interval ms

    uint16_t minues; //daily 零点起分钟数
    uint16_t weeks; //daily 每周生效日

    std::string crontab; //crontab

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
    //proto->commands.data();
}
