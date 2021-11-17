#pragma once

#include "define.hpp"

class FileNode{
public:
    std::string name;
    time_t last;
    size_t length;
    bool isDirectory;
};

void fs_init();

pointer<std::vector<FileNode>> fs_dir(std::string path);
bool fs_exists(const char *path);
void fs_remove(const char *path);
void fs_rename(const char *src, const char *dest);
void fs_mkdir(const char *path);
void fs_rmdir(const char *path);

//TODO 以下设计不合理
const uint8_t *file_read(const char *path);
void file_write(const char *path, const uint8_t *buffer);
