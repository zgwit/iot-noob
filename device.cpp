#include "device.hpp"
#include "configure.hpp"


Device::Device(const std::string& id) {
	this->id = id;
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

void Device::Load(cJSON* json, Application* app) {
	this->enable = json_get_bool(json, "enable");
	this->name = json_get_string(json, "id");
	this->name = json_get_string(json, "name");
	auto items = json_get(json, "tags");
	json_array_foreach(items, item) {
		//TODO json_is_number, or error
		this->tags.push_back(item->valuestring);
	}
	this->slave = json_get_int(json, "slave");

	items = json_get(json, "points");
	json_array_foreach(items, item) {
		item = Config.Load("devices/" + this->id + "/points/" + item->valuestring + ".json");
		auto c = new Point();
		c->Load(item);
		points.push_back(c);
	}
	items = json_get(json, "variables");
	json_array_foreach(items, item) {
		item = Config.Load("devices/" + this->id + "/variables/" + item->valuestring + ".json");
		auto var = new Variable();
		var->Load(item);
		context.Set(var->name, var);
	}
	items = json_get(json, "collectors");
	json_array_foreach(items, item) {
		item = Config.Load("devices/" + this->id + "/collectors/" + item->valuestring + ".json");
		auto c = new Collector();
		c->Load(item);
		collectors.push_back(c);
	}
	items = json_get(json, "calculators");
	json_array_foreach(items, item) {
		item = Config.Load("devices/" + this->id + "/calculators/" + item->valuestring + ".json");
		auto c = new Calculator();
		c->Load(item, context);
		calculators.push_back(c);
	}
	items = json_get(json, "commands");
	json_array_foreach(items, item) {
		item = Config.Load("devices/" + this->id + "/commands/" + item->valuestring + ".json");
		auto c = new Command();
		c->Load(item, app, this);
		commands.push_back(c);
		commandsIndex[c->name] = c;
	}
	items = json_get(json, "alarms");
	json_array_foreach(items, item) {
		item = Config.Load("devices/" + this->id + "/alarms/" + item->valuestring + ".json");
		auto a = new Alarm();
		a->Load(item, context);
		alarms.push_back(a);
	}
	items = json_get(json, "jobs");
	json_array_foreach(items, item) {
		item = Config.Load("devices/" + this->id + "/jobs/" + item->valuestring + ".json");
		auto j = new Job();
		j->Load(item, app, this);
		jobs.push_back(j);
	};
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
