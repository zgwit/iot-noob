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

#include "cjson/cJSON.h"


#define Pointer std::shared_ptr


class Proto
{
public:
    virtual bool Parse(cJSON* json) = 0;
};


typedef struct RangeTime {
    uint16_t start;
    uint16_t end;
}RangeTime;

typedef uint16_t RangeWeek;
#define testRangeWeek(r,d) ((0x1<<d)&r)



