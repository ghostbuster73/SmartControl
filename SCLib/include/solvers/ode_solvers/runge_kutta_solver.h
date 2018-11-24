#ifndef RUNGE_KUTTA_SOLVER_H
#define RUNGE_KUTTA_SOLVER_H

#include "i_ode_solver.h"

class RungeKuttaSolver: public IODESolver {

virtual double solve(double x, double t) override;

};

#endif