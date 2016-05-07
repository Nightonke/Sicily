// Problem#: 1047
// Submission#: 3277800
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
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int a, b, minn, maxx, sum1, i;
        cin >> a >> b >> minn >> maxx;
        if (a > b) swap(a, b);
        int temp = (minn + maxx) * (maxx - minn + 1) / 2 + a - b;
        if (temp < 0 || temp % 2) {
            cout << "not possible" << endl;
            continue;
        }
        sum1 = temp / 2;
        for (i = 0; i <= maxx - minn + 1; i++) {
            int l = 0, r = 0;
            for (int j = 0; j < i; j++) {
                l += minn + j;
                r += maxx - j;
            }
            if (l <= sum1 && sum1 <= r) break;
        }
        if (i > maxx - minn + 1) cout << "not possible" << endl;
        else cout << "possible" << endl;
    }

    return 0;
}                                 