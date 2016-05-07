// Problem#: 1197
// Submission#: 3420067
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

const int MAX_N = 55;

int N;
bool dp[MAX_N][MAX_N];

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {
        string w, s;
        cin >> w;
        if (cin.eof()) break;
        cin >> N;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> s;
            int wl = w.size(), sl = s.size();
            for (int j = 0; j <= wl; j++)
                for (int k = 0; k <= sl; k++) dp[j][k] = false;
            dp[0][0] = true;
            for (int j = 1; j <= wl; j++) {
                for (int k = 0; k <= sl; k++) {
                    if ('a' <= w[j - 1] && w[j - 1] <= 'z' && k) dp[j][k] = dp[j - 1][k - 1] & (w[j - 1] == s[k - 1]);
                    if (w[j - 1] == '*') dp[j][k] = (k ? (dp[j][k - 1] | dp[j - 1][k]) : dp[j - 1][k]);
                    if (w[j - 1] == '?' && k) dp[j][k] = dp[j - 1][k - 1];
                }
            }
            if (dp[wl][sl]) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}                                 