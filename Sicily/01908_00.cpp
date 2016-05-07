// Problem#: 1908
// Submission#: 3590850
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 1005;
const int MAXM = 20000;
const int MAXK = 1000;

int head[MAXN];
int to[MAXM];
int ptr[MAXM];
int len[MAXM];
int count[MAXN];
int queue[MAXN];
int f[MAXN][MAXK];
char stat[MAXN];
int n, m, s, k;

int main() {
    int cs;
    scanf("%d", &cs);
    for (int cn = 1; cn <= cs; cn++) {
        scanf("%d%d%d%d", &n, &m, &s, &k);
        scanf("%s", stat + 1);
        memset(head + 1, -1, sizeof(int) * n);
        memset(count + 1, 0, sizeof(int) * n);
        for (int j = 0; j < m; j++) {
            int a, b;
            scanf("%d%d%d", &a, &b, &len[j]);
            to[j] = b;
            ptr[j] = head[a];
            head[a] = j;
            count[b]++;
        }
        for (int i = 1; i <= n; i++) memset(f[i], -1, sizeof(int) * k);
        f[s][0] = 0;
        int t = 0;
        for (int i = 1; i <= n; i++) {
            if (count[i] == 0) queue[t++] = i;
        }
        for (int i = 0; i < t; i++) {
            int u = queue[i];
            for (int j = head[u]; j >= 0; j = ptr[j]) {
                int v = to[j];
                for (int r = 0; r < k; r++) {
                    if (f[u][r] < 0) continue;
                    int d = f[u][r] + len[j];
                    int r1 = d % k;
                    int & f1 = f[v][r1];
                    if (f1 < 0 || d < f1) f1 = d;;
                }
                count[v]--;
                if (count[v] == 0) queue[t++] = v;
            }
        }
        int z = 0;
        for (int i = 1; i <= n; i++) {
            int d = f[i][0];
            if (stat[i] == 'P' && d >= 0 && (z == 0 || d < f[z][0])) z = i;
        }
        if (z == 0) printf("Case %d: -1 -1\n", cn);
        else printf("Case %d: %d %d\n", cn, f[z][0], z);
    }
    return 0;
}                                 