// Problem#: 1945
// Submission#: 3589482
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXC = 100;
const int MAXN = 1000000 + 1;
const int INF = 0x7fffffff;

int cs, N, C, K, t;
int banana[MAXN];
int monkey[MAXN];

struct A {
    int x, y, t, s;
    bool operator < (const A o) const {return s < o.s;}
}a[MAXC], b;

void heap_down(int j) {
    int i;
    for (b = a[j], i = j;;)
        if (i * 2 + 2 < C && a[i * 2 + 2] < b && a[i * 2 + 2] < a[i * 2 + 1])
            a[i] = a[i * 2 + 2], i = i * 2 + 2;
        else if (i * 2 + 1 < C && a[i * 2 + 1] < b)
            a[i] = a[i * 2 + 1], i = i * 2 + 1;
        else break;
    a[i] = b;
}

void heap_up(int j) {
    int i;
    for (b = a[j], i = j;;)
        if ((i - 1) / 2 >= 0 && b < a[(i - 1) / 2]) a[i] = a[(i - 1) / 2], i = (i - 1) / 2;
        else break;
    a[i] = b;
}

int main() {
    int i;
    scanf("%d", &cs);
    while (cs--) {
        scanf("%d%d", &N, &C);
        t = 0;
        banana[0] = monkey[0] = 0;
        for (i = 0; i < C; i++) {
            scanf("%d%d", &a[i].x, &a[i].y);
            a[i].t = 0;
            a[i].s = a[i].y;
        }
        sort(a, a + C);
        scanf("%d", &K);
        while (a[0].s != INF && t < K) {
            if (a[0].s != banana[t]) {
                t++;
                banana[t] = a[0].s;
                monkey[t] = monkey[a[0].t] + 1;
                for (i = 1; i < C; i++)
                    if (a[i].s == INF && banana[t] % (a[i].x - 1) == 0 && monkey[t] < N) {
                        a[i].s = banana[a[i].t = t] / (a[i].x - 1) * a[i].x + a[i].y;
                        heap_up(i);
                    }
            } else if (monkey[a[0].t] + 1 < monkey[t]) monkey[t] = monkey[a[0].t] + 1;
            a[0].s = INF;
            do {
                a[0].t++;
                if (banana[a[0].t] % (a[0].x - 1) == 0 && monkey[a[0].t] < N) {
                    a[0].s = banana[a[0].t] / (a[0].x - 1) * a[0].x + a[0].y;
                    break;
                }
            } while (a[0].t < t);
            heap_down(0);
        }
        if (t == K) printf("%d\n", banana[t]);
        else printf("-1\n");
    }
    return 0;
}                                 