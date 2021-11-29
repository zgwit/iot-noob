#include "calculator.hpp"

void Calculator::Load(cJSON* json, const Context& ctx) {
    std::string var = json_get_string(json, "variable");
    std::string expr = json_get_string(json, "expression");

    variable = ctx.find(var);
    expression = new Expression(expr, ctx);
}

void Calculator::Evaluate() {
    variable->value = expression->Evaluate();
}
