// Problem#: 11599
// Submission#: 3525803
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

double dp[10][101];
double ans[10][101];
    
int main() {
    
    double sum = 0;
    
    for (int i = 0; i <= 9; i++) {
        
        for (int k = 0; k <= i; k++) dp[k][1] = ans[k][1] = 1;
        for (int j = 2; j <= 100; j++) {
            dp[0][j] = dp[0][j - 1] + (i > 0 ? dp[1][j - 1] : 0);
            for (int k = 1; k < i; k++) 
                dp[k][j] = dp[k - 1][j - 1] + dp[k][j - 1] + dp[k + 1][j - 1];  // recursion formula
            dp[i][j] = (i > 0 ? dp[i - 1][j - 1] : 0) + dp[i][j - 1];
            for (int k = 0; k <= i; k++) sum += dp[k][j];
            ans[i][j] = sum / pow(1.0 * i + 1, j);
            sum = 0;
            if (ans[i][j] < 0.0000001) break;  // ans[i][j] will decrease when j increase. If the ans[i][j] is small enough to ignore, it's unnecessary to calculate anymore
        }
    }

    int k, n;
    while (scanf("%d%d", &k, &n) != EOF) printf("%.5f\n", ans[k][n] * 100);

    return 0;
}                                 