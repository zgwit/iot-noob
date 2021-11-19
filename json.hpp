#pragma once

#include "cjson/cJSON.h"

#define json_get(json, name) \
	cJSON_GetObjectItem(json, #name)

#define json_get_int(to, json, name) \
	{	\
		auto tmp = cJSON_GetObjectItem(json, #name); \
		if (tmp && cJSON_IsNumber(tmp)) to->name = tmp->valueint; \
	}

#define json_get_number(to, json, name) \
	{	\
		auto tmp = cJSON_GetObjectItem(json, #name); \
		if (tmp && cJSON_IsNumber(tmp)) to->name = tmp->valuedouble; \
	}

#define json_get_string(to, json, name) \
	{	\
		auto tmp = cJSON_GetObjectItem(json, #name); \
		if (tmp && cJSON_IsString(tmp)) to->name = tmp->valuestring; \
	}

#define json_get_bool(to, json, name) \
	{	\
		auto tmp = cJSON_GetObjectItem(json, #name); \
		if (tmp && cJSON_IsBool(tmp)) to->name = (bool)tmp->valueint; \
	}

#define json_array_size(json) \
	cJSON_IsArray(json) ? cJSON_GetArraySize(json) : 0

#define json_is_bool(json) cJSON_IsBool(json)
#define json_is_number(json) cJSON_IsNumber(json)
#define json_is_string(json) cJSON_IsString(json)
#define json_is_object(json) cJSON_IsObject(json)
#define json_is_array(json) cJSON_IsArray(json)
#define json_is_null(json) cJSON_IsNull(json)

#define json_array_foreach(json, iter) \
	for(auto iter = (json)->child; iter != NULL; iter = iter->next)

#define json_create cJSON_CreateObject
#define json_delete cJSON_Delete

#define json_set_bool(json, name, value) cJSON_AddBoolToObject(json, #name, value)
#define json_set_int(json, name, value) cJSON_AddNumberToObject(json, #name, value)
#define json_set_number(json, name, value) cJSON_AddNumberToObject(json, #name, value)
#define json_set_string(json, name, value) cJSON_AddStringToObject(json, #name, value)
#define json_set_object(json, name, value) cJSON_AddObjectToObject(json, #name, value)
#define json_set_null(json, name) cJSON_AddNullToObject(json, #name)
