// Problem#: 1916
// Submission#: 3591556
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

long long realmod;
long long mod;

typedef long long matrix[2][2];
const int maxb = 31;
matrix bin[1 + maxb];

int prime[100];
int times[100];
int np;

long long mul(long long a, long long b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    long long c = mul(a, b / 2);
    if (b % 2 == 1) return (c + c + a) % mod;
    else return (c + c) % mod;
}

void multiply(matrix a, matrix b, matrix c) {
    matrix tmp = {0};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                tmp[i][j] += mul(a[i][k], b[k][j]);
                tmp[i][j] %= mod;
            }
        }
    memcpy(c, tmp, sizeof(matrix));
}

void prework() {
    matrix A = {
        {3 % mod, 1},
        {mod - 1, 0}
    };
    memcpy(bin[1], A, sizeof(matrix));
    for (int i = 2; i <= maxb; i++) multiply(bin[i - 1], bin[i - 1], bin[i]);
}

long long F(int n) {
    if (n == 1) return 1;
    if (n == 2) return 5;
    int k = n - 3;
    matrix a = {
        {8, 3},
        {0, 0}
    };
    for (int i = 1; k > 0; k /= 2, i++) {
        if (k & 1) multiply(a, bin[i], a);
    }
    long long fn = a[0][0] * 3 - a[0][1] * 2 - 2;
    return ((fn % mod) + mod) % mod;
}

long long dfs(int t, int divisor, int euler) {
    long long ret = 0;
    if (t == np) {
        return mul(euler % mod, F(divisor));
    }
    for (int i = 0; i < times[t]; i++) divisor *= prime[t];
    for (int i = 0; i <= times[t]; i++) {
        ret += dfs(t + 1, divisor, euler);
        ret %= mod;
        divisor /= prime[t];
        if (i == 0) euler *= (prime[t] - 1);
        else euler *= prime[t];
    }
    return ret;
}

int work(int n) {
    mod = realmod * n;
    prework();
    np = 0;
    int t = n;
    for (int i = 2; i * i <= t; i++)
        if (t % i == 0) {
            prime[np] = i;
            times[np] = 0;
            while (t % i == 0) {
                times[np]++;
                t /= i;
            }
            np++;
        }
    if (t > 1) {
        prime[np] = t;
        times[np] = 1;
        np++;
    }
    long long sum = dfs(0, 1, 1);
    return (int)(sum / n);
}

int main() {
    int n;
    while (scanf("%d%lld", &n, &realmod) == 2) printf("%d\n", work(n));
    return 0;
}                                 