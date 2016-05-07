// Problem#: 1892
// Submission#: 3592099
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int MAXG = 16;
const int INF = 1000000000;

int mov[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int n, m;
char G[MAXN][MAXN + 1];
bool mk[MAXN][MAXN];
map<pair<int, int>, int> Map;
int N;
int g[MAXG + 2][MAXG + 2];
int memo[MAXG + 2][1 << MAXG];

struct Node {
    int r, c, d;
    Node(int r_ = 0, int c_ = 0, int d_ = 0) {
        r = r_;
        c = c_;
        d = d_;
    }
};

Node open[MAXN * MAXN];

bool input() {
    scanf("%d%d", &n, &m);
    if (n == 0) return false;
    for (int i = 0; i < n; i++) scanf("%s", G[i]);
    return true;
}

void bfs(int r, int c) {
    int u = Map[make_pair(r, c)];
    memset(mk, 0, sizeof(mk));
    open[0] = Node(r, c, 0);
    mk[r][c] = true;
    int head = 0, tail = 1;
    while (head < tail) {
        Node cur = open[head++];
        for (int i = 0; i < 4; i++) {
            int rr = cur.r + mov[i][0];
            int cc = cur.c + mov[i][1];
            if (rr >= 0 && rr < n && cc >= 0 && cc < n && !mk[rr][cc]) {
                mk[rr][cc] = true;
                if (G[rr][cc] == 'G' || G[rr][cc] == 'E' || G[rr][cc] == 'X') {
                    int v = Map[make_pair(rr, cc)];
                    g[u][v] = cur.d;
                } else if (G[rr][cc] == '-' && cur.d + 1 <= m) {
                    open[tail++] = Node(rr, cc, cur.d + 1);
                }
            }
        }
    }
}

void construct() {
    Map.clear();
    N = 0;
    int ei, ej;
    int xi, xj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 'G') {
                Map[make_pair(i, j)] = N++;
            } else if (G[i][j] == 'E') {
                ei = i;
                ej = j;
            } else if (G[i][j] == 'X') {
                xi = i;
                xj = j;
            }
        }
    }
    Map[make_pair(ei, ej)] = N++;
    Map[make_pair(xi, xj)] = N++;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 'G' || G[i][j] == 'E' || G[i][j] == 'X') {
                bfs(i ,j);
            }
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int f(int ed, int mask) {
    if (memo[ed][mask] != -1) return memo[ed][mask];
    memo[ed][mask] = INF;
    for (int i = 0; i < N - 2; i++) {
        if ((mask & (1 << i)) > 0 && i != ed) {
            int t = f(i, mask & ~(1 << ed)) + g[i][ed];
            memo[ed][mask] = min(memo[ed][mask], t);
        }
    }
    return memo[ed][mask];
}

void _solve() {
    if (g[N - 2][N - 1] == INF) {
        puts("Impossible");
        return;
    }
    int cnt = 0;
    int mask = 0;
    for (int i = 0; i < N - 2; i++) {
        if (g[N - 2][i] < INF) {
            cnt++;
            mask |= (1 << i);
        }
    }
    if (cnt == 0) {
        printf("0 %d\n", g[N -2 ][N - 1]);
        return;
    }
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < N - 2; i++) {
        memo[i][1 << i] = g[N - 2][i];
        memo[N - 1][1 << i] = g[N - 2][i] + g[i][N - 1];
    }
    int min_cost = f(N - 1, mask);
    printf("%d %d\n", cnt, min_cost);
}

void solve() {
    construct();
    _solve();
}

int main() {
    while (input()) solve();
    return 0;
}                                 