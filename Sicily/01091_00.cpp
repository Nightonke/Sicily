// Problem#: 1091
// Submission#: 2693564
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int t, i, n, a[50010], c[50010], d[50010], sum;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        c[0] = d[n + 1] = 0;
        for (i = 1; i <= n; i++) {
            c[i] = max(c[i - 1] + a[i], a[i]);
        }
        for (i = 2; i <= n; i++) {
            c[i] = max(c[i - 1], c[i]);
        }
        for (i = n; i > 0; i--) {
            d[i] = max(d[i + 1] + a[i], a[i]);
        }
        for (i = n - 1; i >= 0; i--) {
            d[i] = max(d[i + 1], d[i]);
        }
        sum = c[1] + d[2];
        for (i = 1; i <= n - 1; i++) {
            if (sum < c[i] + d[i + 1])
                sum = c[i] + d[i + 1];
        }
        printf("%d\n", sum);
    }
    return 0;
}                                 