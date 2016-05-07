// Problem#: 1212
// Submission#: 3585888
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

#define maxn 200
#define modulo 10000

long n, f[maxn + 1], r[maxn + 1], C[maxn + 1][maxn + 1];

void process() {
    long i, j, k;
    C[0][0] = 1;
    for (i = 1; i <= maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (j = 1; j <= i - 1; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % modulo;
        }
    }
    f[0] = f[1] = f[2] = 1;
    r[0] = r[1] = r[2] = 1;
    f[3] = 3;
    r[3] = 3;
    for (n = 4; n <= maxn; n++) {
        r[n] = (r[n - 1] * (n - 1)) % modulo;
        for (i = 1; i <= n - 2; i++) {
            r[n] += ((C[n - 2][i - 1] * ((r[i] * i) % modulo)) % modulo) * ((r[n - 1 - i] * (n - 1 - i)) % modulo);
            r[n] %= modulo;
        }
        f[n] = r[n];
        for (i = 1; i <= n - 3; i++) {
            for (j = 1; j <= n - 1 - i - 1; j++) {
                f[n] += (((C[n - 2][i - 1] * C[n - 1 - i - 1][j - 1])) % modulo) * ((((((r[i] * i) % modulo) * ((r[j] * j) % modulo)) % modulo) * ((r[n - 1 - i - j] * (n - 1 - i - j)) % modulo)) % modulo);
                f[n] %= modulo;
            }
        }
    }
}

int main() {
    process();
    scanf("%ld", &n);
    printf("%ld\n", f[n]);
    return 0;
}                                 