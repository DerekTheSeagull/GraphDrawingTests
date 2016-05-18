//
// Created by Josh aka Bae on 09/02/2016.
//

#ifndef GRAPHDRAWINGTESTS_CONVERTEQUATION_H
#define GRAPHDRAWINGTESTS_CONVERTEQUATION_H

#include <iostream>
#include <map>
#include <c++/vector>

using namespace std;
bool inString(string s, char d);

map<char, pair<string, string>> mConditionalConversions;

void initialiseMap() {
    mConditionalConversions['x'] = make_pair("0123456789)", "*x");
    mConditionalConversions['y'] = make_pair("0123456789)", "*y");
    mConditionalConversions['('] = make_pair("0123456789)", "*(");
    mConditionalConversions['s'] = make_pair("0123456789)", "*s");
    mConditionalConversions['c'] = make_pair("0123456789)", "*c");
    mConditionalConversions['t'] = make_pair("0123456789)", "*t");
}

string ConvertEquation(string sEquation) {
    string sFinalEquation;

    vector<char> prevChars;

    for (char c : sEquation) {
        if ( c != sEquation[0] && mConditionalConversions.find(c) != mConditionalConversions.end() &&
                inString(mConditionalConversions[c].first, prevChars.back())) {
                sFinalEquation += mConditionalConversions[c].second;
        } else {
            sFinalEquation += c;
        }

        prevChars.push_back(c);
    }

    return sFinalEquation;
}

bool inString(string s, char d) {
    for (char c : s) {
        if (c == d) {
            return true;
        }
    }

    return false;
}


#endif //GRAPHDRAWINGTESTS_CONVERTEQUATION_H
