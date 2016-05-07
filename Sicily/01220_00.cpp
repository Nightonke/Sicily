// Problem#: 1220
// Submission#: 3560426
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX_V = 505;
const int INF = 88888888;

struct edge {
    int to, cap, rev;
    edge(int t = 0, int c = 0, int r = 0) {
        to = t;
        cap = c;
        rev = r;
    }
};

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size() - 1));
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        edge & e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (1) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

vector<int> _onePos, onePos;

int main() {

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int v, m, t;
        scanf("%d%d", &v, &m);
        if (v == 1) onePos.push_back(i);
        if (v == -1) _onePos.push_back(i);
        while (m--) {
            scanf("%d", &t);
            add_edge(i, t, INF);
        }
    }
    for (int i = 0; i < _onePos.size(); i++) add_edge(_onePos[i], N + 1, 1);
    for (int i = 0; i < onePos.size(); i++) add_edge(0, onePos[i], 1);
    printf("%d\n", onePos.size() - max_flow(0, N + 1));

    return 0;
}                                 