//
// Created by Josh aka Bae on 10/05/2016.
//

#ifndef GRAPHDRAWINGTESTS_REARRANGEEQ_H
#define GRAPHDRAWINGTESTS_REARRANGEEQ_H

#include <iostream>
#include <c++/bits/stl_bvector.h>
#include <c++/bits/algorithmfwd.h>

bool is_digits(const std::string &str);

using namespace std;

string RearrageEquation (string equation) {
    vector<string> equationArray;

    for (int i = 0; i < equation.length(); ++i) {
        if (is_digits(equationArray.at(i - 1))) {

        }
    }
}

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

#endif //GRAPHDRAWINGTESTS_REARRANGEEQ_H
