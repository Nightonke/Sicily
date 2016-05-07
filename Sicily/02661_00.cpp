// Problem#: 2661
// Submission#: 3593150
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXM = 202;
const int MAXC = 9999;

int dp[MAXM][MAXM];

bool cmp(const int & a, const int & b) {
    return a > b;
}

int main() {
    int xs, xe, m, xn, yn;
    int sx[MAXM], sy[MAXM];
    int mx[MAXC + 1], my[MAXC + 1];
    int i, j, k;
    vector<int> xValue, yValue, streetList[MAXM];

    while (scanf("%d%d%d", &xs, &xe, &m), xs || xe || m) {
        xValue.clear();
        yValue.clear();
        xValue.push_back(xs);
        xValue.push_back(xe);
        yValue.push_back(0);
        yValue.push_back(MAXC);
        for (i = 0; i < m; i++) {
            scanf("%d%d", sx + i, sy + i);
            xValue.push_back(sx[i]);
            xValue.push_back(sx[i] + 1);
            yValue.push_back(sy[i]);
        }
        sort(xValue.begin(), xValue.end());
        xn = unique(xValue.begin(), xValue.end()) - xValue.begin();
        for (i = 0; i < xn; i++) mx[xValue[i]] = i;
        sort(yValue.begin(), yValue.end(), cmp);
        yn = unique(yValue.begin(), yValue.end()) - yValue.begin();
        for (i = 0; i < yn; i++) my[yValue[i]] = i;
        for (i = 0; i < yn; i++) streetList[i].clear();
        for (i = 0; i < m; i++)
            streetList[my[sy[i]]].push_back(sx[i]);
        for (i = 0; i < yn; i++)
            for (j = 0; j < xn; j++) dp[i][j] = MAXC;
        for (i = 0; i < xn; i++) dp[0][i] = abs(xValue[i] - xs);
        for (i = 1; i < yn; i++) {
            for (j = 0; j < xn; j++) {
                for (k = 0; k < xn; k++) {
                    if (dp[i - 1][j] + abs(xValue[j] - xValue[k]) < dp[i][k]) {
                        dp[i][k] = dp[i - 1][j] + abs(xValue[j] - xValue[k]);
                    }
                }
            }
            for (j = 0; j < streetList[i].size(); j++) {
                int t1 = mx[streetList[i][j]], t2 = mx[streetList[i][j] + 1];
                swap(dp[i][t1], dp[i][t2]);
            }
        }
        printf("%d\n", dp[yn - 1][mx[xe]]);
    }
    return 0;
}                                 