// Problem#: 1953
// Submission#: 3592158
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 101;

char g[MAXN][MAXN], mark[MAXN], used[MAXN];
int n;

void dfs() {
    int i, j;
    for (i = 1; i <= n; i++) if (!mark[i]) break;
    if (i > n) return;
    mark[i] = 1;
    for (j = 1; j <= n; j++) if (g[i][j]) mark[j] = 1;
    dfs();
    for (j = 1; j <= n; j++) if (used[j] && g[j][i]) break;
    if (j > n) used[i] = 1;
}

int main() {
    int m, a, b, i;
    while (scanf("%d%d", &n, &m), n) {
        memset(g, 0, sizeof(g));
        while (m--) {
            scanf("%d%d", &a, &b);
            g[a][b] = 1;
        }
        scanf("%*d");
        memset(mark, 0, sizeof(mark));
        memset(used, 0, sizeof(used));
        dfs();
        for (i = 1, a = 0; i <= n; i++) if (used[i]) a++;
        printf("0\n");
        printf("%d\n", a);
        bool prn = false;
        for (i = 1; i <= n; i++) {
            if (used[i]) {
                if (prn) printf(" ");
                else prn = true;
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}                                 