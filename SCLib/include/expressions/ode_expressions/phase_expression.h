#include <string>
#include <vector>
#include <utility>

#include "expression.h"

#ifndef PHASE_EXPRESSION_H
#define PHASE_EXPRESSION_H

using state_type = std::vector<double>;
using initial_value = std::pair<double, double>;

class PhaseExpression {
public:
    PhaseExpression(int, std::string, initial_value);
    PhaseExpression(const PhaseExpression & phaseExpr);
    PhaseExpression &operator=(const PhaseExpression & phaseExpr);

    void operator()(const state_type & x, state_type & dxdt, double t) {
        dxdt[0] = evaluate(x[0], t);
    };

    double evaluate(double, double);
   
    void connectExpression(PhaseExpression phaseExpr, std::string name);

private:
    double _x;
    double _t;
    Expression _expr;
};

#endif