//
// Created by Josh aka Bae on 09/02/2016.
//

#ifndef GRAPHDRAWINGTESTS_CONVERTEQUATION_H
#define GRAPHDRAWINGTESTS_CONVERTEQUATION_H

#include <iostream>
#include <string.h>

using namespace std;

const int iArrayHeight = 6;

pair <bool, int> InArray(pair <const char*, pair<string, string>> aArray[iArrayHeight][1], const char* cTarget);

bool InString(string sString, const char* cTarget);

string ConvertEquation(string sEquation) {
    string sFinalEquation;
    const char* csEquation = sEquation.c_str();

    pair <const char*, pair<string, string>> aConditionalConversions[iArrayHeight][1];
    aConditionalConversions[0][0] = make_pair("x", make_pair("0123456789(", "*x"));
    aConditionalConversions[1][0] = make_pair("y", make_pair("0123456789(", "*y"));
    aConditionalConversions[2][0] = make_pair("s", make_pair("0123456789(", "*s"));
    aConditionalConversions[3][0] = make_pair("c", make_pair("0123456789(", "*c"));
    aConditionalConversions[4][0] = make_pair("t", make_pair("0123456789(", "*t"));
    aConditionalConversions[5][0] = make_pair("(", make_pair("0123456789(", "*("));


    for (int i = 0; i < sEquation.length(); ++i) {
        const char* ccCurrentChar = &csEquation[i];

        pair <bool, int> inArray;
        bool inString;

        inArray = InArray(aConditionalConversions, ccCurrentChar);

        inString = aConditionalConversions[inArray.second][0].second.first.find(sEquation[i-1]);

        if (i > 0 && inArray.first && inString) {
            sFinalEquation += aConditionalConversions[inArray.second][0].second.second;
        }
        else {
            sFinalEquation += sEquation[i];
        }
    }


    return sFinalEquation;
}

pair <bool, int> InArray(pair <const char*, pair<string, string>> aArray[iArrayHeight][1], const char* cTarget) {
    for (int i = 0; i < iArrayHeight; ++i) {
        if(strcmp(cTarget, aArray[i][0].first) == 0) {
            return make_pair(true, i);
        }
    }

    return make_pair(false, 0);
}

bool InString(string sString, const char* cTarget) {
    for (int i = 0; i < sString.length(); ++i) {
        char cCurrentChar = sString[i];

        if (strcmp(cTarget, &cCurrentChar) == 0) {
            return true;
        }
    }

    return false;
}

#endif //GRAPHDRAWINGTESTS_CONVERTEQUATION_H
