#include "../fs.hpp"

#include<filesystem>

void fs_list(const char* path) {
	//std::filesystem::directory_entry entry(path);

	std::filesystem::directory_iterator dir(path);
	for (auto it : dir) {
		//it.file_size();
	}

	return;
}

