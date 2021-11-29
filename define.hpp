#pragma once

#include <stdint.h>
#include <stddef.h>
#include <string.h>

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



struct StatusReset {
    int interval;
    int total;

    void Parse(cJSON* json) {
        json_member_get_int(this, json, interval);
        json_member_get_int(this, json, total);
    }
};




