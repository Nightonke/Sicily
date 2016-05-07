// Problem#: 1776
// Submission#: 2510931
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, n1, k, kongzhi, i;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (k = 1; k < n; k++) {
            n1 = n;
            if (n1 % k == 0)
                n1 = n1 / k;
            kongzhi = 1;
            for (i = 2; i * i <= n1; i++) {
                if (n1 % (i * i) == 0) {
                    kongzhi = 0;
                    break;
                }
            }
            if (kongzhi == 1) {
                printf("%d\n", k);
                break;
            }
        }
    }
    return 0;
}                                 