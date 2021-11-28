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

    void SetValue(const std::string& name, double value) {
        auto iter = _props.find(name);
        if (iter != _props.end()) {
            iter->second->value = value;
        }
    }


    double GetValue(const std::string& name) {
        auto iter = _props.find(name);
        if (iter != _props.end()) {
            return iter->second->value;
        }
        return NAN;
    }

    void Set(const std::string& name, Variable* var) {
        auto iter = _props.find(name);
        if (iter != _props.end() && iter->second != var) {
            delete iter->second;
        }
        _props[name] = var;
    }

    void SetModule(const std::string& name, Context* ctx) {
        auto iter = _modules.find(name);
        if (iter != _modules.end() && iter->second != ctx) {
            delete iter->second;
        }
        _modules[name] = ctx;
    }

    cJSON* toJSON() {
        auto json = json_create();
        for (auto &iter : _props) {
            cJSON_AddNumberToObject(json, iter.first.c_str(), iter.second->value);
        }
        for (auto& iter : _modules) {
            cJSON_AddItemToObject(json, iter.first.c_str(), iter.second->toJSON());
        }
        return json;
    }
};
