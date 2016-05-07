// Problem#: 1700
// Submission#: 3589018
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int INF = 10000000;
const int MAXN = 1010;
const int MAXH = 10;

long d[MAXN][MAXN];
long sp[MAXN][MAXH + 1];
long n, m, t;

void init() {
    long i, j, a, b, c;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) d[i][j] = INF;
    for (i = 0; i < n; i++)
        for (j = 0; j <= MAXH; j++) sp[i][j] = INF;
    sp[0][0] = 0;
    while (m--) {
        scanf("%ld%ld%ld", &a, &b, &c);
        if (c < d[a][b]) d[a][b] = c;
        if (c < d[b][a]) d[b][a] = c;
    }
}

void dp() {
    long i, j, k;
    for (k = 1; k <= MAXH; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (d[j][i] < INF && sp[j][k - 1] + d[j][i] < sp[i][k])
                    sp[i][k] = sp[j][k - 1] + d[j][i];
}

int main() {
    while (scanf("%ld%ld%ld", &n, &m, &t), n) {
        init();
        dp();
        long answer = INF;
        for (long i = 0; i <= MAXH; i++)
            if (sp[t][i] < answer) answer = sp[t][i];
        if (answer == INF) printf("no\n");
        else printf("%ld\n", answer);
    }
    return 0;
}                                 