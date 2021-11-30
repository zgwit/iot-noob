#pragma once

#include "define.hpp"
#include "command.hpp"
#include "cron.hpp"

#include "ccronexpr/ccronexpr.h"
#include <sstream>

class App;
class Device;

class Job
{
private:
    bool enable;

    std::string type; //daily, crontab

    int clock; //daily 零点起分钟数
    std::vector<int> days; //daily 每周生效日

    std::string crontab; //crontab

    std::vector<Invoke*> invokes;


    CronJob* job;

    cron_expr cron;
    
public:
    Job(/* args */);
    ~Job();

    void Load(cJSON* json, App* app, Device* dev);

    void Execute() {
        for (auto& i : invokes)
            i->Execute();
    }

    const char* Parse() {
        //将 分钟表示 转成 crontab 标准表示
        if (type == "daily") {
            std::stringstream ss;
            //秒 分 时
            ss << "* "<<clock % 60 << " " << clock / 60;
            //日 月
            ss << " * * ";
            //周
            if (days.size() > 0) {
                auto iter = days.cbegin();
                ss << *iter;
                iter++;
                for (; iter != days.cend(); iter++) {
                    ss << "," << *iter;
                }
            } else {
                ss << "*";
            }
            ss >> crontab;
        }

        const char* error = nullptr;
        cron_parse_expr(crontab.c_str(), &cron, &error);
        return error;
    }
};
