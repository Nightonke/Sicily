// Problem#: 11600
// Submission#: 3550130
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

unsigned short dp[200][200], w[200], N;

inline int max(int a, int b) {if (a > b) return a; return b;}

int main() {

    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++) scanf("%d", w + i);
        N--;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < N; i++) 
            for (int j = 1; j + i <= N; j++) 
                for (int k = j; k < j + i; k++) 
                    dp[j][j + i] = max(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + w[j - 1] + w[k] + w[j + i]);
        printf("%d\n", dp[1][N]);

    }

    return 0;
}                                 