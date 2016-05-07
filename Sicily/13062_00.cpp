// Problem#: 13062
// Submission#: 3412529
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

    long long dp[35];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= 30; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    while (1) {
        int pos;
        cin >> pos;
        if (pos == 0) break;
        cout << dp[pos] << endl;
    }

    return 0;
}                                 