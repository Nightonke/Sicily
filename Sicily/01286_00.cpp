// Problem#: 1286
// Submission#: 2584942
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, d, i, j, kongzhi, a[510][110];
    while (scanf("%d %d", &n, &d), n && d) {
        for (i = 0; i < d; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        for (i = 0; i < n; a[d][i++] = 1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < d; j++) {
                if (a[j][i] == 0) {
                    a[d][i] = 0;
                    break;
                }
            }
        }
        kongzhi = 0;
        for (i = 0; i < n; i++) {
            if (a[d][i] == 1) {
                printf("yes\n");
                kongzhi = 1;
                break;
            }
        }
        if (!kongzhi)
            printf("no\n");
    }
    return 0;
}                                 