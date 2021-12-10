#include "context.hpp"



Context::Context(/* args */)
{
}

Context::~Context()
{
    for (auto& it : _props) delete it.second;
}

void Context::SetValue(const std::string& name, double value) {
    auto iter = _props.find(name);
    if (iter != _props.end()) {
        iter->second->value = value;
    }
}

double Context::GetValue(const std::string& name) {
    auto iter = _props.find(name);
    if (iter != _props.end()) {
        return iter->second->value;
    }
    return NAN;
}

void Context::Set(const std::string& name, Variable* var) {
    auto iter = _props.find(name);
    if (iter != _props.end() && iter->second != var) {
        delete iter->second;
    }
    _props[name] = var;
}

Variable* Context::Get(const std::string& name) {
    auto iter = _props.find(name);
    return iter == _props.end() ? nullptr : iter->second;
}

void Context::SetModule(const std::string& name, Context* ctx) {
    auto iter = _modules.find(name);
    if (iter != _modules.end() && iter->second != ctx) {
        delete iter->second;
    }
    _modules[name] = ctx;
}

cJSON* Context::toJSON() {
    auto json = json_create();
    for (auto& iter : _props) {
        cJSON_AddNumberToObject(json, iter.first.c_str(), iter.second->value);
    }
    for (auto& iter : _modules) {
        cJSON_AddItemToObject(json, iter.first.c_str(), iter.second->toJSON());
    }
    return json;
}
