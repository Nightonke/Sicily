// Problem#: 1195
// Submission#: 3588448
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAX_SCALE = 16;
const int LEN = 32;

unsigned int a[LEN], b[LEN];

void add(unsigned int & x, unsigned int y, int m) {x = (x + y) % m;}

void calc(unsigned int x, int m, unsigned int b[]) {
    int i, j, k;
    for (i = 0; i < LEN; i++) b[i] = 0;
    if (x == 0) return;
    unsigned int c[LEN][MAX_SCALE];
    unsigned int d[LEN], digit[LEN];
    int nDigit = 0;
    unsigned int temp = x;
    while (temp > 0) {
        digit[nDigit++] = temp % m;
        temp /= m;
    }
    d[0] = 1;
    for (i = 1; i < nDigit; i++) d[i] = d[i - 1] * m;
    for (i = nDigit - 1; i >= 0; i--)
        for (j = 0; j < m; j++) c[i][j] = 0;
    for (i = nDigit - 1; i >= 0; i--) {
        for (j = 0; j < digit[i]; j++) add(c[i][j], d[i], m);
        add(c[i][digit[i]], x % d[i] + 1, m);
        for (j = i - 1; j >= 0; j--)
            for (k = 0; k < m; k++) add(c[j][k], digit[i] * d[i - 1], m);
    }
    for (i = nDigit - 1; i >= 0; i--) {
        b[i] = 0;
        for (j = 0; j < m; j++) add(b[i], c[i][j] * j, m);
    }
}

int main() {
    int T, n, m;
    unsigned int x, y, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        while (n--) {
            scanf("%u%u", &x, &y);
            calc(y, m, b);
            for (int i = 0; i < LEN; i++) a[i] = (a[i] + b[i]) % m;
            if (x > 0) {
                calc(x - 1, m, b);
                for (int i = 0; i < LEN; i++) a[i] = (a[i] + m - b[i]) % m;
            }
        }
        ans = 0;
        for (int i = LEN - 1; i >= 0; i--) ans = ans * m + a[i];
        printf("%u\n", ans);
    }
    return 0;
}                                 