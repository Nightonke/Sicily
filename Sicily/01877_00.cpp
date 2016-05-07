// Problem#: 1877
// Submission#: 3590221
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXM = 3010;
const int MAXN = 5010;
int n, m;

struct node {
    int b, e, t;
};

int arr[MAXN];
node demands[MAXM];
int sum[MAXN];

bool cmp(const node & n1, const node & n2) {
    if (n1.e != n2.e) return n1.e < n2.e;
    return n1.b < n2.b;
}

void solve() {
    int i, j;
    for (i = 0; i <= n; i++) arr[i] = sum[i] = 0;
    int planted = 0, y, tree, add;
    for (i = 0; i < m; i++) {
        y = demands[i].e;
        tree = sum[demands[i].b] - sum[y + 1];
        add = 0;
        while (tree < demands[i].t) {
            while (arr[y]) sum[y--] += add;
            tree++;
            arr[y] = 1;
            planted++;
            add++;
            sum[y--] += add;
        }
        if (add)
            for (j = 1; j <= y; j++) sum[j] += add;
    }
    printf("%d\n", planted);
    for (i = 1; i <= n; i++) if (arr[i] == 1) printf("%d\n", i);
}

void process() {
    int i;
    for (i = 0; i < m; i++) scanf("%d%d%d", &demands[i].b, &demands[i].e, &demands[i].t);
    sort(demands, demands + m, cmp);
    solve();
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) process();
    return 0;
}                                 