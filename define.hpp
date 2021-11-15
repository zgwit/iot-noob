#pragma once

#include <ArduinoJson.hpp>

virtual class Define
{
public:
    virtual bool Parse(JsonDocument &doc);
};
