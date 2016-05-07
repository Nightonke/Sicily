// Problem#: 1032
// Submission#: 3585062
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

const int num = 50000;

long long a[num], b[num], c[num], avg, sum, p;
int n;

int main() {
    int i, total;
    scanf("%d", &total);
    while (total--) {
        scanf("%d", &n);
        avg = 0;
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            avg += a[i];
        }
        if (avg % n != 0) {
            printf("Impossible\n");
            continue;
        }
        avg /= n;
        sum = 0;
        p = 0;
        for (i = 1; i < n; i++) {
            p += a[i] - avg;
            sum += p;
        }
        if (sum % n != 0) {
            printf("Impossible\n");
            continue;
        }
        c[0] = -sum / n;
        sum = 0;
        b[0] = 0;
        for (i = 1; i < n; i++) {
            c[i] = c[i - 1] + a[i] - avg;
            sum += c[i - 1];
            if (sum > b[0]) b[0] = sum;
        }
        sum = b[0];
        for (i = 1; i < n; i++) {
            b[i] = b[i - 1] - c[i - 1];
            sum += b[i];
        }
        printf("%lld\n", sum * 2);
    }
    return 0;
}                                 