#include "collector.hpp"


Collector::Collector(/* args */)
{
}

Collector::~Collector()
{
}

void Collector::Load(cJSON* json) {
    enable = json_get_bool(json, "enable");
    type = json_get_string(json, "type");
    interval = json_get_int(json, "interval");
    crontab = json_get_string(json, "crontab");
    code = json_get_int(json, "code");
    address = json_get_int(json, "address");
    length = json_get_int(json, "length");
    //filter.Parse(json_get(json, "filter"));
}
