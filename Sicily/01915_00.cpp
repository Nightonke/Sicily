// Problem#: 1915
// Submission#: 3591451
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
const int MAXM = MAXN * (MAXN - 1) / 2;

int x[MAXM], y[MAXM], d[MAXM], w[MAXM];
int order[MAXM];
int father[MAXN];
int r[MAXN];
int slot[MAXN];
int n, m;

bool pr(int i, int j) {return w[i] > w[j];}

int find(int p) {
    if (father[p] == 0) return p;
    return father[p] = find(father[p]);
}

void merge(int x, int y) {
    if (r[x] < r[y]) return merge(y, x);
    father[y] = x;
    slot[x] += slot[y];
    if (r[x] == r[y]) r[x]++;
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d%d", x + i, y + i, d + i, w + i);
            order[i] = i;
        }
        sort(order, order + m, pr);
        for (int i = 1; i <= n; i++) {
            father[i] = r[i] = 0;
            slot[i] = 1;
        }
        int ret = 0;
        for (int i = 0; i < m; i++) {
            int cur = order[i];
            if (d[cur] == 0) {
                int fx = find(x[cur]);
                int fy = find(y[cur]);
                if (slot[fx] + slot[fy] > 0) {
                    ret += w[cur];
                    slot[fx]--;
                    if (fx != fy) merge(fx, fy);
                }
            } else {
                int fx = find(x[cur]);
                if (slot[fx] > 0) {
                    ret += w[cur];
                    slot[fx]--;
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}                                 