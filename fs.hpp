#pragma once

#ifndef WIN32

#include <LittleFS.h>

#endif

void FileSystem_Init();

#define FileSystem LittleFS
// inline FS* FS_Get() { return LittleFS; }