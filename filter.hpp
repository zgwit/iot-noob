#pragma once

#include "define.hpp"

class FilterInterface {
public:
    virtual void Load(cJSON* json) = 0;
    virtual double Push(double value) = 0;
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

    void Load(cJSON* json);

    double Push(double value);
};
