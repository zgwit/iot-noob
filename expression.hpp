#pragma once

#include <ctype.h>

#include "variable.hpp"
#include "variant.hpp"
#include "context.hpp"

class Expression
{
private:
    typedef enum
    {
        OP_NONE,

        OP_DOT, // .

        OP_NEG,   // - 负
        OP_NOT, // ！ 非
        OP_BIT_NOT,   // ~ 反

        OP_ADD, // +
        OP_SUB, // -

        OP_MUL, // *
        OP_DIV, // /
        OP_REM, // % MOD

        OP_SHL, // <<
        OP_SHR, // >>

        OP_LT, // <
        OP_LE, // <=
        OP_EQ, // ==
        OP_NE, // !=
        OP_GT, // >
        OP_GE, // >=

        OP_BIT_AND, // &
        OP_BIT_OR,  // |
        OP_BIT_XOR, // ^

        OP_AND, // &&
        OP_OR,  // ||

        OP_ASSIGN,   // =
        OP_COMMA, // ,

        OP_VAR,
        OP_CONST,
        OP_CALL,
    } OP;

private:
    /* data */
public:
    Expression(/* args */);
    ~Expression();

    bool Parse(const char *expr);
    Variant *Eval(Context &ctx);

private:
    size_t cursor;
    size_t total;
    char peek();
    char next();

};

Expression::Expression(/* args */)
{
}

Expression::~Expression()
{
}

Variant *Expression::Eval(Context &ctx)
{
}
