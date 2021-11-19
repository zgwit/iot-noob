#pragma once

#include <stdint.h>
#include <stddef.h>

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>

#include "json.hpp"
//#include "cjson/cJSON.h"


#define Pointer std::shared_ptr


class Proto
{
public:
    virtual bool Parse(cJSON* json) = 0;
};


struct DailyRange {
    uint16_t start;
    uint16_t end;

    void Parse(cJSON* json) {
        json_get_int(this, json, start);
        json_get_int(this, json, end);
    }
};

typedef uint16_t WeekRange;
#define testWeekRange(r,d) ((0x1<<d)&r)

struct StatusReset {
    unsigned int interval;
    unsigned int total;

    void Parse(cJSON* json) {
        json_get_int(this, json, interval);
        json_get_int(this, json, total);
    }
};




