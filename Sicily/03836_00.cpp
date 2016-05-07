// Problem#: 3836
// Submission#: 2367956
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main () {
    long int n, m, fengzi, fengmu1, fengmu2, c, i;
    fengzi = fengmu1 = fengmu2 = 1;
    while(1) {
        scanf("%ld%ld", &n, &m);
        if (n == 0)
            break;
        for (i = 1; i <= n; i++)
            fengzi = fengzi * i;
        for (i = 1; i <= m; i++)
            fengmu1 = fengmu1 * i;
        for (i = 1; i <= n - m; i++)
            fengmu2 = fengmu2 * i;
        c = fengzi / (fengmu1 * fengmu2);
        fengzi = fengmu1 = fengmu2 = 1;
        printf("%ld\n", c);
    }
    return 0;
}                                 