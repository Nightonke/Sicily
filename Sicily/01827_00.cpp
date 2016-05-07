// Problem#: 1827
// Submission#: 3589660
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 105;
const int MAXNN = MAXN / 2;

int graph[MAXN][MAXN];
int node[MAXNN];
int n, c[MAXN + 1][MAXN + 1], s, t;
int f[MAXN + 1][MAXN + 1];
int pre[MAXN + 1], tag[MAXN + 1];

int find() {
    int queue[MAXN + 10], head, tail;
    int x, loop;
    for (loop = 0; loop <= n; loop++) tag[loop] = 0;
    queue[0] = s;
    head = 0;
    tail = 1;
    tag[s] = 1;
    while (head != tail) {
        x = queue[head++];
        if (head == MAXN + 10) head = 0;
        for (loop = 0; loop <= n; loop++) if (tag[loop] == 0) {
            if (f[x][loop] < c[x][loop]) {
                pre[loop] = x;
                tag[loop] = 1;
                if (loop == t) return 1;
                queue[tail++] = loop;
                if (tail == MAXN + 10) tail = 0;
            } else if (f[loop][x] > 0) {
                pre[loop] = x;
                tag[loop] = -1;
                if (loop == t) return 1;
                queue[tail++] = loop;
                if (tail == MAXN + 10) tail = 0;
            }
        }
    }
    return 0;
}

void adjust() {
    int min = 2000000000, loop;
    for (loop = t; loop != s; loop = pre[loop]) {
        if (tag[loop] > 0) {
            if (c[pre[loop]][loop] - f[pre[loop]][loop] < min)
                min = c[pre[loop]][loop] - f[pre[loop]][loop];
        } else {
            if (f[loop][pre[loop]] < min)
                min = f[loop][pre[loop]];
        }
    }
    for (loop = t; loop != s; loop = pre[loop]) {
        if (tag[loop] > 0) {
            f[pre[loop]][loop] += min;
        } else {
            if (f[loop][pre[loop]] < min)
                f[loop][pre[loop]] -= min;
        }
    }
}

void solve() {
    int i, j;
    for (i = 0; i <= n; i++) for (j = 0; j <= n; j++) f[i][j] = 0;
    while (find()) adjust();
}

int main() {
    int testcase, nn, mm;
    scanf("%d", &testcase);
    while (testcase--) {
        memset(graph, 0, sizeof(graph));
        memset(node, 0, sizeof(node));
        scanf("%d%d", &nn, &mm);
        for (int i = 1; i <= nn - 1; i++) scanf("%d", node + i);
        for (int i = 0; i < mm; i++) {
            int a1, a2, t;
            scanf("%d%d", &a1, &a2);
            if (a1 > a2) {
                t = a1;
                a1 = a2;
                a2 = t;
            }
            graph[a1][a2] = 1;
            if (a2 != nn && a1 != 0) graph[a2][a1] = 1;
        }
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= nn - 1; i++)
            c[i][i + nn] = node[i];
        for (int i = 0; i <= nn; i++)
            for (int j = 0; j <= nn; j++)
                if (graph[i][j]) {
                    int t1, t2;
                    if (i == 0) {
                        t1 = 0;
                        t2 = j;
                    } else {
                        t1 = i + nn;
                        t2 = j;
                    }
                    c[t1][t2] = 2000000000;
                }
                n = nn * 2 - 1;
                s = 0;
                t = nn;
                solve();
                int maxFlow = 0;
                for (int i = 0; i <= n; i++)  maxFlow += f[i][nn];
                printf("%d\n", maxFlow);
    }
    return 0;
}                                 