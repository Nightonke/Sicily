// Problem#: 1735
// Submission#: 2701224
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, m, i, j, k, u, an[110], am1[11][11], am2[110], sum, kongzhi, times;
    while (scanf("%d%d", &n, &m) == 2) {
        for (i = 0; i < n; i++) {
            scanf("%d", &an[i]);
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &am1[i][j]);
            }
        }
        for (times = 0; times * m < n; times++);
        if (times * m > n) {
            for (i = n; i < times * m; i++) {
                an[i] = 0;
            }
        }
        kongzhi = 0;
        k = 0;
        while (times--) {
            for (j = 0; j < m; j++) {
                am2[j] = an[k++];
            }
            for (u = 0; u < m; u++) {
                sum = 0;
                for (i = 0; i < m; i++) {
                    sum += am1[u][i] * am2[i];
                }
                if (kongzhi)
                    printf(" ");
                kongzhi = 1;
                printf("%d", sum);
            }
        }
        printf("\n");
    }
    return 0;
}                                 