// Problem#: 1906
// Submission#: 3590782
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXV = 101;
const int MAXE = MAXV * MAXV / 2;
const int INF = 0x7fffffff;

int head[MAXV];
int Next[MAXE * 2];
int to[MAXE * 2];
int weight[MAXE];
int flow[MAXE];
int temp[MAXE];
int cur[MAXV];
int distant[MAXV];
int counter[MAXV + 1];
int Prev[MAXV];
int delta[MAXV];
int n, m;

void init(int _n) {
    n = _n;
    m = 0;
    memset(head, -1, sizeof(int) * n);
}

void add_edge(int u, int v, int x) {
    to[m * 2 + 0] = v;
    Next[m * 2 + 0] = head[u];
    head[u] = m * 2 + 0;
    to[m * 2 + 1] = u;
    Next[m * 2 + 1] = head[v];
    head[v] = m * 2 + 1;
    weight[m] = x;
    m++;
}

int augmentable(int k) {
    if (k % 2 == 0) return weight[k / 2] - flow[k / 2];
    return flow[k / 2];
}

int maxflow(int source, int target) {
    memset(counter, 0, sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++) {
        distant[i] = 1;
        cur[i] = head[i];
    }
    distant[target] = 0;
    counter[0] = 1;
    counter[1] = n - 1;
    delta[source] = INF;
    int last = source;
    int ret = 0;
    while (1) {
        int & u = cur[last];
        for (; u >= 0; u = Next[u]) 
            if (distant[to[u]] + 1 == distant[last] && augmentable(u)) break;
        if (u < 0) {
            int & c = (--counter[distant[last]]);
            distant[last] = n;
            for (int j = head[last]; j >= 0; j = Next[j]) {
                if (distant[to[j]] + 1 < distant[last] && augmentable(j)) {
                    distant[last] = distant[to[j]] + 1;
                    cur[last] = j;
                }
            }
            counter[distant[last]]++;
            if (c == 0 || distant[source] == n) return ret;
            if (last != source)  last = to[Prev[last] ^ 1];
        } else {
            Prev[to[u]] = u;
            delta[to[u]] = min(delta[last], augmentable(u));
            last = to[u];
            if (last != target) continue;
            ret += delta[target];
            for (; last != source; last = to[Prev[last] ^ 1]) {
                if (Prev[last] % 2 == 0) {
                    flow[Prev[last] / 2] += delta[target];
                } else {
                    flow[Prev[last] / 2] -= delta[target];
                }
            }
        }
    }
}

int main() {
    int cs;
    scanf("%d", &cs);
    while (cs--) {
        int n, m;
        scanf("%d%d", &n, &m);
        init(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a, b, c);
        }
        memset(flow, 0, sizeof(int) * m);
        int orig = maxflow(1, n);
        memcpy(temp, flow, sizeof(int) * m);
        int max1 = 0;
        int max2 = 0;
        for (int i = 2; i < n; i++) {
            memcpy(flow, temp, sizeof(int) * m);
            max1 = max(max1, maxflow(1, i));
            memcpy(flow, temp, sizeof(int) * m);
            max2 = max(max2, maxflow(i, n));
        }
        printf("%d\n", orig + min(max1, max2));
    }
    return 0;
}                                 