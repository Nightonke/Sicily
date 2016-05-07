// Problem#: 1960
// Submission#: 3279948
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
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;
    while (caseNum--) {
        int n;
        cin >> n;
        cout << (1 + n) * n / 2 << endl;
    }

    return 0;
}                                 