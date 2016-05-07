// Problem#: 1951
// Submission#: 3591894
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const long long INF = (1LL << 62);
const int MAXN = 10;
const int MAXK = 10;
const int MAX_CYCLE = 2521;

long long T;
int n;
int p[MAXN][MAXK];
int K[MAXN];
int cycle;

long long f[MAX_CYCLE][MAXN][MAXN];
long long g[65][MAXN][MAXN];
long long h[65][MAXN][MAXN];
long long arb[65][MAXN][MAXN];
long long best[MAXN];

void input() {
    scanf("%d%lld", &n, &T);
    for (int i = 0; i < n; i++) {
        scanf("%d", K + i);
        for (int j = 0; j < K[i]; j++) {
            scanf("%d", &p[i][j]);
        }
    }
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int get_cycle() {
    int cycle = 1;
    for (int i = 0; i < n; i++) cycle = lcm(cycle, K[i]);
    return cycle;
}

void dp_in_cycle(int cycle) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - j) > 1) f[0][i][j] = -INF;
        }
        f[0][i][i] = p[i][0];
        if (i > 0) f[0][i][i - 1] = p[i - 1][0];
        if (i < n - 1) f[0][i][i + 1] = p[i + 1][0];
    }
    for (int s = 1; s < cycle; s++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[s][i][j] = f[s - 1][i][j];
                if (j > 0) {
                    f[s][i][j] = max(f[s][i][j], f[s - 1][i][j - 1]);
                }
                if (j < n - 1) {
                    f[s][i][j] = max(f[s][i][j], f[s - 1][i][j + 1]);
                }
                if (f[s][i][j] > -INF) {
                    f[s][i][j] += p[j][s % K[j]];
                }
            }
        }
    }
}

void dp_among_cycles(long long cycles) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[0][i][j] = f[cycle - 1][i][j];
        }
    }
    for (int s = 1; (1LL << s) <= cycles; s++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[s][i][j] = -INF;
                for (int k = 0; k < n; k++) {
                    if (g[s - 1][i][k] > -INF && g[s - 1][k][j] > -INF) {
                        long long t = g[s - 1][i][k] + g[s - 1][k][j];
                        g[s][i][j] = max(g[s][i][j], t);
                    }
                }
            }
        }
    }
    int bits = 0;
    long long tmp = cycles;
    while (tmp > 0) {
        bits++;
        tmp >>= 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            h[bits - 1][i][j] = g[bits - 1][i][j];
        }
    }
    for (int bit = bits - 2; bit >= 0; bit--) {
        if (((1LL << bit) & cycles) > 0LL) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    h[bit][i][j] = -INF;
                    for (int k = 0; k < n; k++) {
                        if (h[bit + 1][i][k] > -INF && g[bit][k][j] > -INF) {
                            long long t = h[bit + 1][i][k] + g[bit][k][j];
                            h[bit][i][j] = max(h[bit][i][j], t);
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    h[bit][i][j] = h[bit + 1][i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arb[0][i][j] = g[0][i][j];
        }
    }
    for (int bit = 1; bit < bits - 1; bit++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arb[bit][i][j] = arb[bit - 1][i][j];
                arb[bit][i][j] = max(arb[bit][i][j], g[bit][i][j]);
                for (int k = 0; k < n; k++) {
                    if (g[bit][i][k] > -INF && arb[bit - 1][k][j] > -INF) {
                        long long t = g[bit][i][k] + arb[bit - 1][k][j];
                        arb[bit][i][j] = max(arb[bit][i][j], t);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) best[i] = -INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            best[j] = max(best[j], h[0][i][j]);
        }
    }
    if (bits > 1) {
        if ((1LL & cycles) > 0LL) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    best[j] = max(best[j], h[1][i][j]);
                }
            }
        }
        for (int bit = 1; bit < bits - 1; bit++) {
            if (((1LL << (bit)) & cycles) > 0LL) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        best[j] = max(best[j], h[bit + 1][i][j]);
                        for (int k = 0; k < n; k++) {
                            if (h[bit + 1][i][k] > -INF && arb[bit - 1][k][j] > -INF) {
                                long long t = h[bit + 1][i][k] + arb[bit - 1][k][j];
                                best[j] = max(best[j], t);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                best[j] = max(best[j], arb[bits - 2][i][j]);
            }
        }
    }
}

long long dp_rest(int rest) {
    long long ans = -INF;
    for (int i = 0; i < n; i++) ans = max(ans, best[i]);
    long long final[MAXN];
    long long old[MAXN];
    for (int i = 0; i < n; i++) old[i] = max(best[i], 0LL);
    for (int s = 0; s < rest; s++) {
        for (int i = 0; i < n; i++) {
            final[i] = old[i];
            if (i > 0) final[i] = max(final[i], old[i - 1]);
            if (i < n - 1) final[i] = max(final[i], old[i + 1]);
            final[i] += p[i][s % K[i]];
            ans = max(ans, final[i]);
        }
        memcpy(old, final, sizeof(old));
    }
    return ans;
}

void solve() {
    cycle = get_cycle();
    dp_in_cycle(cycle);
    long long cycles = T / cycle;
    int rest = T % cycle;
    if (rest < cycle && cycles > 0) {
        cycles--;
        rest += cycle;
    }
    dp_among_cycles(cycles);
    long long ans = dp_rest(rest);
    printf("%lld\n", ans);
}

int main() {
    int casen;
    scanf("%d", &casen);
    while (casen--) {
        input();
        solve();
    }
    return 0;
}                                 