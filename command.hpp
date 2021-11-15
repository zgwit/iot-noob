#pragma once

#include "define.hpp"

class CommandDef: Define
{
public:
    std::string name;
    std::string label;

    std::vector<InstructionDefine> instructions;

    bool Parse(JsonDocument &doc);
};


class Command
{
private:
    /* data */
public:
    Command(/* args */);
    ~Command();
};

Command::Command(/* args */)
{
}

Command::~Command()
{
}
