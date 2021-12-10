#pragma once

#include "define.hpp"

class Configure
{
private:
    std::string base;

public:
    Configure(const std::string& base);
    ~Configure();

    bool Clear();
    bool Remove(const std::string& path);
    bool Exists(const std::string& path);

    bool Put(const std::string& path, cJSON* json);
    cJSON* Load(const std::string& path);

    std::string Resolve(const std::string& path);

private:

};

extern Configure Config;