// Problem#: 13861
// Submission#: 3653148
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct cow {
    int x, p;
}c[1005];

int dp[1005][1005], n, ans = 0;

bool cmp(const cow & c1, const cow & c2) {
    return c1.x < c2.x;
}

void DP(bool left2Right) {
    int m;
    memset(dp, sizeof(dp), 0);
    for (int i = 0; i < n; i++) dp[i][i] = c[i].p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            m = 0;
            if (left2Right) {
                for (int k = j; k >= 0; k--) {
                    if (c[j].x - c[k].x <= c[i].x - c[j].x) {
                        if (m < dp[j][k]) {
                            m = dp[j][k];
                        }
                    }
                    else {
                        break;
                    }
                }
                dp[i][j] = m + c[i].p;
            }
            else {
                for (int k = 0; k <= j; k++) {
                    if (c[j].x - c[k].x >= c[i].x - c[j].x) {
                        if (m < dp[j][k]) {
                            m = dp[j][k];
                        }
                    }
                    else {
                        break;
                    }
                }
                if (m < dp[j][j]) m = dp[j][j];
                dp[i][j] = m + c[i].p;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (ans < dp[i][j]) {
                ans = dp[i][j];
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &c[i].x, &c[i].p);
    sort(c, c + n, cmp);
    DP(true);
    DP(false);
    printf("%d\n", ans);
    return 0;
}                                 