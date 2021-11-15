#pragma once

#include <ctype.h>

class Expression
{
private:
    typedef enum
    {
        OP_NONE,

        OP_DOT, // .

        OP_NEG,   // - 负
        OP_L_NOT, // ！ 非
        OP_NOT,   // ~ 反

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

        OP_AND, // &
        OP_OR,  // |
        OP_XOR, // ^

        OP_L_AND, // &&
        OP_L_OR,  // ||

        OP_LET,   // =
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
