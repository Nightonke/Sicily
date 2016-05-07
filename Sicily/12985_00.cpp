// Problem#: 12985
// Submission#: 3410175
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <string.h>
#include <math.h>
#include <list>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b + c) {
            cout << b << " + " << c << " = " << a << endl;
        } else if (b == a + c) {
            cout << a << " + " << c << " = " << b << endl;
        } else if (c == a + b) {
            cout << a << " + " << b << " = " << c << endl;
        } else {
            cout << a << " " << b << " " << c << " NO SUM" << endl;
        }
    }

    return 0;
}                                 