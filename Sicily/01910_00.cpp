// Problem#: 1910
// Submission#: 3591062
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 50001;

struct Node {
    int child[2];
    int parent;
};

int n;
Node node[MAXN];

void rotate(int x) {
    int y = node[x].parent;
    int d = x == node[y].child[0] ? 0 : 1;
    int t = node[x].child[1 - d];
    if (t > 0) node[t].parent = y;
    node[y].child[d] = t;
    int z = node[y].parent;
    node[x].child[1 - d] = y;
    node[y].parent = x;
    node[x].parent = z;
    if (z > 0) {
        node[z].child[y == node[z].child[0] ? 0 : 1] = x;
    }
}

void splay(int x) {
    while (1) {
        int y = node[x].parent;
        if (y <= 0) break;
        int d = x == node[y].child[0] ? 0 : 1;
        int z = node[y].parent;
        if (z <= 0 || node[z].child[d] != y) rotate(x);
        else {
            rotate(y);
            rotate(x);
        }
    }
}

void expose(int v) {
    splay(v);
    int x = v;
    while (1) {
        int px = -node[x].parent;
        if (px == 0) break;
        splay(px);
        int lpx = node[px].child[0];
        if (lpx > 0) node[lpx].parent = -px;
        node[px].child[0] = x;
        node[x].parent = px;
        x = px;
    }
    splay(v);
}

void link(int v, int w) {
    expose(v);
    expose(w);
    node[v].parent = -w;
}

int root(int v) {
    expose(v);
    int w = v;
    while (node[w].child[1] > 0) w = node[w].child[1];
    splay(w);
    return w;
}

void cut(int v) {
    expose(v);
    int rv = node[v].child[1];
    if (rv > 0) {
        node[v].child[1] = 0;
        node[rv].parent = 0;;
    }
}

int parent(int v) {
    expose(v);
    int p = node[v].child[1];
    if (p == 0) return 0;
    while (node[p].child[0] > 0) p = node[p].child[0];
    splay(p);
    return p;
}

void readTrees() {
    for (int i = 1; i <= n; i++) {
        node[i].child[0] = node[i].child[1] = node[i].parent = 0;
    }
    for (int i = 1; i <= n; i++) {
        int p;
        scanf("%d", &p);
        if (p > 0) link(i, p);
    }
}

void solve() {
    int m;
    scanf("%d", &m);
    while (m--) {
        char cmd[10];
        int x, y;
        scanf("%s", cmd);
        if (cmd[0] == 'Q') {
            scanf("%d", &x);
            printf("%d\n", root(x));
        } else if (cmd[0] == 'M') {
            scanf("%d%d", &x, &y);
            int px = parent(x);
            if (px > 0) cut(x);
            if (y > 0) {
                if (root(y) != x) {
                    link(x, y);
                } else {
                    if (px > 0) link(x, px);
                }
            }
        }
    }
}

int main() {
    bool firstCase = 1;
    while (scanf("%d", &n) == 1) {
        if (firstCase) firstCase = 0;
        else printf("\n");
        readTrees();
        solve();
    }
    return 0;
}                                 