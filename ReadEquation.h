//
// Created by Josh aka Bae on 21/03/2016.
//

#ifndef GRAPHDRAWINGTESTS_READEQUATION_H
#define GRAPHDRAWINGTESTS_READEQUATION_H

#include <iostream>
#include <cstdio>
#include <string>
#include "exprtk.hpp"

#include <cstdio>
#include <string>
#include "exprtk.hpp"


template <typename T>
void trig_function()
{
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;

    std::string expression_string = "clamp(-1.0,sin(2 * pi * x) + cos(x / 2 * pi),+1.0)";

    T x;

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(expression_string,expression);
}

#endif //GRAPHDRAWINGTESTS_READEQUATION_H
