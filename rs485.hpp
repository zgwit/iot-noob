#pragma once

#include "define.hpp"


class RS485Adapter
{
public:

	bool available(){}
	void write(const char* buf, size_t len) {

	}

};

extern RS485Adapter RS485;