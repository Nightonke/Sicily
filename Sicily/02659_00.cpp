// Problem#: 2659
// Submission#: 3593142
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

long long extended_euclid(long long a, long long b, long long & x, long long & y) {
    long long t, d;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    d = extended_euclid(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

long long modular_linear(long long a, long long b, long long n) {
    long long d, x, y;
    while (b < 0) b += n;
    b %= n;
    d = extended_euclid(a, n, x, y);
    if (b % d) return -1;
    else {
        x *= b / d;
        x = (x % (n / d) + n / d) % (n / d);
        if (!x) x += n / d;
        return x;
    }
}

int main() {
    long long a, b, n;
    while (scanf("%lld%lld%lld", &a, &b, &n), a) 
        printf("%lld\n", modular_linear(a, -b, n));
    return 0;
}                                 