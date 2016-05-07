// Problem#: 1767
// Submission#: 2699972
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#define INF -9999999

int max(int a, int b) {
    return a > b ? a : b;
}

int max_in_four(int a, int b, int c, int d) {
    return max(max(max(a, b), c), d);
}

int dp[51][51][51][51];

int main() {
    int m, n, i, j, k, u, a[55][55], temp;
    while (scanf("%d%d", &m, &n) == 2) {
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                dp[i][j][i][j] = INF;
            }
        }
        dp[1][1][1][1] = 0;
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                for (k = 1; k <= m; k++) {
                    for (u = 1; u <= n; u++) {
                        temp = a[i][j] + a[k][u];
                        if (!(i == k && j == u))
                            dp[i][j][k][u] = max_in_four(dp[i - 1][j][k - 1][u] + temp, dp[i - 1][j][k][u - 1] + temp, dp[i][j - 1][k - 1][u] + temp, dp[i][j - 1][k][u - 1] + temp);
                    }
                }
            }
        }
        dp[m][n][m][n] = max_in_four(dp[m - 1][n][m - 1][n], dp[m - 1][n][m][n - 1], dp[m][n - 1][m - 1][n], dp[m][n - 1][m][n - 1]);
        printf("%d\n", dp[m][n][m][n]);
    }
    return 0;
}                                 