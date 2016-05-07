// Problem#: 1722
// Submission#: 3585370
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

bool vis[105][105][4];
int G[105][105];
int h, w;
int si, sj, ei, ej;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct step {
    int i, j, s;
    step(int ii = 0, int jj = 0, int ss = 0) {
        i = ii;
        j = jj;
        s = ss;
    }
};

inline bool isValid(int i, int j, int dir) {
    if (!(1 <= i && i <= h && 1 <= j && j <= w)) return false;
    if (G[i][j] == 0 && vis[i][j][0]) return false;
    if (G[i][j] && vis[i][j][dir]) return false;
    return true;
}

void BFS() {
    queue<step> q;
    memset(vis, false, sizeof(vis));
    vis[si][sj][0] = true;
    q.push(step(si, sj, 0));
    int ans = 88888888;
    while (!q.empty()) {
        step t = q.front();
        //printf("---%d %d---\n", t.i, t.j);
        q.pop();
        if (t.i == ei && t.j == ej) {
            if (ans > t.s) ans = t.s;
        }
        for (int i = 0; i < 4; i++) {
            int ni = t.i + dir[i][0];
            int nj = t.j + dir[i][1];
            if (isValid(ni, nj, i)) {
                if (G[ni][nj] == 0) {
                    q.push(step(ni, nj, t.s + 1));
                    vis[ni][nj][0] = true;
                } else {
                    while (G[ni][nj] && !vis[ni][nj][i]) {
                        vis[ni][nj][i] = true;
                        if (i == 0) {
                            nj += G[ni][nj];
                            if (nj >= w) nj = w;
                        } else if (i == 1) {
                            ni += G[ni][nj];
                            if (ni >= h) ni = h;
                        } else if (i == 2) {
                            nj -= G[ni][nj];
                            if (nj <= 1) nj = 1;
                        } else {
                            ni -= G[ni][nj];
                            if (ni <= 1) ni = 1;
                        }
                    }
                    q.push(step(ni, nj, t.s + 1));
                    vis[ni][nj][0] = true;
                }
            }
        }
    }
    if (ans == 88888888) printf("Impossible\n");
    else printf("%d\n", ans);
}


int main() {
    while (scanf("%d%d", &h, &w) != EOF) {
        memset(G, 0, sizeof(G));
        int k;
        scanf("%d", &k);
        while (k--) {
            int i, j;
            scanf("%d%d", &i, &j);
            scanf("%d", &G[i][j]);
        }
        scanf("%d%d%d%d", &si, &sj, &ei, &ej);
        BFS();
    }
    return 0;
}                                 