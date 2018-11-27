#include <memory>
#include <algorithm>
#include <vector>
#include "expression.h"
#include "phase_expression.h"
#include "phase_solver.h"
#include <thread>
#include <iterator>
#include "exprtk.hpp"
#include "tinyxml2.h"

#include <boost/numeric/odeint.hpp>
#include <cmath>

using Variables = exprtk::symbol_table<double>;
using Formula = exprtk::expression<double>;
using Parser = exprtk::parser<double>;

using state_type = std::vector<double>;

class CauchyProblem {

public:
    CauchyProblem(double init_x, double init_y):
        _init_x(init_x), _init_y(init_y) { };

    void operator()(const state_type & x, state_type & dxdt, double t) {
        dxdt[0] = 2 * std::exp(pow(t, 2)) - x[0] / t;
    };

private:
    double _init_x;
    double _init_y;
};

double ode(double x, double t) {
    return 2 * std::exp(pow(t, 2)) - x / t;;
}

double runge_kutta_step(double x, double t, double step) {
    auto k1 = ode(x, t);
    auto k2 = ode(x + step / 2 * k1, t + step / 2);
    auto k3 = ode(x + step / 2 * k2, t + step / 2);
    auto k4 = ode(x + step * k3, t + step);
    return x + step / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
}

auto expression = std::make_shared<PhaseExpression>(
        1, 
        "2*exp(t^2)-x/t", 
        std::make_pair(0.0, 0.0));

double runge_kutta_step_expr(double x, double t, double step) {
 
    auto k1 = expression->evaluate(x, t);
    auto k2 = expression->evaluate(x + step / 2 * k1, t + step / 2);
    auto k3 = expression->evaluate(x + step / 2 * k2, t + step / 2);
    auto k4 = expression->evaluate(x + step * k3, t + step);
    return x + step / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
}

void cauchy_problem(const state_type & x, state_type & dxdt, double t) {
    dxdt[0] = 2 * std::exp(pow(t, 2)) - x[0] / t;
};

int main (int argc, char * argv[])
{
    const double t = 1;
    const double m_x = std::exp(1);
    const double step = 0.0000001;

    // auto system = CauchyProblem(1, std::exp(1));
    // auto stepper = boost::numeric::odeint::runge_kutta4<state_type>();

    // state_type x { std::exp(1) };
    //     // state_type x { 27.2991 };

    // boost::numeric::odeint::integrate_const(stepper, system, x, 1.0, 2.0, step);

    // std::cout<< "The solution at 2.0 is " << x[x.size() - 1] << std::endl;

    // auto expression = std::make_shared<PhaseExpression>(
    //     1, 
    //     "2*exp(t^2)-x/t", 
    //     std::make_pair(m_x, t));
    // auto solver = PhaseSolver(expression, std::make_pair(m_x, t));
    // auto result = solver.solve(2.0, step);
    // std::cout<< "The solution with CustomSolver at 2.0 is " << result << std::endl;

    auto correctColution = std::exp(pow(2, 2)) / 2;




    auto cur_x = m_x;
    for (double cur_t = t; cur_t <= 2; cur_t += step) {
        cur_x = runge_kutta_step(cur_x, cur_t, step);
    }

    std::cout << "Manual Runge-Kutta at point 2 is " << cur_x << std::endl;
    std::cout << "The right solution is " << correctColution << std::endl;

    // tinyxml2::XMLDocument printer;

    return 0;
}