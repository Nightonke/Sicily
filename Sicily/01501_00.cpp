// Problem#: 1501
// Submission#: 3022913
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
using namespace std;

#define MAX_TURN 105
#define MAX_N 105

double dp[MAX_TURN][MAX_N];
int board[MAX_N];

int main() {

    //std::ios::sync_with_stdio(false);

    while (1) {

        int n, t, l, b;

        memset(board, 0, sizeof(board));

        cin >> n >> t >> l >> b;

        for (int i = 0; i < l; i++) {

            int p;

            cin >> p;

            board[p] = 1;

        }

        for (int i = 0; i < b; i++) {

            int p;

            cin >> p;

            board[p] = 2;

        }

        if (n + t + l + b == 0) break;

        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;

        for (int i = 0; i < t; i++) {

            for (int j = 0; j < n; j++) {

                for (int k = 1; k <= 6; k++) {

                    int nextPos = j + k;

                    if (nextPos > n) nextPos = n - (nextPos - n);

                    if (board[nextPos] == 0) {

                        dp[i + 1][nextPos] += dp[i][j] / 6;

                    } else if (board[nextPos] == 1) {

                        if (i + 2 <= t) dp[i + 2][nextPos] += dp[i][j] / 6;

                    } else {

                        dp[i + 1][0] += dp[i][j] / 6;

                    }

                }

            }

        }

        double ans = 0;

        for (int i = 0; i <= t; i++) ans += dp[i][n];

        printf("%.6lf\n", ans);

    }
 
    //getchar();
    //getchar();
    return 0;
}                                 