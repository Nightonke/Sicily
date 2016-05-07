// Problem#: 1684
// Submission#: 3589186
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 1001;

int N;
int disp[MAXN][MAXN];
int heightm[MAXN], heightw[MAXN];
int agem[MAXN], agew[MAXN];
int nx, ny, g[MAXN][MAXN], sy[MAXN], cx[MAXN], cy[MAXN];

int path(int u) {
    for (int v = 1; v <= ny; v++)
        if (g[u][v] && !sy[v]) {
            sy[v] = 1;
            if (!cy[v] || path(cy[v])) {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    return 0;
}

int maxmatch() {
    int i, ret = 0;
    memset(cx, 0, sizeof(cx));
    memset(cy, 0, sizeof(cy));
    for (i = 1; i <= nx; i++)
        if (!cx[i]) {
            memset(sy, 0, sizeof(sy));
            ret += path(i);
        }
    return ret;
}

void buildgraph(int x) {
    int i, j;
    nx = ny = N;
    memset(g, 0, sizeof(g));
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            if (disp[i][j] <= x) g[i][j] = 1;
            else g[i][j] = 0;
}

int main() {
    int i, j, p, q, ans, left, right;
    while (scanf("%d", &N) == 1) {
        if (N == 0) break;
        for (i = 1; i <= N; i++) scanf("%d%d", heightm + i, agem + i);
        for (i = 1; i <= N; i++) scanf("%d%d", heightw + i, agew + i);
        left = 1000000000;
        right = 0;
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                p = heightm[i] - heightw[j];
                q = agem[i] - agew[j];
                disp[i][j] = p * p + q * q;
                if (disp[i][j] < left) left = disp[i][j];
                if (disp[i][j] > right) right = disp[i][j];
            }
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            buildgraph(mid);
            int ret = maxmatch();
            if (ret == N) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}                                 