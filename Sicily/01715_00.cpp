// Problem#: 1715
// Submission#: 3585085
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int n, m, k;

long long mat[60][60];

long long gcd(long long a, long long b) {
    long long r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long c(int a, int b) {
    long long x = 1, y = 1;
    long long r;
    int i;
    for (i = 0; i < b; i++) {
        x *= (a - i);
        y *= (b - i);
        r = gcd(x, y);
        x /= r;
        y /= r;
    }
    return x / y;
}

void process() {
    int i, j, u;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++) mat[i][j] = 0;
    for (i = 0; i <= n; i++) mat[i][0] = 0;
    mat[0][0] = 1;
    for (i = 1; i <= m; i++)
        for (j = k * i; j <= n; j++) {
            mat[j][i] = 0;
            for (u = k; u <= j - (i - 1) * k; u++) {
                long long temp = c(j, u);
                mat[j][i] = mat[j][i] + temp * mat[j - u][i - 1];
            }
        }
    printf("%lld\n", mat[n][m]);
}

int main() {
    while (scanf("%d%d%d", &n, &m, &k) == 3) {
        if (n == 0) break;
        process();
    }
    return 0;
}                                 