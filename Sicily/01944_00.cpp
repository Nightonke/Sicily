// Problem#: 1944
// Submission#: 3589469
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 1010;
long N, M;
long link[MAXN][MAXN];
long parent[MAXN];
long t[MAXN];
long c[MAXN];
long nChild[MAXN];
long firstLeaf[MAXN];
long ans[MAXN][3];
long cc;

void input() {
    long i, j, x, y, z, temp;
    memset(parent, 0, sizeof(parent));
    memset(t, 0, sizeof(t));
    scanf("%ld", &N);
    for (i = 1; i < N; i++) {
        scanf("%ld", &x);
        scanf("%ld%ld", parent + x, t + x);
    }
    memset(c, 0, sizeof(c));
    memset(link, 0, sizeof(link));
    memset(nChild, 0, sizeof(nChild));
    memset(firstLeaf, 0, sizeof(firstLeaf));
    cc = 0;
    scanf("%ld", &M);
    for (i = 0; i <= M; i++) {
        scanf("%ld%ld%ld", &x, &y, &z);
        if (!i || i == M) cc += z;
        firstLeaf[y] = y;
        c[y] = z;
        if (i < M) {
            temp = y;
            while (parent[temp]) {
                if (!nChild[parent[temp]]) firstLeaf[parent[temp]] = y;
                link[parent[temp]][nChild[parent[temp]]++] = temp;
                if (nChild[parent[temp]] > 1) break;
                temp = parent[temp];
            }
        }
    }
    for (i = 0; i <= N; i++)
        for (j = 0; j < 3; j++)
            ans[i][j] = -1;
}

long findRoot() {
    long i;
    for (i = 1; i <= N; i++) if (!parent[i]) break;
    return i;
}

long Travel(long root, long flag) {
    long i, k, temp;
    if (!nChild[root]) {ans[root][flag] = 0; return 0;}
    if (ans[root][flag] >= 0) return ans[root][flag];
    switch(flag) {
    case 0:
        for (k = 1; k < nChild[root]; k++) {
            temp = t[link[root][k - 1]] + t[link[root][k]];
            for (i = 0; i < k - 1; i++)
                temp += c[firstLeaf[link[root][i + 1]]] + Travel(link[root][i], 0);
            temp += Travel(link[root][k - 1], 2);
            temp += Travel(link[root][k], 1);
            for (i = k + 1; i < nChild[root]; i++)
                temp += c[firstLeaf[link[root][i]]] + Travel(link[root][i], 0);
            if (ans[root][0] < 0) ans[root][0] = temp;
            else if (temp < ans[root][0]) ans[root][0] = temp;
        }
        break;
    case 1:
        ans[root][1] = t[link[root][0]];
        ans[root][1] += Travel(link[root][0], 1);
        for (i = 1; i < nChild[root]; i++)
            ans[root][1] += c[firstLeaf[link[root][i]]] + Travel(link[root][i], 0);
        break;
    case 2:
        ans[root][2] = t[link[root][nChild[root] - 1]];
        for (i = 1; i < nChild[root]; i++)
            ans[root][2] += c[firstLeaf[link[root][i]]] + Travel(link[root][i - 1], 0);
        ans[root][2] += Travel(link[root][nChild[root] - 1], 2);
        break;
    }
    return ans[root][flag];
}

int main() {
    long T, root, answer;
    scanf("%ld", &T);
    while (T--) {
        input();
        root = findRoot();
        answer = cc + Travel(root, 0);
        printf("%ld\n", answer);
    }
    return 0;
}                                 