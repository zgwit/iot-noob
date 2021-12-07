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

#define json_member_get_int(to, json, name) {	\
		auto item = cJSON_GetObjectItem(json, #name); \
		if (cJSON_IsNumber(item)) to->name = item->valueint; \
	}


#define json_member_get_number(to, json, name) {	\
		auto item = cJSON_GetObjectItem(json, #name); \
		if (cJSON_IsNumber(item)) to->name = item->valuedouble; \
	}

#define json_member_get_string(to, json, name) {	\
		auto item = cJSON_GetObjectItem(json, #name); \
		if (cJSON_IsString(item)) to->name = item->valuestring; \
	}

#define json_member_get_bool(to, json, name) {	\
		auto item = cJSON_GetObjectItem(json, #name); \
		if (cJSON_IsBool(item)) to->name = (bool)item->valueint; \
	}

#define json_get_object(to, json, name) { \
		auto item = cJSON_GetObjectItem(json, #name);\
		if (cJSON_IsObject(item)) to->name.Parse(item); \
	}

#define json_member_get_bool_array(to, json, name) { \
		auto arr = cJSON_GetObjectItem(json, #name);\
		if (cJSON_IsArray(arr)) { \
			vec.resize(cJSON_GetArraySize(arr));\
			auto iter = to->name.begin();\
			cJSON* item; \
			cJSON_ArrayForEach(json, item) {\
				*iter = (bool)item->valueint;\
				iter++;\
			}\
		}\
	}

#define json_member_get_int_array(to, json, name) { \
		auto arr = cJSON_GetObjectItem(json, #name);\
		if (cJSON_IsArray(arr)) { \
			to->name.resize(cJSON_GetArraySize(arr));\
			auto iter = to->name.begin();\
			cJSON* item; \
			cJSON_ArrayForEach(item, json) {\
				*iter = item->valueint;\
				iter++;\
			}\
		}\
	}

#define json_member_get_number_array(to, json, name) { \
		auto arr = cJSON_GetObjectItem(json, #name);\
		if (cJSON_IsArray(arr)) { \
			to->name.resize(cJSON_GetArraySize(arr));\
			auto iter = to->name.begin();\
			cJSON* item; \
			cJSON_ArrayForEach(item, json) {\
				*iter = item->valuedouble;\
				iter++;\
			}\
		}\
	}


#define json_member_get_string_array(to, json, name) { \
		auto arr = cJSON_GetObjectItem(json, #name);\
		if (cJSON_IsArray(arr)) { \
			to->name.resize(cJSON_GetArraySize(arr));\
			auto iter = to->name.begin();\
			cJSON* item; \
			cJSON_ArrayForEach(item, json) {\
				*iter = item->valuestring;\
				iter++;\
			}\
		}\
	}

#define json_get_object_array(to, json, name) { \
		auto arr = cJSON_GetObjectItem(json, #name);\
		if (cJSON_IsArray(arr)) { \
			to->name.resize(cJSON_GetArraySize(arr));\
			auto iter = to->name.begin();\
			cJSON* item; \
			cJSON_ArrayForEach(item, json) {\
				iter->Parse(item);\
				iter++;\
			}\
		}\
	}


#define json_is_bool(json) cJSON_IsBool(json)
#define json_is_number(json) cJSON_IsNumber(json)
#define json_is_string(json) cJSON_IsString(json)
#define json_is_object(json) cJSON_IsObject(json)
#define json_is_array(json) cJSON_IsArray(json)
#define json_is_null(json) cJSON_IsNull(json)

#define json_array_size(json) cJSON_GetArraySize(json)

#define json_array_foreach(json, item) \
	for(cJSON* item = (json != NULL) ? (json)->child : NULL; item != NULL; item = item->next)

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

template<class _FN>
void json_foreach(cJSON* json, _FN fn) {
	for (cJSON* item = (json != NULL) ? (json)->child : NULL; item != NULL; item = item->next)
	{
		fn(item);
	}
}

