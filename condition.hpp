#pragma once

#include "define.hpp"
#include "variable.hpp"
#include "context.hpp"

class CompareProfile
{
public:
    std::string device;
    std::string variable;

    std::string type;

    double value;

    bool Parse(cJSON* json);
};

class ConditionProfile
{
public:
    //bool both;
    std::string type; //and or
    std::vector<CompareProfile> compares;
    std::vector<ConditionProfile> children;

    bool Parse(cJSON* json);
};


class Compare
{
public:
    CompareProfile* profile;

    enum class OP
    {
        NONE = 0,
        LT,
        LE,
        EQ,
        NE,
        GT,
        GE,
    };

    OP compare;

    Variable* variable;


public:
    Compare();
    ~Compare();

    bool Evaluate() {
        switch (compare)
        {
        case OP::LT: return variable->value < profile->value; 
        case OP::LE: return variable->value <= profile->value; 
        case OP::EQ: return variable->value == profile->value; 
        case OP::NE: return variable->value != profile->value;
        case OP::GT: return variable->value > profile->value;
        case OP::GE: return variable->value >= profile->value;
        default:
            return false;
        }
    }

private:
    OP ParseOperator(const char* op);
};

class Condition
{
public:
    bool both;
    std::vector<Compare*> compares;
    std::vector<Condition*> children;

public:
    Condition(ConditionProfile* profile, const Context& ctx);
    ~Condition();

    bool Evaluate() {
        if (both) {
            for (auto& it : compares)
                if (!it->Evaluate())
                    return false;
            for (auto& it : children)
                if (!it->Evaluate())
                    return false;
            return true;
        }else{
            for (auto& it : compares)
                if (it->Evaluate())
                    return true;
            for (auto& it : children)
                if (it->Evaluate())
                    return true;
            return false;
        }
    }

private:

};
