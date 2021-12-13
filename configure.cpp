#include "configure.hpp"


Configure Config("config");

Configure::Configure(const std::string& base):base(base)
{
}

Configure::~Configure()
{
}

bool Configure::Clear() {

    return false;
}

bool Configure::Remove(const std::string& path) {
	
	return false;
}

bool Configure::Exists(const std::string& path) {
	return false;
}

bool Configure::Put(const std::string& path, cJSON* json) {


    return false;
}



cJSON* Configure::Load(const std::string& path) {



    return NULL;
}

std::string Configure::Resolve(const std::string& path) {
    return base + '\\' + path;
}

