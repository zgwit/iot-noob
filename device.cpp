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

    auto items = json_get(json, "points");
    json_array_foreach(items, item) {
        auto c = new Point();
        c->Load(item);
        points.push_back(c);
    }
    items = json_get(json, "variables");
    json_array_foreach(items, item) {
        auto var = new Variable();
        var->Load(item);
        context.Set(var->name, var);
    }
    items = json_get(json, "collectors");
    json_array_foreach(items, item) {
        auto c = new Collector();
        c->Load(item);
        collectors.push_back(c);
    }
    items = json_get(json, "calculators");
    json_array_foreach(items, item) {
        auto c = new Calculator();
        c->Load(item, context);
        calculators.push_back(c);
    }
    items = json_get(json, "commands");
    json_array_foreach(items, item) {
        auto c = new Command();
        c->Load(item, app, this);
        commands.push_back(c);
        commandsIndex[c->name] = c;
    }
    items = json_get(json, "alarms");
    json_array_foreach(items, item) {
        auto a = new Alarm();
        a->Load(item, context);
        alarms.push_back(a);
    }
    items = json_get(json, "jobs");
    json_array_foreach(items, item) {
        auto j = new Job();
        j->Load(item, app, this);
        jobs.push_back(j);
    }
}

Variable* Device::findVariable(const std::string& name) {
    return nullptr;


}

void Device::Start() {
    for (auto& c : collectors)
        if (c->enable)
            c->Start();
    for (auto& j : jobs)
        if (j->enable)
            j->Start();
}

void Device::Stop() {
    for (auto& c : collectors)
        c->Stop();
    for (auto& j : jobs)
        j->Stop();
}
