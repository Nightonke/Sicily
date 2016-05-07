// Problem#: 1930
// Submission#: 2460479
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, j, i, min, zj, counter, a[110], jilu;
    scanf("%d", &t);
    while (t--) {
        counter = 0;
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n - 1; i++) {
            min = a[i];
            jilu = i;
            for (j = i; j < n; j++) {
                if (min > a[j]) {
                    min = a[j];
                    counter++;
                    jilu = j;
                }
            }
            zj = a[jilu];
            a[jilu] = a[i];
            a[i] = zj;
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 