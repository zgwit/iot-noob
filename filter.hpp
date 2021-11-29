#pragma once

#include "define.hpp"

class FilterProfile
{
public:
    std::string algorithm;
    std::vector<double> arguments;

    void Parse(cJSON* json)
    {
        json_member_get_string(this, json, algorithm);
        json_member_get_number_array(this, json, arguments);
    }
};

class Filter
{
public:
    FilterProfile* profile;

    //std::vector<double> window;
    std::list<double> window;

public:
	Filter();
	~Filter();

    double Push(double value);


private:

};


