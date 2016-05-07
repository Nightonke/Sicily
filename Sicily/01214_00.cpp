// Problem#: 1214
// Submission#: 3586227
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

unsigned long L, sum, e[40], L1;
int b[40], s, i, k;

unsigned long f(unsigned long x) {
    if (x == 1) return 1;
    if (x == 3) return 3;
    if (x % 2 == 0) return f(x / 2);
    if (x % 4 == 1) return 2 * f((x + 1) / 2) - f((x - 1) / 4);
    return 3 * f((x - 1) / 2) - 2 * f((x - 3) / 4);
}

int main() {
    scanf("%lu", &L);
    sum = 0;
    e[0] = 1;
    for (i = 1; i <= 31; i++) e[i] = 2 * e[i - 1];
    s = 0;
    L1 = L;
    while (L1 > 0) {
        s = s + 1;
        b[s] = L1 % 2;
        L1 /= 2;
    }
    for (i = 1; i < s; i++) sum += e[(i + 1) / 2 - 1];
    if (s == 1) sum += 1;
    else if (s % 2 == 0) {
        k = s / 2;
        for (i = e[k - 1]; i <= e[k] - 1; i++) {
            L1 = i * e[k] + f(i);
            if (L1 <= L) sum++;
            else break;
        }
    } else {
        k = (s - 1) / 2;
        for (i = e[k - 1]; i <= e[k] - 1; i++) {
            L1 = i * e[k + 1] + f(i);
            if (L1 <= L) sum++;
            else break;
            L1 = i * e[k + 1] + e[k] + f(i);
            if (L1 <= L) sum++;
            else break;
        }
    }
    printf("%lu\n", sum);
    return 0;
}                                 