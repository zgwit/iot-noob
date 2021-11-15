#pragma once

#include "define.hpp"

class Compare : Proto
{
public:
    typedef enum
    {
        OP_NONE,
        OP_LT,
        OP_LE,
        OP_EQ,
        OP_NE,
        OP_GT,
        OP_GE,
        OP_BT,
        OP_NB,
    } OP;

    OP ParseOperator(const char *op);
}

Compare::OP
Compare::ParseOperator(const char *op)
{
    if (!strcmp(op, "lt") || !strcmp(op, "<"))
        return OP_LT;
    if (!strcmp(op, "le") || !strcmp(op, "<="))
        return OP_LE;
    if (!strcmp(op, "eq") || !strcmp(op, "=="))
        return OP_EQ;
    if (!strcmp(op, "ne") || !strcmp(op, "!="))
        return OP_NE;
    if (!strcmp(op, "gt") || !strcmp(op, ">"))
        return OP_GT;
    if (!strcmp(op, "ge") || !strcmp(op, ">="))
        return OP_GE;
    if (!strcmp(op, "bt") || !strcmp(op, "~"))
        return OP_BT;
    if (!strcmp(op, "nb") || !strcmp(op, "!~"))
        return OP_NB;
    return OP_NONE;
}
