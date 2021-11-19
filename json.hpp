#pragma once

#include "cjson/cJSON.h"

#define json_get(json, name) cJSON_GetObjectItem(json, #name)

#define json_get_int(to, json, name) {	\
		auto item = cJSON_GetObjectItem(json, #name); \
		if (cJSON_IsNumber(item)) to->name = item->valueint; \
	}

#define json_get_number(to, json, name) {	\
		auto item = cJSON_GetObjectItem(json, #name); \
		if (cJSON_IsNumber(item)) to->name = item->valuedouble; \
	}

#define json_get_string(to, json, name) {	\
		auto item = cJSON_GetObjectItem(json, #name); \
		if (cJSON_IsString(item)) to->name = item->valuestring; \
	}

#define json_get_bool(to, json, name) {	\
		auto item = cJSON_GetObjectItem(json, #name); \
		if (cJSON_IsBool(item)) to->name = (bool)item->valueint; \
	}

#define json_get_object(to, json, name) { \
		auto item = cJSON_GetObjectItem(json, #name);\
		if (cJSON_IsObject(item)) to->name.Parse(item); \
	}

#define json_get_bool_array(to, json, name) { \
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

#define json_get_int_array(to, json, name) { \
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

#define json_get_number_array(to, json, name) { \
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


#define json_get_string_array(to, json, name) { \
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
#define json_array_foreach(json, item) cJSON_ArrayForEach(item, json)

#define json_create() cJSON_CreateObject()
#define json_delete(json) cJSON_Delete(json)

#define json_set_bool(json, name, value) cJSON_AddBoolToObject(json, #name, value)
#define json_set_int(json, name, value) cJSON_AddNumberToObject(json, #name, value)
#define json_set_number(json, name, value) cJSON_AddNumberToObject(json, #name, value)
#define json_set_string(json, name, value) cJSON_AddStringToObject(json, #name, value)
#define json_set_object(json, name, value) cJSON_AddObjectToObject(json, #name, value)
#define json_set_null(json, name) cJSON_AddNullToObject(json, #name)


