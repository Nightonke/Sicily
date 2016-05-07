// Problem#: 1862
// Submission#: 3590189
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 100;
long tot[MAXN][MAXN];
bool isin[MAXN][MAXN];
long L;

int fill(long x, long y) {
    long tx, ty, i, j, k, nNode, flag;
    while (1) {
        if (y > L) x++, y = 1;
        if (x > L) return 1;
        if (!isin[x][y]) break;
        else y++;
    }
    for (k = 1; ; k++) {
        tx = x + k - 1;
        ty = y + k - 1;
        if (tx > L || ty > L) break;
        nNode = tot[tx][ty] - tot[tx][y - 1] - tot[x - 1][ty] + tot[x - 1][y - 1];
        if (nNode > 1) break;
        if (nNode == 1) {
            for (i = x; i < x + k; i++)
                for (j = y; j < y + k; j++) isin[i][j] = 1;
            if (fill(x, y + 1)) return 1;
            for (i = x; i < x + k; i++)
                for (j = y; j < y + k; j++) isin[i][j] = 0;
        }
    }
    return 0;
}

int main() {
    long cases, i, j, N, x, y, a;
    scanf("%ld", &cases);
    while (cases--) {
        scanf("%ld%ld", &L, &N);
        memset(tot, 0, sizeof(tot));
        while (N--) {
            scanf("%ld%ld", &x, &y);
            tot[x][y] = 1;
        }
        for (i = 1; i <= L; i++)
            for (j = 1; j <= L; j++)
                tot[i][j] = tot[i - 1][j] + tot[i][j - 1] - tot[i - 1][j - 1] + tot[i][j];
        memset(isin, 0, sizeof(isin));
        if (fill(1, 1)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}                                 