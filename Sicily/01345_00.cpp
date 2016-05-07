// Problem#: 1345
// Submission#: 2776705
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#define MAX 105

int main() {
    int i, j, k, dp[2 * MAX][2 * MAX], a[2 * MAX], n, max;
    while (~scanf("%d", &n)) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i + n] = a[i];
        }
        
        memset(dp, 0, sizeof(dp));
        
        for (i = 2 * n - 1; i >= 0; i--) {
            for (j = i + 2; j < 2 * n; j++) {
                for (k = i + 1, max = -1; k < j; k++) {
                    if (max < dp[i][k] + dp[k][j] + a[i] * a[k] * a[j])
                        max = dp[i][k] + dp[k][j] + a[i] * a[k] * a[j];
                }
                dp[i][j] = max;
            }
        }
        
        for (i = 0, max = -1; i < n; i++) {
            if (max < dp[i][i + n])
                max = dp[i][i + n];
        }
        
        printf("%d\n", max);
    }
    return 0;
}                                 