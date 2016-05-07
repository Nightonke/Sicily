// Problem#: 2404
// Submission#: 3590815
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

unsigned short r[30005], c[30005], d[60005], b[60005];

int main() {
    int n, m, k, x, y, s, t, tx, ty;
    while (scanf("%d", &n) && n) {
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d%d%d%d", &k, &x, &y, &s, &t);
            for (int i = 0; i < k; i++) {
                tx = x + i * s;
                ty = y + i * t;
                r[tx]++;
                c[ty]++;
                d[tx + ty]++;
                b[tx - ty + n]++;
            }
        }
        int size = n, ans = 0;
        for (int i = 1; i <= size; i++) {
            if (r[i] > 1) ans += r[i] - 1;
            if (c[i] > 1) ans += c[i] - 1;
            r[i] = c[i] = 0;
        }
        size = 2 * n;
        for (int i = 1; i < size; i++) {
            if (b[i] > 1) ans += b[i] - 1;
            if (d[i] > 1) ans += d[i] - 1;
            d[i] = b[i] = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}                                 