// Problem#: 2681
// Submission#: 3592151
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 109;
const int INF = 1009;

int N;
int dp[MAXN][3];
int g[MAXN][MAXN];
int deg[MAXN];
bool vst[MAXN];

void dfs(int x) {
    int i, v, sum0 = 0, cnt = 0, odd, even;
    vst[x] = true;
    if (deg[x] <= 1 && vst[g[x][0]]) {
        dp[x][0] = 0;
        dp[x][1] = INF;
        dp[x][2] = 1;
        return;
    }
    for (i = 0; i < deg[x]; i++) 
        if (!vst[v = g[x][i]]) {
            dfs(v);
            sum0 += dp[v][0];
            if (++cnt == 1) {
                odd = dp[v][2];
                even = dp[v][1];
            } else {
                int oddT = odd, evenT = even;
                odd += dp[v][1];
                even += dp[v][1];
                if (odd > evenT + dp[v][2]) odd = evenT + dp[v][2];
                if (even > oddT + dp[v][2]) even = oddT + dp[v][2];
            }
        }
    dp[x][0] = even;
    dp[x][1] = odd;
    dp[x][2] = sum0 + 1;
}

void input() {
    int i, x, y;
    memset(deg, 0 ,sizeof(deg));
    for (i = 0; i < N - 1; i++) {
        scanf("%d%d", &x, &y);
        --x;
        --y;
        g[x][deg[x]++] = y;
        g[y][deg[y]++] = x;
    }
}

void solve() {
    int ans;
    memset(vst, 0, sizeof(vst));
    dfs(0);
    ans = dp[0][1] < dp[0][2] ? dp[0][1] : dp[0][2];
    if (ans >= INF) printf("-1\n");
    else printf("%d\n", ans);
}

int main() {
    while (scanf("%d", &N) && N) {
        input();
        solve();
    }
    return 0;
}                                 