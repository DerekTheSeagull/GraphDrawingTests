//
// Created by Josh aka Bae on 21/03/2016.
//

#ifndef GRAPHDRAWINGTESTS_READEQUATION_H
#define GRAPHDRAWINGTESTS_READEQUATION_H

#include <iostream>
#include "ConvertEquation.h"
#include <muParser.h>

using namespace std;
using namespace mu;

Parser parser;

map<double, double> ReadEquation(string equation) {
    map<double, double> mValues;

    double x = -500;

    parser.DefineVar("x", &x);
    parser.SetExpr(equation);

    for (float i = 0; i < 1000; i += 0.01) {
        mValues[x] = parser.Eval();

        x += 0.01;
    }

    return mValues;
}

#endif //GRAPHDRAWINGTESTS_READEQUATION_H
