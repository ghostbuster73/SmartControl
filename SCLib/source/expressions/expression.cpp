#include "expression.h"
#include <iostream>

//constructors

Expression::Expression() {
    _id = "";
    _expression = "";
    _value = new double(0.0);
}

Expression::Expression(std::string id, std::string formula, Variables vars) {
    _id = id;
    
    _vars = vars;
    _expression = formula;
    _value = new double(0.0);
    setupParser();
}

Expression &Expression::operator=(const Expression & expr) {
    _id = expr._id;
    _expression = expr._expression;
    _value = expr._value;
    _vars = expr._vars;
    _formula = expr._formula;
    setupParser();

    return *this;
}

Expression::~Expression() {
    // delete _value;
}

//public interface inplementation

void Expression::connect(Expression * expr, std::string varName) {
    _vars.add_variable(varName, *expr->getValue());
    setupParser();
}

double Expression::evaluate() {
    *_value = _formula.value();
    return *_value;
}

double * Expression::getValue() {
    return _value;
}

//private section

void Expression::setupParser() {
    _formula.register_symbol_table(_vars);
    _parser.compile(_expression, _formula);
}