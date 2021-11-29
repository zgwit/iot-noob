#pragma once

#include "define.hpp"
#include "filter.hpp"



class Collector
{
public:
    bool enable;

private:
    std::string type; // interval, clock, crontab

    int interval; // seconds
    std::string crontab;

    int code;
    int address;
    int length;

    //Filter filter;
    
public:
    Collector(/* args */);
    ~Collector();

    void Load(cJSON* json);

    void Start(){}
    void Stop(){}
};
