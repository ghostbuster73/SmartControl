#include <memory>
#include <string>
#include <iostream>

#include "phase_expression.h"


class PhaseSolver {

public:

    PhaseSolver(std::shared_ptr<PhaseExpression> expression, initial_value initial);
    double solve(double end, double step);
private:
    std::shared_ptr<PhaseExpression> expr;
    initial_value _initial;
};