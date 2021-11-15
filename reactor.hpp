#pragma once

class Reactor
{
private:
    /* data */
    std::string type; // gt lt
    std::string expression;
    std::string variable;
    std::string operator;
    double value;
    double value2;



public:
    Reactor(/* args */);
    ~Reactor();
};

Reactor::Reactor(/* args */)
{
}

Reactor::~Reactor()
{
}
