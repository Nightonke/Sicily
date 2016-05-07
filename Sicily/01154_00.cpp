// Problem#: 1154
// Submission#: 2365454
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main () {
    long long  int t, n, a[1000], i = 0, j = 0, zj, k, n1;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        while (n--) {
            scanf("%lld", &a[i]);
            i++;}
        for (j = 0; j < (i - 1); j++)
            for (k =0; k < (i -1 - j); k++)
                if (a[k] > a[k+1]) {
                    zj = a[k];
                    a[k] = a[k+1];
                    a[k+1] = zj;}
        for (j = 0; j < i; j++) {
            printf("%lld\n", a[j]);}
        i = 0;}
    return 0;
}                                 