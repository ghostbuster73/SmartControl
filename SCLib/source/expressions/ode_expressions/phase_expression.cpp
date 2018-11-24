#include <string>
#include "phase_expression.h"
#include "exprtk.hpp"

PhaseExpression::PhaseExpression(int number, std::string formula, initial_value initialValue) {
    _x = initialValue.first;
    _t = initialValue.second;
    Variables vars;
    vars.add_variable("t", _t);
    vars.add_variable("x", _x);
    _expr = Expression("x" + std::to_string(number), formula, vars);
}

PhaseExpression::PhaseExpression(const PhaseExpression & phaseExpr) {
    _x = phaseExpr._x;
    _t = phaseExpr._t;
    _expr = phaseExpr._expr;
}

PhaseExpression &PhaseExpression::operator=(const PhaseExpression & phaseExpr) {
    _x = phaseExpr._x;
    _t = phaseExpr._t;
    _expr = phaseExpr._expr;
    return *this;
}

void PhaseExpression::connectExpression(PhaseExpression phaseExpr, std::string name) {
    _expr.connect(&phaseExpr._expr, name);
}

double PhaseExpression::evaluate(double x, double t) {
    _x = x;
    _t = t;
    return _expr.evaluate();
}