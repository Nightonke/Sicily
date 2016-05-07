// Problem#: 1504
// Submission#: 3027617
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <math.h>
using namespace std;

#define MAX_N 105
#define INF 2000000000

struct edge{
    int u;
    int v;
    int cost;
};

vector<edge> G;
double x;
int n;
int m;

int par[MAX_N];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int find(int x) {
    if (par[x] == x) return x;
    par[x] = find(par[x]);
    return par[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y) return;

    par[x] = y;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

bool cmp(edge e1, edge e2) {
    return e1.cost < e2.cost;
}

int kruskal(int st) {

    init(n);
    
    edge lastEdge;

    int eNum = 0;

    for (int i = st; i < m; i++) {
        edge e = G[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            eNum++;
            if (eNum == n - 1) {
                return G[i].cost - G[st].cost;
                break;
            }
        }
    }

    return INF;

}

bool judge() {
    init(n);
    for (int i = 0; i < m; i++) {
        unite(G[i].u, G[i].v);
    }

    for (int i = 1; i < n; i++) {

        if (!same(i, i + 1)) return false;

    }

    return true;

}

int main() {

    std::ios::sync_with_stdio(false);

    while (1) {

        cin >> n >> m;

        if (n == 0 && m == 0) break;

        G.clear();
        G.resize(m);

        for (int i = 0; i < m; i++)  cin >> G[i].u >> G[i].v >> G[i].cost;

        if (!judge()) {
            cout << -1 << endl;
            continue;
        }

        int ans = INF;

        sort(G.begin(), G.end(), cmp);

        for (int i = 0; i <= m - (n - 1); i++) {

            int newAns = kruskal(i);

            if (newAns < ans) ans = newAns;

        }

        cout << ans << endl;

    }

    //getchar();
    //getchar();
    
    return 0;
}                                 