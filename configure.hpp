#pragma once

#include "define.hpp"

class Configure
{
private:
	std::string base;

public:
	Configure(const char* base);
	~Configure();

	bool Clear();
	bool Remove(const char* path);
	bool Exists(const char* path);

	bool Set(const char* path, cJSON* json);
	cJSON* Get(const char* path);

	std::string Resolve(const char* path){}

private:

};

extern Configure Config;