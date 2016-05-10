//
// Created by Josh aka Bae on 21/03/2016.
//

#ifndef GRAPHDRAWINGTESTS_READEQUATION_H
#define GRAPHDRAWINGTESTS_READEQUATION_H

#include <iostream>
#include "ConvertEquation.h"
#include "muParser.h"

using namespace std;
using namespace mu;

Parser parser;

vector<float> ReadEquation(string equation) {
    double x = 0;

    parser.DefineVar("x", &x);
    parser.SetExpr(equation);


}

#endif //GRAPHDRAWINGTESTS_READEQUATION_H
