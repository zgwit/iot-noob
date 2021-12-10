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
    this->clean();
}

void Application::clean() {
    for (auto& it : devices) delete it;
    //for (auto& it : variables) delete it;
    for (auto& it : aggregators) delete it;
    for (auto& it : commands) delete it;
    for (auto& it : alarms) delete it;
    for (auto& it : jobs) delete it;
    for (auto& it : reactors) delete it;
}

void Application::Begin(const char* cfg) {
    auto json = Config.Load(cfg);
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

    this->clean();
}


static cJSON* load_child_config(cJSON* item, const std::string& base) {
    std::string id;
    if (json_is_string(item))
        id = item->valuestring;
    else if (json_is_number(item))
        id += item->valueint;
    else
        return nullptr;

    return Config.Load(base + "/" + id + ".json");
}


void Application::Load(cJSON* json)
{
    //TODO Ãû³Æ£¬°æ±¾ºÅµÈ
    auto items = json_get(json, "devices");
    json_foreach(items, [&, this](cJSON* item) {
        item = load_child_config(item, "devices");
        if (item) {
            auto dev = new Device();
            dev->Load(item, this);
            devices.push_back(dev);
            context.SetModule(dev->name, &dev->context);
        }
        });
        
    items = json_get(json, "variables");
    json_foreach(items, [&, this](cJSON* item) {
        item = load_child_config(item, "variables");
        if (item) {
            auto var = new Variable();
            var->Load(item);
            context.Set(var->name, var);
        }
        });

    items = json_get(json, "aggregators");
    json_foreach(items, [&, this](cJSON* item) {
        item = load_child_config(item, "aggregators");
        if (item) {
            auto c = new Aggregator();
            c->Load(item, this);
            aggregators.push_back(c);
        }
        });

    items = json_get(json, "commands");
    json_foreach(items, [&, this](cJSON* item) {
        item = load_child_config(item, "commands");
        if (item) {
            auto c = new Command();
            c->Load(item, this, nullptr);
            commands.push_back(c);
            commandsIndex[c->name] = c;
        }
        });

    items = json_get(json, "alarms");
    json_foreach(items, [&, this](cJSON* item) {
        item = load_child_config(item, "alarms");
        if (item) {
            auto a = new Alarm();
            a->Load(item, context);
            alarms.push_back(a);
        }
        });

    items = json_get(json, "jobs");
    json_foreach(items, [&, this](cJSON* item) {
        item = load_child_config(item, "jobs");
        if (item) {
            auto j = new Job();
            j->Load(item, this, nullptr);
            jobs.push_back(j);
        }
        });

    items = json_get(json, "reactors");
    json_foreach(items, [&, this](cJSON* item) {
        item = load_child_config(item, "reactors");
        if (item) {
            auto r = new Reactor();
            r->Load(item, context);
            reactors.push_back(r);
        }
        });

}

