// Problem#: 1875
// Submission#: 3590237
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int MAXN = 1001;

struct node {
    int v, w;
};

vector<node> tree[MAXN];
double ans;

void dfs(int x, int dep, int sum) {
    if (sum / double(dep) > ans) ans = sum / double(dep);
    for (int i = 0; i < tree[x].size(); i++) {
        int j = tree[x][i].v;
        dfs(j, dep + 1, sum + tree[x][i].w);
    }
}

int main() {
    int i, j, tn, x, y, n;
    node tmp;
    scanf("%d", &tn);
    while (tn--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) tree[i].clear();
        for (i = 0; i < n - 1; i++) {
            scanf("%d%d", &x, &y);
            scanf("%d", &tmp.w);
            tmp.v = y;
            tree[x].push_back(tmp);
        }
        ans = 0;
        int size = tree[0].size();
        for (i = 0; i < size; i++) {
            j = tree[0][i].v;
            dfs(j, 1, tree[0][i].w);
        }
        printf("%.2lf\n", ans + 1e-10);
    }
    return 0;
}                                 