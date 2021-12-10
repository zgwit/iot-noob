#include "application.hpp"
#include "configure.hpp"

Application App;

Application::Application(): context(), devices(), 
aggregators(), commands(), alarms(),
jobs(), reactors(), commandsIndex()
{

}

Application::~Application()
{
	for (auto& it : devices) delete it;
	//for (auto& it : variables) delete it;
	for (auto& it : aggregators) delete it;
	for (auto& it : commands) delete it;
	for (auto& it : alarms) delete it;
	for (auto& it : jobs) delete it;
	for (auto& it : reactors) delete it;
}

void Application::Begin(const char* cfg) {
    auto json = Config.Get(cfg);
    this->Load(json);

    for (auto& d : devices)
        if (d->enable)
            d->Start();
    for (auto& j : jobs)
        if (j->enable)
            j->Start();
}

void Application::End() {
    for (auto& d : devices)
        d->Stop();
    for (auto& j : jobs)
        j->Stop();
}


void Application::Load(cJSON* json)
{
    auto items = json_get(json, "devices");
    json_foreach(items, [&, this](cJSON* item) {
        auto d = new Device();
        d->Load(item, this);
        devices.push_back(d);
        //TODO ¼ÓÔØÅäÖÃÎÄ¼þ
        });
    items = json_get(json, "variables");
    json_foreach(items, [&, this](cJSON* item) {
        auto var = new Variable();
        var->Load(item);
        context.Set(var->name, var);
        });
    items = json_get(json, "aggregators");
    json_foreach(items, [&, this](cJSON* item) {
        auto c = new Aggregator();
        c->Load(item, this);
        aggregators.push_back(c);
        });
    items = json_get(json, "commands");
    json_foreach(items, [&, this](cJSON* item) {
        auto c = new Command();
        c->Load(item, this, nullptr);
        commands.push_back(c);
        commandsIndex[c->name] = c;
        });
    items = json_get(json, "alarms");
    json_foreach(items, [&, this](cJSON* item) {
        auto a = new Alarm();
        a->Load(item, context);
        alarms.push_back(a);
        });
    items = json_get(json, "jobs");
    json_foreach(items, [&, this](cJSON* item) {
        auto j = new Job();
        j->Load(item, this, nullptr);
        jobs.push_back(j);
        });
    items = json_get(json, "reactors");
    json_foreach(items, [&, this](cJSON* item) {
        auto r = new Reactor();
        r->Load(item, context);
        reactors.push_back(r);
        });

}

