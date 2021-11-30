#include "app.hpp"


App::App()
{
}

App::~App()
{
	for (auto& it : devices) delete it;
	//for (auto& it : variables) delete it;
	for (auto& it : aggregators) delete it;
	for (auto& it : commands) delete it;
	for (auto& it : alarms) delete it;
	for (auto& it : jobs) delete it;
	for (auto& it : reactors) delete it;
}


void App::Load(cJSON* json)
{
    json_array_foreach(json_get(json, "devices"), item) {
        auto d = new Device();
        d->Load(item, this);
        devices.push_back(d);
        //TODO ¼ÓÔØÅäÖÃÎÄ¼þ
    }
    json_array_foreach(json_get(json, "variables"), item) {
        auto var = new Variable();
        var->Load(item);
        context.Set(var->name, var);
    }
    json_array_foreach(json_get(json, "aggregators"), item) {
        auto c = new Aggregator();
        c->Load(item, this);
        aggregators.push_back(c);
    }
    json_array_foreach(json_get(json, "commands"), item) {
        auto c = new Command();
        c->Load(item, this, nullptr);
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
        j->Load(item, this, nullptr);
        jobs.push_back(j);
    }
    json_array_foreach(json_get(json, "reactors"), item) {
        auto r = new Reactor();
        r->Load(item, context);
        reactors.push_back(r);
    }

}

