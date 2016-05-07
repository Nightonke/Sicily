// Problem#: 1157
// Submission#: 2387909
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    long long int a[5], n, i, max;
    while (1) {
        scanf("%lld", &n);
        if (n == 0)
            break;
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        max = a[0];
        for (i = 0; i < n - 1; i++) {
            if (a[i] < a[i+1]) {
                max = a[i+1];
            }
        }
        printf("%lld\n", max);
    }
    return 0;
}                                 