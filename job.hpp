#pragma once

#include "define.hpp"
#include "command.hpp"

class JobProfile
{
public:
    bool enable;

    std::string type; //daily, crontab

    uint16_t daily; //daily 零点起分钟数
    WeekRange weekRange; //daily 每周生效日

    std::string crontab; //crontab

    std::vector<InvokeProfile> invokes;

    bool Parse(cJSON* json);
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
