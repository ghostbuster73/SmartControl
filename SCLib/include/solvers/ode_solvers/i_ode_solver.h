#ifndef I_SOLVER_H
#define I_SOLVER_H

class IODESolver {

virtual double solve(double x, double t) = 0;

};

#endif