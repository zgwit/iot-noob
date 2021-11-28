#pragma once

#include "define.hpp"
#include "command.hpp"

#include "ccronexpr/ccronexpr.h"
#include <sstream>

class JobProfile
{
public:
    bool enable;

    std::string type; //daily, crontab

    int clock; //daily 零点起分钟数
    std::vector<int> days; //daily 每周生效日

    std::string crontab; //crontab

    std::vector<InvokeProfile> invokes;

    bool Parse(cJSON* json);
};

class Job
{
private:
    JobProfile* profile;

    cron_expr crontab;
    
public:
    Job(/* args */);
    ~Job();

    const char* Parse() {
        //将 分钟表示 转成 crontab 标准表示
        if (profile->type == "daily") {
            std::stringstream ss;
            //秒 分 时
            ss << "* "<<profile->clock % 60 << " " << profile->clock / 60;
            //日 月
            ss << " * * ";
            //周
            if (profile->days.size() > 0) {
                auto iter = profile->days.cbegin();
                ss << *iter;
                iter++;
                for (; iter != profile->days.cend(); iter++) {
                    ss << "," << *iter;
                }
            } else {
                ss << "*";
            }
            ss >> profile->crontab;
        }

        const char* error = nullptr;
        cron_parse_expr(profile->crontab.c_str(), &crontab, &error);
        return error;
    }
};
