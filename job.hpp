#pragma once

#include "define.hpp"

class JobProfile
{
public:
    std::string type; //daily, crontab

    uint16_t minues; //daily ����������
    uint16_t weeks; //daily ÿ����Ч��

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
