#include "fs.hpp"


#ifndef WIN32
#include <LittleFS.h>
#endif


void FileSystem_Init() {
    LittleFS.begin();
}