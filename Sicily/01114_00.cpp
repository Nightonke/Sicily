// Problem#: 1114
// Submission#: 2583257
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int a[101][101][101], maxx, maxy, maxz;
int move[][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}};

int max(int a, int b) {
    return a > b ? a : b;
}

void dfs(int i, int j, int k) {
    int u, goi, goj, gok;
    a[i][j][k] = 1;
    for (u = 0; u < 6; u++) {
        goi = i + move[u][0];
        goj = j + move[u][1];
        gok = k + move[u][2];
        if (goi <= maxx && goj <= maxy && gok <= maxz && goi >= 0 && goj >= 0 && gok >= 0 && a[goi][goj][gok] == 0)
            dfs(goi, goj, gok);
    }
    return;
}

int main() {
    int t, n, t1, t2, t3, counter, i, j, k;
    scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        maxx = maxy = maxz = 0;
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &t1, &t2, &t3);
            maxx = max(maxx, t1);
            maxy = max(maxy, t2);
            maxz = max(maxz, t3);
            a[t1][t2][t3] = 1;
        }
        maxx += 2;
        maxy += 2;
        maxz += 2;
        counter = -1;
        for (i = 1; i < maxx; i++) {
            for (j = 1; j < maxy; j++) {
                for (k = 1; k < maxz; k++) { 
                    if (a[i][j][k] == 0) {
                        dfs(i, j, k);
                        counter++;
                    }
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 