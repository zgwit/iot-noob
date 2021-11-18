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


#define Pointer std::shared_ptr


#define ARDUINOJSON_ENABLE_STD_STRING
//#include <ArduinoJson.hpp>
#include <ArduinoJson.h> //°üº¬using namespace ArduinoJson

class Proto
{
public:
    virtual bool Parse(JsonObject& obj) = 0;
};


typedef struct RangeTime {
    uint16_t start;
    uint16_t end;
}RangeTime;

typedef uint16_t RangeWeek;
#define testRangeWeek(r,d) ((0x1<<d)&r)
