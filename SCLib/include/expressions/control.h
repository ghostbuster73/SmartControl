#ifndef CONTROL_H
#define CONTROL_H

#include "expression.h"
#include <memory>
#include <vector>
#include <map>
#include <string>

using ControlParameters = std::vector<ControlParameterContainer>;
using ControlVector = std::vector<ControlExpression>;

class ControlFunction {
public:
    ControlFunction(ControlVector controlVector);
    double evaluate(int index, double t);

private:
    ControlVector cotrolVector;
};

class ControlExpression {

public:
    ControlExpression(ControlParameters parameters, double start, double end);

    double evaluate(double t);

private:
    std::unique_ptr<Expression> _expression;
    ControlParameterContainer currentContainer;
};


class ControlParameterContainer {

public:
    ControlParameterContainer(
        std::string formula,
        std::map<std::string, double> coeffs,
        double startTime,
        double endTime
    );

    bool canEvaluate();
    double evaluate(double t);

private:
    std::map<std::string, double> coeffs;
    double startTime;
    double endTime;
    std::string formula;
};

#endif CONTROL_H