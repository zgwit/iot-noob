#pragma once

#include "define.hpp"
#include "variable.hpp"
//#include "tinyexpr/tinyexpr.h"


class Context
{
private:
    /* data */
    std::map<std::string, Variable*> _props;
    std::map<std::string, Context*> _modules;

public:
    Context(/* args */);
    ~Context();

    //void getModified();

    void Set(const std::string& name, Variable* var);
    Variable* Get(const std::string& name);

    double GetValue(const std::string& name);
    void SetValue(const std::string& name, double value);

    void SetModule(const std::string& name, Context* ctx);
    cJSON* toJSON();
};
