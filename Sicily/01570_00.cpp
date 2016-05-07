// Problem#: 1570
// Submission#: 3322380
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
using namespace std;

int main() {

    //std::ios::sync_with_stdio(false);

    while (1) {
        int N, P, W, D, L;
        scanf("%d%d", &N, &P);
        if (N == 0 && P == 0) break;
        scanf("%d%d%d", &W, &D, &L);
        double w = W * 1.0 / (W + D + L), d = D * 1.0 / (W + D + L), l = L * 1.0 / (W + D + L);
        vector<vector<double> > dp;
        dp.resize(N + 5);
        for (int i = 0; i < dp.size(); i++) dp[i].resize(3 * N + 3);
        dp[1][3] = w, dp[1][1] = d, dp[1][0] = l;
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= 3 * i; j++) {
                if (j >= 3) dp[i][j] = dp[i - 1][j - 3] * w + dp[i - 1][j - 1] * d + dp[i - 1][j] * l;
                else if (j > 0) dp[i][j] = dp[i - 1][j - 1] * d + dp[i - 1][j] * l;
                else dp[i][j] = dp[i - 1][j] * l;
            }
        }
        double ans = 0;
        for (int i = P; i <= 3 * N; i++) ans += dp[N][i];
        printf("%.1lf\n", 100 * ans);
    }

    //getchar();
    //getchar();
    
    return 0;
}                                 