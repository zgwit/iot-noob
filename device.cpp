#include "device.hpp"


Device::Device(/* args */)
{
}

Device::~Device()
{
    //for (auto& it : variables) delete it;
    for (auto& it : points) delete it;
    for (auto& it : collectors) delete it;
    for (auto& it : calculators) delete it;
    for (auto& it : commands) delete it;
    for (auto& it : alarms) delete it;
    for (auto& it : jobs) delete it;
}

void Device::Load(cJSON* json, App* app) {
    json_member_get_bool(this, json, enable);
    json_member_get_string(this, json, name);
    json_member_get_string_array(this, json, tags);
    json_member_get_string(this, json, element);
    json_member_get_int(this, json, slave);

    json_array_foreach(json_get(json, "points"), item) {
        auto c = new Point();
        c->Load(item);
        points.push_back(c);
    }
    json_array_foreach(json_get(json, "variables"), item) {
        auto var = new Variable();
        var->Load(item);
        context.Set(var->name, var);
    }
    json_array_foreach(json_get(json, "collectors"), item) {
        auto c = new Collector();
        c->Load(item);
        collectors.push_back(c);
    }
    json_array_foreach(json_get(json, "calculators"), item) {
        auto c = new Calculator();
        c->Load(item, context);
        calculators.push_back(c);
    }
    json_array_foreach(json_get(json, "commands"), item) {
        auto c = new Command();
        c->Load(item, app, this);
        commands.push_back(c);
        commandsIndex[c->name] = c;
    }
    json_array_foreach(json_get(json, "alarms"), item) {
        auto a = new Alarm();
        a->Load(item, context);
        alarms.push_back(a);
    }
    json_array_foreach(json_get(json, "jobs"), item) {
        auto j = new Job();
        j->Load(item, app, this);
        jobs.push_back(j);
    }
}

Variable* Device::findVariable(const std::string& name) {
    return nullptr;


}
