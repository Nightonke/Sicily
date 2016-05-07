// Problem#: 1898
// Submission#: 3593210
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 101;

int e[MAXN][MAXN];
int count[MAXN];
int f[MAXN][MAXN];
char color[MAXN];
bool adj[MAXN][MAXN];
bool visited[MAXN];
int n, m;

inline int max(int a, int b) {
    if (a > b) return a;
    return b;
}

void dfs(int u) {
    int i;
    visited[u] = true;
    count[u] = 0;
    for (i = 1; i <= n; i++) {
        if (adj[u][i] && !visited[i]) {
            e[u][count[u]++] = i;
            dfs(i);
        }
    }
}

void dp(int u) {
    int i, j;
    if (color[u] == 'b') f[u][1] = 1;
    else f[u][1] = 0;
    if (count[u] > 0) {
        int v = e[u][--count[u]];
        dp(v);
        dp(u);
        for (i = m; i >= 1; i--) {
            for (j = 1; j < i; j++) {
                f[u][i] = max(f[u][i], f[u][j] + f[v][i - j]);
            }
        }
    }
}

int solve() {
    if (m == 0 || m == n) return 0;
    int res = 0;
    int i;
    memset(visited, 0, sizeof(visited));
    dfs(1);
    memset(f, 0, sizeof(f));
    dp(1);
    for (i = 1; i <= n; i++) res = max(res, f[i][m]);
    return m - res;
}

int main() {
    int tn, i;
    char str[3];
    for (scanf("%d", &tn); tn--; ) {
        scanf("%d", &n);
        m = 0;
        for (i = 1; i <= n; i++) {
            scanf("%s", str);
            color[i] = str[0];
            if (color[i] == 'b') m++;
        }
        memset(adj, false, sizeof(adj));
        for (i = 1; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            adj[x][y] = adj[y][x] = true;
        }
        printf("%d\n", solve());
    }
    return 0;
}                                 