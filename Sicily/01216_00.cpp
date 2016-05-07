// Problem#: 1216
// Submission#: 3586249
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

#define maxn 100

long n, W, h;
long w[maxn], v[maxn];

void process() {
    long i, j, k;
    long double l, r, mid, height, sin1, cos1, t;
    l = 1;
    r = 0;
    while (l - r > 1e-15) {
        mid = (l + r) / 2;
        height = 0;
        for (i = 0; i < n; i++) {
            sin1 = mid * v[i] / v[0];
            if (sin1 >= 1) break;
            cos1 = sqrt(1 - sin1 * sin1);
            height += w[i] * (sin1 / cos1);
        }
        if (i < n && sin1 >= 1) {
            l = mid;
            continue;
        }
        if (height > h) l = mid;
        else r = mid;
    }
    t = 0;
    for (i = 0; i < n; i++) {
        sin1 = l * v[i] / v[0];
        cos1 = sqrt(1 - sin1 * sin1);
        t += w[i] / cos1 / v[i];
    }
    printf("%.4llf\n", t);
}

int main() {
    while (scanf("%ld%ld%ld", &n, &W, &h) == 3) {
        for (int i = 0; i < n; i++) scanf("%ld%ld", w + i, v + i);
        process();
    }
    return 0;
}                                 