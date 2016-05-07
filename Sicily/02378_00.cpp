// Problem#: 2378
// Submission#: 2704263
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, b, i, all[100], a[100], j, kongzhi;
    while (scanf("%d%d", &n, &b), n && b) {
        for (i = 0; i < b; i++) {
            scanf("%d", &a[i]);
        }
        for (i = 1; i <= n; i++) {
            all[i] = 0;
        }
        for (i = 0; i < b; i++) {
            for (j = i + 1; j < b; j++) {
                all[a[j] > a[i] ? a[j] - a[i] : a[i] - a[j]] = 1;
            }
        }
        for (i = kongzhi = 1; i <= n; i++) {
            if (all[i] == 0) {
                printf("N\n");
                kongzhi = 0;
                break;
            }
        }
        if (kongzhi)
            printf("Y\n");
    }
    return 0;
}                                 