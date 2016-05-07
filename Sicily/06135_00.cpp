// Problem#: 6135
// Submission#: 2704256
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, sum, max, i, j, k, a[110];
    while (scanf("%d%d", &n, &sum) == 2) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0, max = 0; i < n; i++) {
            for (j = i + 1; j < n && a[i] <= sum; j++) {
                for (k = j + 1; k < n && a[i] + a[j] <= sum; k++) {
                    if (a[i] + a[j] + a[k] <= sum && max < a[i] + a[j] + a[k])
                        max = a[i] + a[j] + a[k];
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}                                 