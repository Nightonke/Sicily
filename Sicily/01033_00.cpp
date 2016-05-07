// Problem#: 1033
// Submission#: 3402870
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
using namespace std;

const int MAX = 1000010;

int N, M, B;

bool G[MAX];
long long dp[2][MAX];

int main() {

    //std::ios::sync_with_stdio(false);

    while (1) {

        scanf("%d%d", &M, &N);
        if (!M && !N) break;

        int size = N * M;

        for (int i = 1; i <= size; i++) G[i] = false;

        scanf("%d", &B);
        for (int i = 0; i < B; i++) {
            int x, y, a, b;
            scanf("%d%d%d%d", &x, &y, &a, &b);
            a = x + a - 1;
            b = y + b - 1;
            for (int j = x; j < a; j++) {
                for (int k = y; k < b; k++) {
                    G[(j - 1) * N + k] = true;
                }
            }
        }

        int lastLine = 0, nowLine = 1;

        for (int i = 1; i <= N; i++) {
            dp[0][i] = 1;
            dp[1][i] = 0;
        }

        for (int i = 1; i <= M; i++) {
            dp[nowLine][0] = 1;
            for (int j = 1; j <= N; j++) {
                if (G[(i - 1) * N + j])
                    dp[nowLine][j] = 0;
                else 
                    dp[nowLine][j] = dp[lastLine][j] + dp[nowLine][j - 1];
            }
            nowLine = 1 - nowLine;
            lastLine = 1 - lastLine;
        }

        printf("%lld\n", dp[lastLine][N]);

    }

    return 0;
}                                 