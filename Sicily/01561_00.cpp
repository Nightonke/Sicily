// Problem#: 1561
// Submission#: 2380253
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    long long int i = 2, n, j = 3, a[10009], k;
    scanf("%lld", &k);
    n = 5;
    a[0] = 2;
    a[1] = 3;
    while (1) {
        for (j = 3; j * j <= n; j = j + 2) {
            if (n % j == 0)
                break;
        }
        if (n % j != 0) {
            a[i] = n;
            i++;
        }
        n = n + 2;
        if (i >= k)
            break;
    }
    printf("%lld\n", a[k - 1]);
    return 0;
}                                 