#include "../configure.hpp"

#include <filesystem>
#include <fstream>


Configure Config("config/");

Configure::Configure(const char* base):base(base)
{
}

Configure::~Configure()
{
}

bool Configure::Clear() {
	std::filesystem::remove_all(base);
	return true;
}

bool Configure::Remove(const char* path) {
	return std::filesystem::remove(base + path);
}

bool Configure::Exists(const char* path) {
	return std::filesystem::exists(path);
}

bool Configure::Set(const char* path, cJSON* json) {
	auto filename = base + path;
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

cJSON* Configure::Get(const char* path) {
	auto filename = base + path;
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

