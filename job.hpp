#pragma once

#include "define.hpp"

class JobProfile
{
public:
    std::string type; //daily, crontab

    uint16_t minues; //daily 零点起分钟数
    uint16_t weeks; //daily 每周生效日

    std::string crontab; //crontab

    std::vector<InvokeProfile> commands;
};

class Job
{
private:
    JobProfile* profile;
    
public:
    Job(/* args */);
    ~Job();
};

Job::Job(/* args */)
{
}

Job::~Job()
{
    //proto->commands.data();
}
