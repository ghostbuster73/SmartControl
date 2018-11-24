#include "phase_solver.h"
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;

PhaseSolver::PhaseSolver(std::shared_ptr<PhaseExpression> expression, initial_value initial)
: expr(expression),
 _initial(initial) { }

double PhaseSolver::solve(double end, double step) {
    auto stepper = boost::numeric::odeint::runge_kutta4<state_type>();
    state_type x { _initial.first };
    boost::numeric::odeint::integrate_const(stepper, *expr, x, _initial.second, end, step);
    return x[x.size() - 1];
}