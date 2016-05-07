// Problem#: 1641
// Submission#: 2496348
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, counter, i, flag1, flag2, a[200], j;
    while (scanf("%d", &n) == 1) {
        counter = n;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        flag1 = 0;
        for (i = 1; i < n; i++) {
            if (a[i] < a[0])
                flag1 = 1;
        }
        if (flag1)
            counter--;
        flag1 = 0;
        for (i = n - 2; i >= 0; i--) {
            if (a[i] > a[n - 1])
                flag1 = 1;
        }
        if (flag1)
            counter--;
        flag1 = flag2 = 0;
        for (i = 1; i < n - 1; i++) {
            for (j = 0; j < i; j++) {
                if (a[j] > a[i]) {
                    flag1 = 1;
                    break;
                }
            }
            for (j = i + 1; j < n; j++) {
                if (a[j] < a[i]) {
                    flag2 = 1;
                    break;
                }
            }
            if (flag1 || flag2)
                counter--;
            flag1 = flag2 = 0;
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 