//
// Created by Josh aka Bae on 21/03/2016.
//

#ifndef GRAPHDRAWINGTESTS_READEQUATION_H
#define GRAPHDRAWINGTESTS_READEQUATION_H

#include <iostream>
#include "symbolicc++.h"
#include "ConvertEquation.h"
#include <vector>
#include <algorithm>

using namespace std;

const int pStrToSymbolHeight = 2;

list ReadEquation(string equation){
    pair<string, Symbolic> pStrToSymbol[pStrToSymbolHeight][0];
    pStrToSymbol[0][0] = make_pair("x", Symbolic("x"));
    pStrToSymbol[0][0] = make_pair("y", Symbolic("y"));

    "*";



}

#endif //GRAPHDRAWINGTESTS_READEQUATION_H
