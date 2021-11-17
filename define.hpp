#pragma once

#include <stdint.h>
#include <stddef.h>

#include <cstdint>

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <numeric>
#include <algorithm>


#define pointer std::shared_ptr


#define ARDUINOJSON_ENABLE_STD_STRING
//#include <ArduinoJson.hpp>
#include <ArduinoJson.h> //°üº¬using namespace ArduinoJson

class Proto
{
public:
    virtual bool Parse(JsonObject& obj) = 0;
};
