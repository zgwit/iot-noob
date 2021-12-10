#include "point.hpp"

Point::Point(/* args */)
{
}

Point::~Point()
{
}

void Point::Load(cJSON* json) {
    this->name  = json_get_string(json, "name");
    this->value = json_get_number(json, "default");
    const char* tp = json_get_string(json, "type");
    type = parseType(tp);

    this->interval  = json_get_int(json, "interval");
    this->crontab  = json_get_string(json, "crontab");

    this->code  = json_get_int(json, "code");
    this->address  = json_get_int(json, "address");
    this->precision  = json_get_int(json, "precision");

    this->littleEndian  = json_get_bool(json, "littleEndian");

    filter.Load(json_get(json, "filter"));
}

