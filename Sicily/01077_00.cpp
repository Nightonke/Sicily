// Problem#: 1077
// Submission#: 2695062
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}
int dp[11][100001];
int main() {
    int sum, i, n, j, num[11], w[11], k;
    while (scanf("%d", &sum) == 1) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d%d", &num[i], &w[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (i = 0; i < n; i++) {
            for (j = 0; j <= sum; j++) {
                for (k = 0; k * w[i] <= j && k <= num[i]; k++) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * w[i]] + k * w[i]);
                }
            }
        }
        printf("%d\n", dp[n][sum]);
    }
    return 0;
}                                 