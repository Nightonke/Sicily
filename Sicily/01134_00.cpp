// Problem#: 1134
// Submission#: 2375337
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    long int n, s, i, a[20000], b[20000], j, k, zj, counter = 0;
    while (1) {
        scanf("%ld%ld", &n, &s);
        if (n == 0)
            break;
        for (i = 0; i < n; i++) {
            scanf("%ld%ld", &a[i], &b[i]);
        }
        for (j = 0; j < n; j++)
            for (k = 0; k < n - j; k++)
                if (b[k] > b[k+1]) {
                    zj = b[k];
                    b[k] = b[k+1];
                    b[k+1] = zj;
                    zj = a[k];
                    a[k] = a[k+1];
                    a[k+1] = zj;
                }
        for (j = 0; j < n; j++) {
            if (s >= b[j]) {
                s = s + a[j];
                counter++;
            }
            if (s < b[j]) {
                printf("NO\n");
                break;
            }
        }
        if (counter == n)
            printf("YES\n");
        counter = 0;
    }
    return 0;
}                                 