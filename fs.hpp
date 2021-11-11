#pragma once

#include <LittleFS.h>

void FileSystem_Init();

#define FileSystem LittleFS
// inline FS* FS_Get() { return LittleFS; }