// Problem#: 1078
// Submission#: 3403425
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
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {

        int n;
        cin >> n;
        if (n < 3) {
            cout << 0 << endl;
            continue;
        }
        cout << (n % 2 ? (n * (n - 3) / 2) : (n * (n - 4) / 2 + 1)) << endl;

    }

    return 0;
}                                 