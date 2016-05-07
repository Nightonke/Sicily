// Problem#: 1736
// Submission#: 3584390
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int n;
int c[101];
int tag[101];
int father[101];
int g[101][101];
int tree[101][101];
int f0[101], f1[101];

int solve1(int);

int solve0(int x) {
    if (f0[x] >= 0) return f0[x];
    int i, res = 0, temp1, temp2;
    for (i = 1; i <= n; i++)
        if (tree[x][i] == 1) {
            temp1 = solve0(i);
            temp2 = solve1(i);
            if (temp1 > temp2) res += temp1;
            else res += temp2;
        }
    f0[x] = res;
    return f0[x];
}

int solve1(int x) {
    if (f1[x] >= 0) return f1[x];
    int i, j, mark[101], temp1, temp2, res = 0;
    for (i = 0; i <= n; i++) mark[i] = 1;
    for (i = 1; i <= n; i++) {
        if (tree[x][i] == 1) {
            mark[i] = 0;
            for (j = 1; j <= n; j++)
                if (tree[i][j] == 1 && g[x][j] == 1) {
                    mark[j] = 0;
                }
        }
    }
    for (i = 1; i <= n; i++)
        if (mark[i] == 1 && father[i] > 0 && mark[father[i]] == 0) {
            temp1 = solve0(i);
            temp2 = solve1(i);
            if (temp1 > temp2) res += temp1;
            else res += temp2;
        }
    f1[x] = c[x] + res;
    return f1[x];
}

void maketree(int x) {
    tag[x] = 1;
    for (int i = 1; i <= n; i++) 
        if (tag[i] == 0 && g[x][i] == 1) {
            tree[x][i] = 1;
            father[i] = x;
            maketree(i);
        }
}

int main() {
    int i, j, k, m, ans;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        for (i = 1; i <= n; i++) scanf("%d", &c[i]);
        memset(g, 0, sizeof(g));
        memset(tree, 0, sizeof(tree));
        scanf("%d", &m);
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &j, &k);
            g[j][k] = g[k][j] = 1;
        }
        memset(tag, 0, sizeof(tag));
        ans = 0;
        for (i = 1; i <= n; i++) f0[i] = f1[i] =father[i] = -1;
        for (i = 1; i <= n; i++)
            if (tag[i] == 0) {
                maketree(i);
                father[i] = 0;
                j = solve0(i);
                k = solve1(i);
                if (j > k) ans += j;
                else ans += k;
            }
        printf("%d\n", ans);
    }
    return 0;
}                                 