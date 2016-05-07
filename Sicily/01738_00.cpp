// Problem#: 1738
// Submission#: 2508194
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, i, id[10001], score[10001], no_use, max, jilu, j, zj;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &id[i], &score[i], &no_use);
        }
        for (i = 0; i < n - 1; i++) {
            max = score[i];
            jilu = i;
            for (j = i + 1; j < n; j++) {
                if (score[j] > max) {
                    max = score[j];
                    jilu = j;
                }
            }
            zj = score[i];
            score[i] = score[jilu];
            score[jilu] = zj;
            zj = id[i];
            id[i] = id[jilu];
            id[jilu] = zj;
        }
        printf("%d", id[0]);
        for (i = 1; i < n; i++)
            printf(" %d", id[i]);
        printf("\n");
    }
    return 0;
}                                 