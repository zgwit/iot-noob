#pragma once

#include "cjson/cJSON.h"

inline cJSON* json_get(cJSON* json, const char* name) {
    return cJSON_GetObjectItem(json, name);
}

inline const char* json_get_string(cJSON* json, const char* name) {
    return cJSON_GetStringValue(cJSON_GetObjectItem(json, name));
}

inline double json_get_number(cJSON* json, const char* name) {
    return cJSON_GetNumberValue(cJSON_GetObjectItem(json, name));
}

inline int json_get_int(cJSON* json, const char* name) {
    auto item = cJSON_GetObjectItem(json, name);
    if (cJSON_IsNumber(item))
        return item->valueint;
    return 0;
}

inline bool json_get_bool(cJSON* json, const char* name) {
    return (bool)cJSON_IsTrue(cJSON_GetObjectItem(json, name));
}


inline bool json_is_bool(cJSON* json) {
    return cJSON_IsBool(json);
}

inline bool json_is_number(cJSON* json) {
    return cJSON_IsNumber(json);
}

inline bool json_is_string(cJSON* json) {
    return cJSON_IsString(json);
}

inline bool json_is_object(cJSON* json) {
    return cJSON_IsObject(json);
}

inline bool json_is_array(cJSON* json) {
    return cJSON_IsArray(json);
}

inline bool json_is_null(cJSON* json) {
    return cJSON_IsNull(json);
}

inline int json_array_size(cJSON* json) {
    return cJSON_GetArraySize(json);
}


inline cJSON* json_create() {
    return cJSON_CreateObject();
}

inline void json_delete(cJSON* json) {
    cJSON_Delete(json);
}

inline cJSON* json_set_bool(cJSON* json, const char* name, bool value) {
    return cJSON_AddBoolToObject(json, name, value);
}

inline cJSON* json_set_int(cJSON* json, const char* name, int value) {
    return cJSON_AddNumberToObject(json, name, value);
}

inline cJSON* json_set_number(cJSON* json, const char* name, bool value) {
    return cJSON_AddNumberToObject(json, name, value);
}

inline cJSON* json_set_string(cJSON* json, const char* name, const char* value) {
    return cJSON_AddStringToObject(json, name, value);
}

inline cJSON* json_set_object(cJSON* json, const char* name) {
    return cJSON_AddObjectToObject(json, name);
}

inline cJSON* json_set_null(cJSON* json, const char* name) {
    return cJSON_AddNullToObject(json, name);
}


//使用Lambda函数，徒增代码量，丑，不方便（C++闭包真难受）
template<class _FN>
void json_foreach(cJSON* json, _FN fn) {
    for (cJSON* item = (json != NULL) ? (json)->child : NULL; item != NULL; item = item->next)
        fn(item);
}


//#define json_array_foreach(items, item) cJSON_ArrayForEach(item, items)
#define json_array_foreach(items, item) for (cJSON* item = (items != nullptr) ? (items)->child : nullptr; item != nullptr; item = item->next)

