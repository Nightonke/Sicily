// Problem#: 1199
// Submission#: 2583477
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int Euler(int n) {
    int ret = n, i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret = (ret  / i )* (i - 1);
            while (n % i == 0) {
                n = n / i;
            }
        }
    }
    if (n > 1)
        ret = (ret / n) * (n - 1);
    return ret;
}

int main() {
    int t, n, m, i, sum;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        if (m == 0 || m == 1) {
            printf("%d\n", n);
            continue;
        }
        if (m > n) {
            printf("0\n");
            continue;
        }
        if (m == n) {
            printf("1\n");
            continue;
        }
        sum = 0;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (i >= m) {
                    sum += Euler(n / i);
                }
                if (n / i >= m && i * i != n) {
                    sum += Euler(i);
                }
            }
        }
        printf("%d\n", sum + 1);
    }
    return 0;
}                                 