// Problem#: 1820
// Submission#: 3590157
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

struct node {
    int v, c;
};

const int MAXN = 20005;
const int MAXK = 105;

vector<node> tree[MAXN];
int d[MAXN][MAXK];
int eluer[MAXN * 2];
int dep[MAXN * 2];
int first[MAXN];
int dist[MAXN];
int n, tot, m;

void DFS(int x, int f, int depth, int distance) {
    int size = tree[x].size();
    int i, j;
    dist[x] = distance;
    eluer[tot] = x;
    dep[tot] = depth;
    first[x] = tot;
    tot++;
    for (i = 0; i < size; i++) {
        j = tree[x][i].v;
        if (j == f) continue;
        DFS(j, x, depth + 1, distance + tree[x][i].c);
        eluer[tot] = x;
        dep[tot] = depth;
        tot++;
    }
}

void RMQ() {
    int t = tot;
    int k = -1, i, j;
    while (t) {
        t >>= 1;
        k++;
    }
    for (i = 0; i < tot; i++) d[i][0] = i;
    for (j = 1; j <= k; j++) {
        int temp = (1 << j);
        temp = tot - temp;
        int temp2 = (1 << (j - 1));
        for (i = 0; i <= temp; i++) {
            d[i][j] = dep[d[i][j - 1]] < dep[d[i + temp2][j - 1]] ? d[i][j - 1] : d[i + temp2][j - 1];
        }
    }
}

int LCA(int x, int y) {
    int temp, k;
    if (first[x] > first[y]) {
        temp = x;
        x = y;
        y = temp;
    }
    temp = first[y] - first[x] + 1;
    k = -1;
    while (temp) {
        k++;
        temp >>= 1;
    }
    temp = dep[d[first[x]][k]] < dep[d[first[y] - (1 << k) + 1][k]] ? d[first[x]][k] : d[first[y] - (1 << k) + 1][k];
    return eluer[temp];
}

int main() {
    int t, x, y, i, k;
    node tmp;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++) tree[i].clear();
        tot = 0;
        for (i = 0; i < n - 1; i++) {
            scanf("%d%d%d", &x, &y, &k);
            tmp.v = y;
            tmp.c = k;
            tree[x].push_back(tmp);
            tmp.v = x;
            tree[y].push_back(tmp);
        }
        DFS(1, -1, 0, 0);
        RMQ();
        while (m--) {
            scanf("%d%d", &x, &y);
            k = LCA(x, y);
            printf("%d\n", dist[x] + dist[y] - 2 * dist[k]);
        }
        printf("\n");
    }
    return 0;
}                                 