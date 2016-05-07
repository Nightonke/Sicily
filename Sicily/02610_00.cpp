// Problem#: 2610
// Submission#: 3593228
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>

const int MAXN = 101;
const double EPS = 1e-9;

int n, jump[MAXN];
double a[MAXN][MAXN], b[MAXN], x[MAXN];

int GaussEimination() {
    int i, j, k, p, q[MAXN];
    double max, l;
    memset(q, 0, sizeof(q));
    for (k = 1; k <= n; k++) {
        p = 0;
        max = 0;
        for (i = 1; i <= n; i++)
            if (!q[i] && max + EPS < fabs(a[i][k])) max = fabs(a[p = i][k]);
        if (!p) return 0;
        else q[p] = 1;
        for (i = 1; i <= n; i++)
            if (i != p) {
                l = a[i][k] / a[p][k];
                for (j = 1; j <= n; j++) a[i][j] -= l * a[p][j];
                b[i] -= l * b[p];
            }
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (fabs(a[i][j]) > EPS) x[j] = b[i] / a[i][j];
    return 1;
}

void modeling() {
    int i, j;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(x, 0, sizeof(x));
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j <= 6; j++) {
            int k = (i + j) % n;
            k = ((k + jump[k]) % n + n) % n;
            a[i + 1][k + 1] += -1.0 / 6;
        }
        a[i + 1][i + 1] += 1.0;
        b[i + 1] = 1.0;
    }
    a[n][n] = 1.0;
}

int main() {
    int tn, i;
    scanf("%d", &tn);
    while (tn--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d", jump + i);
        modeling();
        if (!GaussEimination()) printf("-1\n");
        else printf("%.3lf\n", x[1]);
    }
    return 0;
}                                 