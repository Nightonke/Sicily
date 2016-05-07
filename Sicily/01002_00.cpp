// Problem#: 1002
// Submission#: 2693169
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int ans[1001], vis[1001], p[10000];
int is_ok, n, m, d;

void make_prime() {
    for (int i = 2; i < 10000; i++) {
        if (p[i]) {
            for (int j = 2; j * i < 10000; j++) {
                p[i * j] = 0;
            }
        }
    }
}

bool check(int pos, int i) {
    int add_times = d - 1;
    for (int j = pos - 1; j >= 0 && add_times > 0; j--, add_times--) {
        i += ans[j];
        if (p[i])
            return false;
    }
    return true;
}

void dfs(int pos) {
    for (int i = n; i <= m; i++) {
        if (vis[i] == 0 && check(pos, i)) {
            vis[i] = 1;
            ans[pos] = i;
            if (pos == m - n) {
                is_ok = 1;
                return;
            }
            dfs(pos + 1);
            if (is_ok)
                return;
            vis[i] = 0;
        }
    }
}

int main() {
    memset(p, 1, sizeof(p));
    make_prime();
    while (scanf("%d %d %d", &n, &m, &d), n && m && d) {
        is_ok = 0;
        memset(vis, 0, sizeof(vis));
        dfs(0);
        if (is_ok) {
            printf("%d", ans[0]);
            for (int i = 1; i <= m - n; i++)
                printf(",%d", ans[i]);
            printf("\n");
        }
        else
            printf("No anti-prime sequence exists.\n");
    }
    return 0;
}                                 