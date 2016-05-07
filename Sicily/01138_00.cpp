// Problem#: 1138
// Submission#: 3586746
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

int map[110][110], fa[110], degree[110], max[110][2][110], num[110];
int n, m;

void init() {
    int i, x, y;
    memset(map, 0, sizeof(map));
    scanf("%d%d", &n, &m);
    if (m > n) m = n;
    for (i = 1; i <= n; i++) scanf("%d", num + i);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        map[x][y] = 1;
        map[y][x] = 1;
    }
}

void creat_tree() {
    int mark[110], stack[110];
    int i, j, total;
    memset(mark, 0, sizeof(mark));
    memset(degree, 0, sizeof(degree));
    stack[1] = 1;
    mark[1] = 1;
    fa[1] = 0;
    i = total = 1;
    while (i <= total) {
        for (j = 1; j <= n; j++)
            if (!mark[j] && map[stack[i]][j]) {
                fa[j] = stack[i];
                degree[stack[i]]++;
                mark[j] = 1;
                stack[++total] = j;
            }
        i++;
    }
}

void work() {
    int i, j, k;
    creat_tree();
    memset(max, 0xff, sizeof(max));
    for (i = 1; i <= n; i++) {
        max[i][0][0] = 0;
        max[i][1][1] = num[i];
    }
    while (1) {
        for (i = 1; i <= n; i++) if (degree[i] == 0) break;
        if (i > n) break;
        for (j = 0; j <= 1; j++)
            for (k = 1; k <= m; k++)
                if (max[i][j][k] > max[fa[i]][0][k])
                    max[fa[i]][0][k] = max[i][j][k];
        for (k = m; k >= 1; k--)
            if (max[fa[i]][1][k] >= 0)
                for (j = 1; j <= m - k; j++) {
                    if (max[i][0][j] >= 0 && max[i][0][j] + max[fa[i]][1][k] > max[fa[i]][1][k + j])
                        max[fa[i]][1][k + j] = max[i][0][j] + max[fa[i]][1][k];
                    if (max[i][1][j] >= 0 && max[i][1][j] + max[fa[i]][1][k] > max[fa[i]][1][k + j])
                        max[fa[i]][1][k + j] = max[i][1][j] + max[fa[i]][1][k];
                }
        degree[fa[i]]--;
        degree[i] = -1;
    }
    if (max[1][0][m] > max[1][1][m]) printf("%d\n", max[1][0][m]);
    else printf("%d\n", max[1][1][m]);
}

int main() {
    init();
    work();
    return 0;
}                                 