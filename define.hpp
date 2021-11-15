#pragma once

#include <stdint.h>
#include <stddef.h>

#include <memory>
#include <string>
#include <vector>
#include <map>

#include <ArduinoJson.hpp>

class Proto
{
public:
    virtual bool Parse(JsonDocument &doc);
};
