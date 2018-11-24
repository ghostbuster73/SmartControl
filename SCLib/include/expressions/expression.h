#include <map>
#include <string>
#include <algorithm>

#include "exprtk.hpp"

using Variables = exprtk::symbol_table<double>;
using Formula = exprtk::expression<double>;
using Parser = exprtk::parser<double>;

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {

public:

    Expression();
    Expression(std::string id, std::string formula, Variables vars);
    Expression &operator=(const Expression &);
    ~Expression();

    //make constant reference to constant 
    //(it's bad to provide full access to variables to clients of this class)
    double * getValue();

    void connect(Expression * expr, std::string varName);

    double evaluate();

private:
    void setupParser();

private:
    std::string _id;
    std::string _expression;
    double * _value;

    //parser vars
    Variables _vars;
    Formula _formula;
    Parser _parser;
    
};


#endif