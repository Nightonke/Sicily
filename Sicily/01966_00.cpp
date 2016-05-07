// Problem#: 1966
// Submission#: 2392805
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, i, a[50], cishu, zj, j, b[50];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        cishu = n - 2;
        for (i = 0; i <= n - 2; i++) {
            b[i] = a[0];
            zj = a[1];
            for (j = 0; j <= cishu - 1; j++) {
                a[j] = a[j + 2];
            }
            a[cishu] = zj;
            cishu--;
        }
        for (i = 0; i < n - 1; i++) {
            printf("%d ",b[i]);
        }
        printf("%d \n", a[0]);
    }
    return 0;
}                                 