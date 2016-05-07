// Problem#: 1083
// Submission#: 2563548
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
//最小生成树1083. Networking
#include <stdio.h>
#include <string.h>
#define MAXN 101
int fa[MAXN];
int visit[MAXN][MAXN];

int find(int u) {
    if (fa[u] == u)
        return u;
    fa[u] = find(fa[u]);
    return fa[u];
}

void combine(int x, int y) {
    fa[find(x)] = find(y);
}

struct road{
    int x;
    int y;
    int length;
};

void sort(road a[], int n) {
    int i, j;
    road temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j].length > a[j + 1].length) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

int main() {
    int pn, rn, i, temp1, temp2, temp3, sum, j;
    while (scanf("%d", &pn) && pn) {
        scanf("%d", &rn);
        if (rn == 0) {
            printf("0\n");
            continue;
        }
        road a[10010];
        for (i = 1; i <= pn; i++)
            fa[i] = i;
        memset(visit, 0, sizeof(visit));
        j = 0;
        for (i = 0; i < rn; i++) {
            scanf("%d %d %d", &temp1, &temp2, &temp3);
            a[j].x = temp1;
            a[j].y = temp2;
            a[j++].length = temp3;
            a[j].y = temp2;
            a[j].x = temp1;
            a[j++].length = temp3;
        }
        sort(a, j);
        sum = 0;
        for (i = 0; i < j; i++) {
            if (!visit[a[i].x][a[i].y] && !visit[a[i].y][a[i].x]) {
                if (find(fa[a[i].x]) != find(fa[a[i].y])) {
                    sum = sum + a[i].length;
                    combine(a[i].x, a[i].y);
                    visit[a[i].x][a[i].y] = 1;
                    visit[a[i].y][a[i].x] = 1;
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}                                 