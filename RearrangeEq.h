//
// Created by Josh aka Bae on 10/05/2016.
//

#ifndef GRAPHDRAWINGTESTS_REARRANGEEQ_H
#define GRAPHDRAWINGTESTS_REARRANGEEQ_H

#include <iostream>
#include <c++/bits/algorithmfwd.h>
#include <c++/vector>
#include <c++/set>
#include <c++/bits/stl_map.h>

using namespace std;

bool isoperator (char c);
bool is_alnum(string s);
bool ContainsTarget(string s, string target);
vector<string> CreateVector(string s);
vector<string> LumpStrings(vector<string> v);
string FlipOp (string op);
vector<string> RearrangeSides (vector<string> v1, vector<string> v2, string target);

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

    beforeEqls, afterEqls = RearrangeSides(beforeEqls, afterEqls, target);

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

    set<string> opset1 = {"+", "-"}; //set of operators that can be easily dealt with i.e. just sent to the other side
    set<string> opset2 = {"*", "/"}; //set of operators that are slightly more complex

    for (int i = 0; i < v.size(); ++i) {
        if (opset1.find(v[i]) != opset1.end()) {
            tempStrings.push_back(v[i]);
        } else if (is_alnum(v[i]) or opset2.find(v[i]) != opset2.end()) {
            tempStrings.back().append(v[i]);
        }
    }

    return tempStrings;
}

vector<string> RearrangeSides (vector<string> v1, vector<string> v2, string target) {
    //rearranges the vectors so that only the expressions holding the target are on the left (v1)

    for (int i = 0; i < v1.size(); ++i) {
        if (!ContainsTarget(v1[i], target)) {
            v2.push_back(FlipOp(to_string(v1[i][0])) + v1[i].substr(1));
            v1[i] = "";
        }
    }

    return v1, v2;
}

bool is_alnum(string s) {
    for(char c : s) {
        if (!isalnum(c)) {
            return false;
        }
    }

    return true;
}

bool ContainsTarget (string s, string target) {
    for (char c : s) {
        if (to_string(c) == target) {
            return true;
        }
    }

    return false;
}

string FlipOp (string op) {
    map<string, string> Operators;

    Operators.insert(make_pair("*", "/"));
    Operators.insert(make_pair("/", "*"));
    Operators.insert(make_pair("-", "+"));
    Operators.insert(make_pair("+", "-"));


    return Operators.at(op);
}

#endif //GRAPHDRAWINGTESTS_REARRANGEEQ_H
