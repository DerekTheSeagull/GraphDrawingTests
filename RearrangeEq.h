//
// Created by Josh aka Bae on 10/05/2016.
//

#ifndef GRAPHDRAWINGTESTS_REARRANGEEQ_H
#define GRAPHDRAWINGTESTS_REARRANGEEQ_H

#include <iostream>
#include <c++/bits/algorithmfwd.h>
#include <c++/vector>
#include <c++/set>

using namespace std;

bool isoperator (char c);
bool is_alnum(string s);
vector<string> CreateVector(string s);
vector<string> LumpStrings(vector<string> v);

string RearrageEquation (string equation, string target) {
    vector<string> beforeEqls; vector<string> afterEqls;

    int eqlsPos;
    int vectorContainingTarget;

    for (int i = 0; i < equation.length(); ++i) { //find the position of the equals sign
        if (equation[i] == '=') {
            eqlsPos = i;
        }
    }

    //splits equation into two vectors, one for before the equals and one for after
    beforeEqls = CreateVector(equation.substr(0, eqlsPos));
    //checks to see if there is an operator for the first digit and adds one if there isn't e.g x+3 becomes +x+3
    if (!(beforeEqls[0] == "+" || beforeEqls[0] == "-")) {
        beforeEqls.insert(beforeEqls.begin(), "+");
    }

    afterEqls = CreateVector(equation.substr(eqlsPos + 1, equation.size()));
    //checks to see if there is an operator for the first digit and adds one if there isn't e.g x+3 becomes +x+3
    if (!(afterEqls[0] == "+" || afterEqls[0] == "-")) {
        afterEqls.insert(afterEqls.begin(), "+");
    }

    beforeEqls = LumpStrings(beforeEqls); //Groups all of the strings in the vectors into groups that can be
    afterEqls = LumpStrings(afterEqls);   //moved around by themselves, e.g. +, x, *, 3 could all be dealt with
                                          //together
    for (string s : beforeEqls) {
        cout << s << "," << " ";
    }

    cout << endl;

    for (string s : afterEqls) {
        cout << s << "," << " ";
    }

}

bool isoperator (string s) {
    string ops = "+-*/^";

    for (int i = 0; i < ops.length(); ++i) {
        if (s == to_string(ops[i])) {
            return true;
        }
    }

    return false;
}

vector<string> CreateVector (string s) {
    vector<string> v;

    for (char c : s) {
        v.push_back(&c);
    }

    for (int i = 0; i < v.size(); ++i) {
        v[i] = v[i][0];
    }

    return v;
}

vector<string> LumpStrings (vector<string> v) {
    vector<string> tempStrings;
    tempStrings.push_back(".");

    set<string> opset1 = {"+", "-"}; //set of operators that can be easily dealt with i.e. just sent to the other side
    set<string> opset2 = {"*", "/"}; //set of operators that are slightly more complex

    for (int i = 0; i < v.size(); ++i) {
        bool inOpset1 = opset1.find(v[i]) != opset1.end(); //checks if the current item is in either of the opsets
        bool inOpset2 = opset2.find(v[i]) != opset2.end(); //

        if (inOpset2) {
            if (tempStrings.back().back() != '.') {
                tempStrings.back() += v[i];
            } else {
                tempStrings.push_back(v[i-1] + v[i]);
            }
        }

        if (i > 0 && !isoperator(v[i]) && inOpset2) {
            tempStrings.back() += v[i];
        }

        if (inOpset1) {
            string stringToAdd = v[i];
            int x = i + 1;
            while (x < v.size() &&  opset1.find(v[x]) == opset1.end()) {
                stringToAdd += v[x];
                x ++;
            }

            i = x - i + 1;

            cout << "String to add = " << stringToAdd << endl;

            tempStrings.push_back(stringToAdd + ".");
        }
    }



    return tempStrings;
}

bool is_alnum(string s) {
    for(char c : s) {
        if (!isalnum(c)) {
            return false;
        }
    }

    return true;
}


#endif //GRAPHDRAWINGTESTS_REARRANGEEQ_H
