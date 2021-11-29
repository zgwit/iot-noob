#pragma once

#include "define.hpp"
#include "filter.hpp"

enum DataType {
    NONE = 0,
    BIT,
    BYTE,
    WORD,
    DWORD,
    INT,
    DINT,
    FLOAT,
    DOUBLE,
};

class PointProfile
{
public:
    std::string name;
    std::string label;
    std::string unit;
    double value; //默认值

    std::string type;
    //DataType type;

    std::string crontab;
    int interval;

    int code;
    int address;
    int precision;

    bool littleEndian;
    bool readable;
    bool writable;

    //滤波器
    //Filter filter;

    bool Parse(cJSON* json);
};

class Point
{
private:
    PointProfile *profile;

    /* data */
public:
    Point(/* args */);
    ~Point();
};
