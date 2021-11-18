#pragma once

#include "define.hpp"

class FileNode{
public:
    std::string name;
    time_t last;
    size_t size;
    bool isDir;
};

bool fs_init();

Pointer<std::vector<FileNode>> fs_list(const char *path);
bool fs_exists(const char *path);
bool fs_remove(const char *path);
bool fs_rename(const char *src, const char *dest);
bool fs_mkdir(const char *path);
bool fs_rmdir(const char *path);

//TODO 以下设计不合理，待优化
const uint8_t *file_read(const char *path);
bool file_write(const char *path, const uint8_t *buffer);
