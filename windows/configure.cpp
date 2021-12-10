#include "../configure.hpp"

#include <filesystem>
#include <fstream>


Configure Config("config");

Configure::Configure(const std::string& base):base(base)
{
}

Configure::~Configure()
{
}

bool Configure::Clear() {
	std::filesystem::remove_all(base);
	return true;
}

bool Configure::Remove(const std::string& path) {
	return std::filesystem::remove(this->Resolve(path));
}

bool Configure::Exists(const std::string& path) {
	return std::filesystem::exists(this->Resolve(path));
}

bool Configure::Put(const std::string& path, cJSON* json) {
	auto filename = this->Resolve(path);
	char* text = cJSON_Print(json);

	std::ofstream ofs(filename);
	if (!ofs.is_open()) {
		return false;
	}
	//ofs << text;
	ofs.write(text, strlen(text));
	cJSON_free(text);

	ofs.close();

	return true;
}

cJSON* Configure::Load(const std::string& path) {
	auto filename = this->Resolve(path);
	if (!std::filesystem::exists(filename))
		return nullptr;
	auto size = std::filesystem::file_size(filename);
	std::ifstream ifs(filename);
	char* buffer = new char[size+1];
	buffer[size] = '\0';
	if (!ifs.is_open()) {
		return nullptr;
	}
	ifs.read(buffer, size);
	ifs.close();

	auto json = cJSON_Parse(buffer);
	delete[] buffer;

	return json;
}

std::string Configure::Resolve(const std::string& path) {
	return base + '\\' + path;
}

