// Problem#: 1763
// Submission#: 2763079
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int dp[35][35];

int dpp(int mans, int times) {
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    for (int i = 1; i <= times; i++) {
        for (int j = 1; j <= mans; j++) {
            if (j == 1) {
                dp[i][j] = dp[i - 1][mans] + dp[i - 1][2];
            } else if (j == mans) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][1];
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
        }
    }
    return dp[times][1];
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m))
        printf("%d\n", dpp(n, m));
    return 0;
}                                 