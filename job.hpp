#pragma once

#include "define.hpp"

class Job : Proto
{
public:
    std::string type; //interval, daily, crontab
    uint32_t interval; //interval ms

    uint16_t minues; //daily ����������
    uint16_t weeks; //daily ÿ����Ч��

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
