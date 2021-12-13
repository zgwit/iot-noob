#pragma once

#include "define.hpp"
#include "filter.hpp"


class Point
{
public:
    enum class Type {
        NONE = 0,
        BIT,
        BYTE, //char
        UINT16,//WORD
        UINT32,//DWORD
        UINT64,//QWORD
        INT16,
        INT32,
        INT64,
        FLOAT, //float32
        DOUBLE, //double float64
    };

private:
    std::string name;
    //std::string label;
    //std::string unit;
    double value; //默认值
    //std::string type;
    Type type;

    std::string crontab;
    int interval;

    int code;
    int address;
    int precision;

    bool littleEndian;

    //滤波器
    Filter filter;

    Type parseType(const char* op) {
        if (!strcasecmp(op, "bit"))
            return Type::BIT;
        if (!strcasecmp(op, "byte") || !strcasecmp(op, "char"))
            return Type::BYTE;
        if (!strcasecmp(op, "word") || !strcasecmp(op, "uint16"))
            return Type::UINT16;
        if (!strcasecmp(op, "dword") || !strcasecmp(op, "uint32"))
            return Type::UINT32;
        if (!strcasecmp(op, "qword") || !strcasecmp(op, "uint64"))
            return Type::UINT64;
        if (!strcasecmp(op, "int16"))
            return Type::INT16;
        if (!strcasecmp(op, "int32"))
            return Type::INT32;
        if (!strcasecmp(op, "int64"))
            return Type::INT64;
        if (!strcasecmp(op, "float") || !strcasecmp(op, "float32"))
            return Type::FLOAT;
        if (!strcasecmp(op, "double") || !strcasecmp(op, "float64"))
            return Type::DOUBLE;
        return Type::NONE;
    }

    /* data */
public:
    Point(/* args */);
    ~Point();

    void Load(cJSON* json);
};
