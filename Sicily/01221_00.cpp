// Problem#: 1221
// Submission#: 3294098
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
using namespace std;

struct thing {
    int a, b;
};

thing t[205];
int dp[205][205];

bool cmp(const thing & t1, const thing & t2) {
    return t1.b > t2.b;
}

int main() {

    //std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> t[i].a;
    for (int i = 0; i < n; i++) cin >> t[i].b;
    sort(t, t + n, cmp);

    for (int j = 0; j <= m; j++) dp[0][j] = 0;
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i + 1][j] = max(dp[i][j], dp[i][j - 1] + t[i].a - t[i].b * (j - 1));
        }
    }

    cout << dp[n][m] << endl;

    cin >> n;

    return 0;
}                                 