// Problem#: 1896
// Submission#: 3593203
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 201;
const int BIGNUM = 100000000;

int n, limit[MAXN][MAXN], flow[MAXN][MAXN];

void maxflow() {
    int last[MAXN], check[MAXN];
    int i, j, x, delta;
    while (1) {
        memset(last, 0, sizeof(last));
        memset(check, 0, sizeof(check));
        last[1] = BIGNUM;
        do {
            i = 0;
            do {
                i++;
            } while (i <= n && (!last[i] || check[i]));
            if (i > n) break;
            for (j = 1; j <= n; j++) {
                if (last[j] == 0) {
                    if (flow[i][j] < limit[i][j]) last[j] = i;
                    else if (flow[j][i] > 0) last[j] = -i;
                }
            }
            check[i] = 1;
        } while (!last[n]);
        if (last[n] == 0) break;
        delta = BIGNUM;
        i = n;
        do {
            j = i;
            i = abs(last[j]);
            if (last[j] > 0) x = limit[i][j] - flow[i][j];
            else x = flow[j][i];
            if (x < delta) delta = x;
        } while (i != 1);
        i = n;
        do {
            j = i;
            i = abs(last[j]);
            if (last[j] > 0) flow[i][j] += delta;
            else flow[j][i] -= delta;
        } while (i != 1);
    }
}

int main() {
    int fn, w, s, i, j, a, b, c, d;
    while (scanf("%d", &fn), fn) {
        memset(flow, 0, sizeof(flow));
        memset(limit, 0, sizeof(limit));
        scanf("%d%d", &w, &s);
        for (i = 1; i <= s; i++) limit[1 + fn + i][2 + fn + s] = w;
        for (i = 1; i <= fn; i++) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            limit[1][1 + i] = a;
            for (j = c; j <= d; j++) limit[1 + i][1 + fn + j] = b;
        }
        n = 2 + fn + s;
        maxflow();
        for (i = 1; i <= fn; i++) if (flow[1][1 + i] != limit[1][1 + i]) break;
        printf(i > fn ? "yes\n" : "no\n");
    }
    return 0;
}                                 