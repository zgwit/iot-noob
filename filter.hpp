#pragma once

#include "define.hpp"

class FilterInterface {
public:
    virtual void Load(cJSON* json) = 0;
    virtual double Push(double value) = 0;
};

class FilterMedian: FilterInterface {
public:
    std::list<double> window;
    int size = 10;

    void Load(cJSON* json) {
        json_member_get_int(this, json, size);
    }

    double Push(double value) {
        window.push_back(value);
        if (window.size() > size) window.pop_front();
        auto sum = std::accumulate(window.begin(), window.end(), 0);
        return sum / window.size();
    }
};


class Filter
{
public:
    //FilterProfile* profile;
    std::vector<double> arguments;
    std::list<double> window;

    FilterInterface* filter;

public:
	Filter();
	~Filter();

    void Load(cJSON* json) {
        std::string alg = json_get_string(json, "type");
        //TODO 创建算法实例
        if (alg == "median") {
            filter = (FilterInterface*)new FilterMedian();
        }

        if (filter)
            filter->Load(json_get(json, "options"));
    }

    double Push(double value) {
        if (filter)
            return filter->Push(value);
        return value;
    }
};
