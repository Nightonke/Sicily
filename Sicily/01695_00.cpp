// Problem#: 1695
// Submission#: 3421689
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
#include <list>
using namespace std;

const int MAXD = 1005;
const int MAXB = 10005;
const int MAXM = 1005;

int nDay;
int nBook;
int date[MAXB];
int cost[MAXD];
int iBook[MAXD];
int r1;
int a[MAXM], r[MAXM];
int r2;
int b[MAXM], s[MAXM];

int solve() {
    int dp[MAXB];
    int i, j, k, t;
    dp[0] = 0;
    for (k = 1; k <= nBook; k++) {
        dp[k] = dp[k - 1] + cost[date[k]];
        for (i = 0; i < r1; i++) {
            j = k - a[i];
            if (j < 0) j = 0;
            t = dp[j] + r[i];
            if (t < dp[k]) dp[k] = t;
            if (!j) break;
        }
        for (i = 0; i < r2; i++) {
            j = date[k] - b[i] + 1;
            if (j < 1) j = 1;
            t = dp[iBook[j] - 1] + s[i];
            if (t < dp[k]) dp[k] = t;
            if (j == 1) break;
        }
    }
    return dp[nBook];
}

int main() {

    //std::ios::sync_with_stdio(false);

    int n1, n2, n3;
    int p, c, x, y, i, j;

    while (scanf("%d", &nDay) == 1) {
        if (!nDay) break;
        for (nBook = 0, i = 1; i <= nDay; i++) {
            scanf("%d", &x);
            iBook[i] = nBook + 1;
            while (x--) date[++nBook] = i;
        }
        scanf("%d%d%d", &n1, &p, &c);
        for (i = 1; i < n1; i++) {
            scanf("%d%d", &x, &y);
            for (j = p; j < x; j++) cost[j] = c;
            p = x;
            c = y;
        }
        for (j = p; j <= nDay; j++) cost[j] = c;
        scanf("%d", &n2);
        r1 = 0;
        if (n2 > 0) {
            scanf("%d%d", &a[0], &r[0]);
            for (i = 1; i < n2; i++) {
                scanf("%d%d", &x, &y);
                while (r1 >= 0 && y < r[r1]) r1--;
                r1++;
                a[r1] = x;
                r[r1] = y;
            }
            r1++;
        }
        scanf("%d", &n3);
        r2 = 0;
        if (n3 > 0) {
            scanf("%d%d", &b[0], &s[0]);
            for (i = 1; i < n3; i++) {
                scanf("%d%d", &x, &y);
                while (r2 >= 0 && y < s[r2]) r2--;
                r2++;
                b[r2] = x;
                s[r2] = y;
            }
            r2++;
        }
        printf("%d\n", solve());
    }

    return 0;
}                                 