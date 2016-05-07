// Problem#: 1946
// Submission#: 3589529
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 6;
const int MAXP = MAXN * MAXN * 2 + 2;
const int mSide[] = {0, 9, 6, 3, 10, 12, 5, 11, 14, 13, 7, 15};
const char cDir[] = "ULRD";
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int m;
int n;
int S, T;
int a[MAXN][MAXN];
int nNode;
int pNode[MAXN][MAXN][4];
int g[MAXP][MAXP];
int deg[MAXP];

int ans;
bool flag[MAXP];
int nAdj[MAXP];
int adj[MAXP][MAXP];

void buildNode() {
    nNode = 2;
    memset(pNode, -1, sizeof(pNode));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            int v = a[i][j];
            int * p = pNode[i][j];
            switch(v) {
            case 12:
                p[0] = p[3] = nNode++;
                p[1] = p[2] = nNode++;
                break;
            case 13:
                p[0] = p[1] = nNode++;
                p[2] = p[3] = nNode++;
                break;
            case 14:
                p[0] = p[2] = nNode++;
                p[1] = p[3] = nNode++;
                break;
            default:
                for (int k = 0; k < 4; k++) if ((mSide[v] >> k) & 1) p[k] = nNode;
                nNode++;
            }
        }
}

void buildEdge() {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++) {
                int u = pNode[i][j][k];
                if (u < 0) continue;
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int v = pNode[x][y][3 - k];
                    if (v >= 0) g[u][v] = g[v][u] = 1;
                }
            }
}

int getP() {
    int x, y;
    char d[2];
    scanf("%d%d%s", &x, &y, d);
    x--;
    y--;
    for (int i = 0; i < 4; i++) if (d[0] == cDir[i]) return pNode[x][y][i];
    return -1;
}

void simplify() {
    for (int i = 0; i < nNode; i++) {
        deg[i] = 0;
        for (int j = 0; j < nNode; j++) deg[i] += (g[i][j] > 0);
    }
    bool done;
    do {
        done = 1;
        for (int i = 0; i < nNode; i++) if (deg[i] == 2) {
            int u = -1, v = -1;
            for (int j = 0; j < nNode; j++) if (g[i][j] > 0) {
                if (u < 0) u = j;
                else {v = j; break;}
            }
            if (g[u][v] > 0) deg[u]--, deg[v]--;
            g[v][u] = g[u][v] = g[i][u] * g[i][v] + g[u][v];
            deg[i] = -1;
            g[i][u] = g[u][i] = 0;
            g[i][v] = g[v][i] = 0;
            done = 0;
        }
    } while (!done);
}

void go(int u, int cur) {
    if (u == T) {
        ans += cur;
        return;
    }
    flag[u] = 1;
    for (int i = 0; i < nAdj[u]; i++) {
        int v = adj[u][i];
        if (flag[v] || g[u][v] == 0) continue;
        go(v, cur * g[u][v]);
    }
    flag[u] = 0;
}

int solve() {
    buildNode();
    S = getP();
    T = getP();
    if (S < 0 || T < 0) return 0;
    memset(g, 0, sizeof(g));
    g[0][S] = g[S][0] = 1;
    g[1][T] = g[T][1] = 1;
    buildEdge();
    simplify();
    if (g[0][1] > 0) return g[0][1];
    for (int i = 2; i < nNode; i++) if (deg[i] >= 0) {
        if (g[0][i] > 0) S = i;
        if (g[1][i] > 0) T = i;
    }
    int c = g[0][S] * g[1][T];
    g[S][0] = g[T][1] = 0;
    memset(nAdj, 0 ,sizeof(nAdj));
    for (int i = 2; i < nNode; i++) if (deg[i] >= 0) {
        for (int j = 2; j < nNode; j++) if (deg[j] >= 0 && g[i][j] > 0) adj[i][nAdj[i]++] = j;
    }
    memset(flag, 0, sizeof(flag));
    ans = 0;
    go(S, 1);
    return ans * c;
}

int main() {
    while (scanf("%d%d", &m, &n) == 2) printf("%d\n", solve());
    return 0;
}                                 