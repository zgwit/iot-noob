#pragma once

#include "define.hpp"

class Variable
{
public:
    std::string name;
    double _default; //д╛хож╣

    double value;

public:
    Variable(/* args */);
    ~Variable();

    void Load(cJSON* json) {
        name = json_get_string(json, "name");
        _default = json_get_number(json, "default");
        value = _default;
    }

    void Reset() {
        value = _default;
    }
};
