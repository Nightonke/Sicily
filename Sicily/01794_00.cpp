// Problem#: 1794
// Submission#: 3592826
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 111;
int n, g[MAXN][MAXN];
int an, a[MAXN];
int bn, b[MAXN];
int maxd;
char newg[MAXN][MAXN];
char cover[MAXN];
int link[MAXN];

void input() {
    int i, j, k;
    maxd = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            maxd = maxd > g[i][j] ? maxd : g[i][j];
        }
    }
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (g[i][k] + g[k][j] < g[i][j])
                    g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
    scanf("%d", &an);
    for (i = 1; i <= an; i++) scanf("%d", a + i);
    scanf("%d", &bn);
    for (i = 1; i <= bn; i++) scanf("%d", b + i);
}

bool find(int x) {
    int q, i;
    for (i = 1; i <= bn; i++) 
        if (!cover[i] && newg[x][i]) {
            q = link[i];
            link[i] = x;
            cover[i] = 1;
            if (!q || find(q)) return true;
            link[i] = q;
        }
    return false;
}

int max_match() {
    int i, ret = 0;
    memset(link, 0, sizeof(link));
    for (i = 1; i <= an; i++) {
        memset(cover, 0, sizeof(cover));
        find(i);
    }
    for (i = 1; i <= bn; i++) if (link[i]) ret++;
    return ret;
}

int main() {
    int i, j, l, r, mid, ans;
    while (scanf("%d", &n) && n) {
        input();
        l = 1, r = maxd;
        while (l <= r) {
            mid = (l + r) / 2;
            for (i = 1; i <= an; i++)
                for (j = 1; j <= bn; j++)
                    if (g[a[i]][b[j]] <= mid) newg[i][j] = 1;
                    else newg[i][j] = 0;
            if (max_match() == bn) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}                                 