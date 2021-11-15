#pragma once

#include "define.hpp"
#include "compare.hpp"

class Reactor: Proto
{
public:
    Compare compare;

};

class ReactorInstance {
public:
    Reactor* proto;


};

